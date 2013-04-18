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

#include "types/Brakes.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Brakes Brakes::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Brakes::Brakes() :
    PRIUSMessage(0x30) {
}

Brakes::Brakes(const Brakes &other) :
    PRIUSMessage(other),
    mValue(other.mValue) {
}

Brakes& Brakes::operator = (const Brakes& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mValue = other.mValue;
  }
  return *this;
}

Brakes::~Brakes() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Brakes::read(BinaryReader& stream) {
  stream >> mValue;
}

void Brakes::write(BinaryWriter& stream) const {
  stream << mTypeID << mValue;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Brakes::fillData(const unsigned char* data) {
  mValue = data[4];
}

Brakes* Brakes::clone() const {
  return new Brakes(*this);
}
