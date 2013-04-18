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

#include "types/Acceleration1.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Acceleration1 Acceleration1::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Acceleration1::Acceleration1() :
    PRIUSMessage(0x22) {
}

Acceleration1::Acceleration1(const Acceleration1 &other) :
    PRIUSMessage(other),
    mValue1(other.mValue1),
    mValue2(other.mValue2) {
}

Acceleration1& Acceleration1::operator = (const Acceleration1& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mValue1 = other.mValue1;
    mValue2 = other.mValue2;
  }
  return *this;
}

Acceleration1::~Acceleration1() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Acceleration1::read(BinaryReader& stream) {
  stream >> mValue1 >> mValue2;
}

void Acceleration1::write(BinaryWriter& stream) const {
  stream << mTypeID << mValue1 << mValue2;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Acceleration1::fillData(const unsigned char* data) {
  mValue1 = (data[0] << 8) | (data[1] << 0);
  mValue2 = (data[2] << 8) | (data[3] << 0);
}

Acceleration1* Acceleration1::clone() const {
  return new Acceleration1(*this);
}
