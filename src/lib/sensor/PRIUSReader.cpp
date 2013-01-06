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

#include "sensor/PRIUSReader.h"

#include "base/Factory.h"
#include "types/PRIUSMessage.h"
#include "com/CANConnection.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

PRIUSReader::PRIUSReader(CANConnection& device) :
    mDevice(device) {
}

PRIUSReader::~PRIUSReader() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

std::shared_ptr<PRIUSMessage> PRIUSReader::readMessage() {
  CANConnection::Message canMessage;
  mDevice.receiveMessage(canMessage);
  std::shared_ptr<PRIUSMessage>
    priusMessage(Factory<int, PRIUSMessage>::getInstance().create(
    canMessage.id));
  priusMessage->fillData(canMessage.content);
  return priusMessage;
}
