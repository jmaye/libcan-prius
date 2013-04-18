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

#include "visualization/CANScanCom.h"

#include "exceptions/IOException.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

CANScanCom::CANScanCom(CANConnection& device, double pollingTime) :
    mDevice(device),
    mPollingTime(pollingTime) {
  connect(&mTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
  mTimer.setInterval(pollingTime);
  mTimer.start();
}

CANScanCom::~CANScanCom() {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

double CANScanCom::getPollingTime() const {
  return mPollingTime;
}

void CANScanCom::setPollingTime(double pollingTime) {
  mPollingTime = pollingTime;
  mTimer.setInterval(pollingTime);
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void CANScanCom::timerTimeout() {
  try {
    if (!mDevice.isOpen())
      mDevice.open();
    std::shared_ptr<CANConnection::Message> canMessage(
      new CANConnection::Message());
    mDevice.receiveMessage(*canMessage);
    emit readMessage(canMessage);
  }
  catch (IOException& e) {
    emit comException(e.what());
  }
}
