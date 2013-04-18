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

#include "types/Speed2.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Speed2 Speed2::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Speed2::Speed2() :
    PRIUSMessage(0x3ca) {
}

Speed2::Speed2(const Speed2 &other) :
    PRIUSMessage(other),
    mValue(other.mValue) {
}

Speed2& Speed2::operator = (const Speed2& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mValue = other.mValue;
  }
  return *this;
}

Speed2::~Speed2() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Speed2::read(BinaryReader& stream) {
  stream >> mValue;
}

void Speed2::write(BinaryWriter& stream) const {
  stream << mTypeID << mValue;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Speed2::fillData(const unsigned char* data) {
  mValue = data[2];
}

Speed2* Speed2::clone() const {
  return new Speed2(*this);
}
