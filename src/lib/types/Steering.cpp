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

#include "types/Steering.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Steering Steering::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Steering::Steering() :
    PRIUSMessage(0x25) {
}

Steering::Steering(const Steering &other) :
    PRIUSMessage(other),
    mAngle(other.mAngle) {
}

Steering& Steering::operator = (const Steering& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mAngle = other.mAngle;
  }
  return *this;
}

Steering::~Steering() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Steering::read(BinaryReader& stream) {
  stream >> mAngle;
}

void Steering::write(BinaryWriter& stream) const {
  stream << mTypeID << mAngle;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Steering::fillData(const unsigned char* data) {
  uint16_t msg = (data[0] << 8) | (data[1] << 0);
  if (msg <= 0x1B7)
    mAngle = msg;
  else
    mAngle = -(4096 - msg);
}

Steering* Steering::clone() const {
  return new Steering(*this);
}
