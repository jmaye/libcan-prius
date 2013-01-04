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

/** \file CANConnection.h
    \brief This file defines the CANConnection class, which is an interface
           for a CAN connection
  */

#ifndef CANCONNECTION_H
#define CANCONNECTION_H

extern "C" {
  #include <libcan/can.h>
}

#include <string>

#include "base/Serializable.h"

/** The class CANConnection is an interface for CAN communication.
    \brief CAN communication interface
  */
class CANConnection :
  public virtual Serializable {
  /** \name Private constructors
    @{
    */
  /// Copy constructor
  CANConnection(const CANConnection& other);
  /// Assignment operator
  CANConnection& operator = (const CANConnection& other);
  /** @}
    */

public:
  /** \name Types definitions
    @{
    */
  /// CAN message
  struct Message {
    /// ID of the message
    int id;
    /// Content of the message
    unsigned char content[8];
    /// Length of the message
    ssize_t length;
  };
  /** @}
    */

  /** \name Constructors/destructor
    @{
    */
  /// Constructs the CAN connection from parameters
  CANConnection(const std::string& devicePathStr = "/dev/cpc_usb0",
    int bitrate = 500, int quantaPerBit = 16, double samplingPoint = 0.875,
    double timeout = 0.01);
   /// Destructor
  virtual ~CANConnection();
  /** @}
    */

  /** \name Accessors
    @{
    */
  /// Returns the path to the device
  const std::string& getDevicePathStr() const;
  /// Returns the bitrate
  int getBitrate() const;
  /// Returns the quanta per bit
  int getQuantaPerBit() const;
  /// Returns the sampling point
  double getSamplingPoint() const;
  /// Returns the timeout
  double getTimeout() const;
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Opens the CAN port
  void open();
  /// Closes the CAN port
  void close();
  /// Check if the port is open
  bool isOpen() const;
  /// Sends a message to the CAN device
  void sendMessage(const Message& message);
  /// Receives a message from the CAN device
  void receiveMessage(Message& message);
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from standard input
  virtual void read(std::istream& stream);
  /// Writes to standard output
  virtual void write(std::ostream& stream) const;
  /// Reads from a file
  virtual void read(std::ifstream& stream);
  /// Writes to a file
  virtual void write(std::ofstream& stream) const;
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Path to the CAN device
  std::string mDevicePathStr;
  /// Bitrate for the CAN device
  int mBitrate;
  /// Quanta per bit for the CAN device
  int mQuantaPerBit;
  /// Sampling point for the CAN device
  double mSamplingPoint;
  /// Timeout for the CAN device
  double mTimeout;
  /// Handle to the CAN device
  can_device_p mHandle;
  /** @}
    */

};

#endif // CANCONNECTION_H
