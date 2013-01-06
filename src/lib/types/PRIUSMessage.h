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

/** \file PRIUSMessage.h
    \brief This file defines the PRIUSMessage class, which is the base class for
           all PRIUS messages.
  */

#ifndef PRIUSMESSAGE_H
#define PRIUSMESSAGE_H

#include "exceptions/TypeCastException.h"

/** The class PRIUSMessage is the base class for all PRIUS messages.
    \brief Base class for all PRIUS messages
  */
class PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Constructs a new message with given type ID
  PRIUSMessage(int typeID);
  /// Copy constructor
  PRIUSMessage(const PRIUSMessage& other);
  /// Assignement operator
  PRIUSMessage& operator = (const PRIUSMessage& other);
  /// Destructor
  virtual ~PRIUSMessage();
  /** @}
    */

  /** \name Accessors
    @{
    */
  /// Returns the type ID of the message
  int getTypeID() const;
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual PRIUSMessage* clone() const = 0;
  /// Cast the message into something else
  template<class O> const O& typeCast() const {
    if (this->mTypeID == O::mProto.mTypeID)
      return (const O&)*this;
    else
      throw TypeCastException("PRIUSMessage::typeCast(): cast failed");
  }
  /// Cast the message into something else
  template<class O> O& typeCast() {
    if (this->mTypeID == O::mProto.mTypeID)
      return (O&)*this;
    else
      throw TypeCastException("PRIUSMessage::typeCast(): cast failed");
  }
  /// Check if a message is an instance of something
  template<class O> bool instanceOf() const {
    if (this->mTypeID == O::mProto.mTypeID)
      return true;
    else
      return false;
  }
  /// Check if a message is an instance of something
  template<class O> bool instanceOf() {
    if (this->mTypeID == O::mProto.mTypeID)
      return true;
    else
      return false;
  }
  /// Fill data into the message
  virtual void fillData(const unsigned char* data) = 0;
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Type ID
  int mTypeID;
  /** @}
    */

};

#endif // PRIUSMESSAGE_H
