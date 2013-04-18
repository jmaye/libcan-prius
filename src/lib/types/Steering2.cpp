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

#include "types/Steering2.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Steering2 Steering2::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Steering2::Steering2() :
    PRIUSMessage(0x25) {
}

Steering2::Steering2(const Steering2 &other) :
    PRIUSMessage(other),
    mValue(other.mValue) {
}

Steering2& Steering2::operator = (const Steering2& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mValue = other.mValue;
  }
  return *this;
}

Steering2::~Steering2() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Steering2::read(BinaryReader& stream) {
  stream >> mValue;
}

void Steering2::write(BinaryWriter& stream) const {
  stream << mTypeID << mValue;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Steering2::fillData(const unsigned char* data) {
  uint16_t msg = (data[0] << 8) | (data[1] << 0); // type is signed 12-bits
  if (msg <= 2047) // 2^11-1
    mValue = msg;
  else
    mValue = -(4096 - msg);
}

Steering2* Steering2::clone() const {
  return new Steering2(*this);
}
