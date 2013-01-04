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

#include "com/Joystick.h"

#include <linux/joystick.h>
#include <fcntl.h>
#include <string.h>
//#include <errno.h>

#include "exceptions/SystemException.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Joystick::Joystick(const std::string& devicePathStr) :
    mDevicePathStr(devicePathStr),
    mHandle(0) {
}

Joystick::~Joystick() {
  close();
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Joystick::open() {
  if (isOpen())
    return;
  mHandle = ::open(mDevicePathStr.c_str(), O_RDONLY);
  if (mHandle == -1) {
    mHandle = 0;
    throw SystemException(errno, "Joystick::open()::open()");
  }
  if (ioctl(mHandle, JSIOCGAXES, &mState.mNumAxes) == -1) {
    close();
    throw SystemException(errno, "Joystick::open()::ioctl()");
  }
  if (ioctl(mHandle, JSIOCGBUTTONS, &mState.mNumButtons) == -1) {
    close();
    throw SystemException(errno, "Joystick::open()::ioctl()");
  }
  if (fcntl(mHandle, F_SETFL, O_NONBLOCK) == -1) {
    close();
    throw SystemException(errno, "Joystick::open()::open()");
  }
  if (mState.mAxes)
    delete []mState.mAxes;
  mState.mAxes = new int16_t[mState.mNumAxes];
  memset(mState.mAxes, 0, sizeof(mState.mAxes));
  if (mState.mButtons)
    delete []mState.mButtons;
  mState.mButtons = new int16_t[mState.mNumButtons];
  memset(mState.mButtons, 0, sizeof(mState.mButtons));
}

void Joystick::close() {
  if (mHandle != 0) {
    if (::close(mHandle))
      throw SystemException(errno, "Joystick::close()::close()");
    mHandle = 0;
    if (mState.mAxes) {
      delete []mState.mAxes;
      mState.mAxes = 0;
    }
    if (mState.mButtons) {
      delete []mState.mButtons;
      mState.mButtons = 0;
    }
    mState.mNumAxes = 0;
    mState.mNumButtons = 0;
  }
}

bool Joystick::isOpen() const {
  return (mHandle != 0);
}

uint32_t Joystick::getDriverVersion() {
  if (!isOpen())
    open();
  uint32_t version;
  if (ioctl(mHandle, JSIOCGVERSION, &version) == -1) {
    close();
    throw SystemException(errno, "Joystick::getDriverVersion()::ioctl()");
  }
  return version;
}

std::string Joystick::getIdentifierString() {
  if (!isOpen())
    open();
  char buffer[80];
  if (ioctl(mHandle, JSIOCGNAME(80), buffer) == -1) {
    close();
    throw SystemException(errno, "Joystick::getIdentifierString()::ioctl()");
  }
  return std::string(buffer);
}

const Joystick::State& Joystick::getState() {
  if (!isOpen())
    open();
  struct js_event js;
  while (read(mHandle, &js, sizeof(struct js_event)) > 0) {
    switch (js.type & ~JS_EVENT_INIT) {
      case JS_EVENT_AXIS:
        mState.mAxes[js.number] = js.value;
        break;
      case JS_EVENT_BUTTON:
        mState.mButtons[js.number] = js.value;
        break;
    }
  }
  if (errno != EAGAIN) {
    close();
    throw SystemException(errno, "Joystick::readState()::read()");
  }
  return mState;
}
