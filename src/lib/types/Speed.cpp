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

#include "types/Speed.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Speed Speed::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Speed::Speed() :
    PRIUSMessage(0x3ca) {
}

Speed::Speed(const Speed &other) :
    PRIUSMessage(other),
    mSpeed(other.mSpeed) {
}

Speed& Speed::operator = (const Speed& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mSpeed = other.mSpeed;
  }
  return *this;
}

Speed::~Speed() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Speed::read(BinaryReader& stream) {
  stream >> mSpeed;
}

void Speed::write(BinaryWriter& stream) const {
  stream << mTypeID << mSpeed;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Speed::fillData(const unsigned char* data) {
  mSpeed = data[2];
}

Speed* Speed::clone() const {
  return new Speed(*this);
}
