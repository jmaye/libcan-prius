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

#include "types/Speed3.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Speed3 Speed3::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Speed3::Speed3() :
    PRIUSMessage(0x244) {
}

Speed3::Speed3(const Speed3 &other) :
    PRIUSMessage(other),
    mThrottle(other.mThrottle),
    mSpeed(other.mSpeed) {
}

Speed3& Speed3::operator = (const Speed3& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mThrottle = other.mThrottle;
    mSpeed = other.mSpeed;
  }
  return *this;
}

Speed3::~Speed3() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Speed3::read(BinaryReader& stream) {
  stream >> mThrottle >> mSpeed;
}

void Speed3::write(BinaryWriter& stream) const {
  stream << mTypeID << mThrottle << mSpeed;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Speed3::fillData(const unsigned char* data) {
  mThrottle = data[6];
  uint16_t msg = (data[4] << 8) | (data[5] << 0); // type is signed 16-bits
  if (msg <= 65535) // 2^16-1
    mSpeed = msg;
  else
    mSpeed = -(65536 - msg);
}

Speed3* Speed3::clone() const {
  return new Speed3(*this);
}
