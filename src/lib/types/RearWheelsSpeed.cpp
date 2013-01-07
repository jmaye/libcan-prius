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

#include "types/RearWheelsSpeed.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const RearWheelsSpeed RearWheelsSpeed::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

RearWheelsSpeed::RearWheelsSpeed() :
    PRIUSMessage(0xb3) {
}

RearWheelsSpeed::RearWheelsSpeed(const RearWheelsSpeed &other) :
    PRIUSMessage(other),
    mRight(other.mRight),
    mLeft(other.mLeft) {
}

RearWheelsSpeed& RearWheelsSpeed::operator = (const RearWheelsSpeed& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mRight = other.mRight;
    mLeft = other.mLeft;
  }
  return *this;
}

RearWheelsSpeed::~RearWheelsSpeed() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void RearWheelsSpeed::read(BinaryReader& stream) {
  stream >> mRight >> mLeft;
}

void RearWheelsSpeed::write(BinaryWriter& stream) const {
  stream << mTypeID << mRight << mLeft;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void RearWheelsSpeed::fillData(const unsigned char* data) {
  mRight = (data[0] << 8) | (data[1] << 0);
  mLeft = (data[2] << 8) | (data[3] << 0);
}

RearWheelsSpeed* RearWheelsSpeed::clone() const {
  return new RearWheelsSpeed(*this);
}
