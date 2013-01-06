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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "types/PRIUSMessage.h"

#include "base/Factory.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

PRIUSMessage::PRIUSMessage(int typeID) :
    mTypeID(typeID) {
  Factory<int, PRIUSMessage>::getInstance().registerType(this, mTypeID);
}

PRIUSMessage::PRIUSMessage(const PRIUSMessage& other) :
    mTypeID(other.mTypeID) {
}

PRIUSMessage& PRIUSMessage::operator = (const PRIUSMessage& other) {
  if (this != &other) {
    mTypeID = other.mTypeID;
  }
  return *this;
}

PRIUSMessage::~PRIUSMessage() {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

int PRIUSMessage::getTypeID() const {
  return mTypeID;
}
