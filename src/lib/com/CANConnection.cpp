/******************************************************************************
 * Copyright (C) 2013 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "com/CANConnection.h"

#include <string.h>

extern "C" {
  #include <libcan/can_cpc.h>
}

#include "exceptions/IOException.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

CANConnection::CANConnection(const std::string& devicePathStr, int bitrate,
    int quantaPerBit, double samplingPoint, double timeout) :
    mDevicePathStr(devicePathStr),
    mBitrate(bitrate),
    mQuantaPerBit(quantaPerBit),
    mSamplingPoint(samplingPoint),
    mTimeout(timeout) {
}

CANConnection::~CANConnection() {
  close();
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void CANConnection::read(std::istream& stream) {
}

void CANConnection::write(std::ostream& stream) const {
  stream << "device path: " << mDevicePathStr << std::endl
    << "bitrate: " << mBitrate << std::endl
    << "quanta per bit: " << mQuantaPerBit << std::endl
    << "sampling point: " << mSamplingPoint << std::endl
    << "timeout: " << mTimeout;
}

void CANConnection::read(std::ifstream& stream) {
}

void CANConnection::write(std::ofstream& stream) const {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

const std::string& CANConnection::getDevicePathStr() const {
  return mDevicePathStr;
}

int CANConnection::getBitrate() const {
  return mBitrate;
}

int CANConnection::getQuantaPerBit() const {
  return mQuantaPerBit;
}

double CANConnection::getSamplingPoint() const {
  return mSamplingPoint;
}

double CANConnection::getTimeout() const {
  return mTimeout;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void CANConnection::open() {
  if (isOpen())
    return;
  config_t config;
  config_init(&config);
  config_set_string(&config, CAN_CPC_PARAMETER_DEVICE, mDevicePathStr.c_str());
  config_set_int(&config, CAN_CPC_PARAMETER_BITRATE, mBitrate);
  config_set_int(&config, CAN_CPC_PARAMETER_QUANTA_PER_BIT, mQuantaPerBit);
  config_set_float(&config, CAN_CPC_PARAMETER_SAMPLING_POINT, mSamplingPoint);
  config_set_float(&config, CAN_CPC_PARAMETER_TIMEOUT, mTimeout);
  mHandle = (can_device_p)malloc(sizeof(can_device_t));
  can_init(mHandle, &config);
  if (can_open(mHandle)) {
    free(mHandle);
    mHandle = 0;
    throw IOException("CANConnection::open: CAN port opening failed");
  }
}

void CANConnection::close() {
  if (mHandle != 0) {
    can_destroy(mHandle);
    int ret = can_close(mHandle);
    free(mHandle);
    mHandle = 0;
    if (ret)
      throw IOException("CANConnection::close: CAN port closing failed");
  }
}

bool CANConnection::isOpen() const {
  return (mHandle != 0);
}

void CANConnection::sendMessage(const Message& message) {
  if (!isOpen())
    open();
  can_message_t msg;
  msg.id = message.id;
  memcpy(msg.content, message.content, sizeof(message.content));
  msg.length = message.length;
  if (can_send_message(mHandle, &msg))
    throw IOException("CANConnection::sendMessage: failed");
}

void CANConnection::receiveMessage(Message& message) {
  if (!isOpen())
    open();
  can_message_t msg;
  memset(msg.content, 0, sizeof(msg.content));
  if (can_receive_message(mHandle, &msg))
    throw IOException("CANConnection::receiveMessage: failed");
  message.id = msg.id;
  memcpy(message.content, msg.content, sizeof(msg.content));
  message.length = msg.length;
}
