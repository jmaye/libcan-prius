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

#include "visualization/LogReader.h"

#include "types/PRIUSMessage.h"
#include "base/BinaryStreamReader.h"
#include "exceptions/IOException.h"
#include "base/Factory.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

LogReader::LogReader(BinaryStreamReader<std::ifstream>& device,
    double pollingTime) :
    mDevice(device),
    mPollingTime(pollingTime),
    mDone(false) {
  mDevice.getStream().seekg (0, std::ios::end);
  mFileLength = mDevice.getStream().tellg();
  mDevice.getStream().seekg (0, std::ios::beg);
  connect(&mTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
  mTimer.setInterval(pollingTime);
  mTimer.start();
}

LogReader::~LogReader() {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

double LogReader::getPollingTime() const {
  return mPollingTime;
}

void LogReader::setPollingTime(double pollingTime) {
  mPollingTime = pollingTime;
  mTimer.setInterval(pollingTime);
}

int LogReader::getFileLength() const {
  return mFileLength;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void LogReader::timerTimeout() {
  if (mDevice.getStream().tellg() >= mFileLength) {
    if (!mDone) {
      emit eof();
      mDone = true;
    }
    return;
  }
  if (mDevice.getStream().good()) {
    if (mDevice.getStream().tellg() == 0)
      emit start();
    double timestamp;
    mDevice >> timestamp;
    int typeID;
    mDevice >> typeID;
    std::shared_ptr<PRIUSMessage>
      priusMessage(Factory<int, PRIUSMessage>::getInstance().create(
      typeID));
    mDevice >> *priusMessage;
    emit readMessage(priusMessage);
    emit deviceConnected(true);
  }
  else
    emit deviceConnected(false);
}
