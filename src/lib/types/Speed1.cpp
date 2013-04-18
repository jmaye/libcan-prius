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

#include "types/Speed1.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Speed1 Speed1::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Speed1::Speed1() :
    PRIUSMessage(0xb4) {
}

Speed1::Speed1(const Speed1 &other) :
    PRIUSMessage(other),
    mValue(other.mValue) {
}

Speed1& Speed1::operator = (const Speed1& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mValue = other.mValue;
  }
  return *this;
}

Speed1::~Speed1() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Speed1::read(BinaryReader& stream) {
  stream >> mValue;
}

void Speed1::write(BinaryWriter& stream) const {
  stream << mTypeID << mValue;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Speed1::fillData(const unsigned char* data) {
  uint16_t msg = (data[5] << 8) | (data[6] << 0);
  mValue = msg;
}

Speed1* Speed1::clone() const {
  return new Speed1(*this);
}
