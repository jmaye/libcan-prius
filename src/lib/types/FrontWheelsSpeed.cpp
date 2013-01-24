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

#include "types/FrontWheelsSpeed.h"

#include "base/BinaryReader.h"
#include "base/BinaryWriter.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const FrontWheelsSpeed FrontWheelsSpeed::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

FrontWheelsSpeed::FrontWheelsSpeed() :
    PRIUSMessage(0xb1) {
}

FrontWheelsSpeed::FrontWheelsSpeed(const FrontWheelsSpeed &other) :
    PRIUSMessage(other),
    mRight(other.mRight),
    mLeft(other.mLeft) {
}

FrontWheelsSpeed& FrontWheelsSpeed::operator = (const FrontWheelsSpeed& other) {
  if (this != &other) {
    PRIUSMessage::operator=(other);
    mRight = other.mRight;
    mLeft = other.mLeft;
  }
  return *this;
}

FrontWheelsSpeed::~FrontWheelsSpeed() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void FrontWheelsSpeed::read(BinaryReader& stream) {
  stream >> mRight >> mLeft;
}

void FrontWheelsSpeed::write(BinaryWriter& stream) const {
  stream << mTypeID << mRight << mLeft;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void FrontWheelsSpeed::fillData(const unsigned char* data) {
  uint16_t mRightRead = (data[0] << 8) | (data[1] << 0);
  uint16_t mLeftRead = (data[2] << 8) | (data[3] << 0);
  mRight = mRightRead / 100.0 / 3.6;
  mLeft = mLeftRead / 100.0 / 3.6;
}

FrontWheelsSpeed* FrontWheelsSpeed::clone() const {
  return new FrontWheelsSpeed(*this);
}
