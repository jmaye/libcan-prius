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

/** \file Speed1.h
    \brief This file defines the Speed1 class, which represents the
           velocity sensor 1 of the vehicle.
  */

#ifndef SPEED1_H
#define SPEED1_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class Speed1 contains the velocity sensor 1 of the vehicle.
    \brief Velocity sensor 1 of the vehicle
  */
class Speed1 :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  Speed1();
  /// Copy constructor
  Speed1(const Speed1& other);
  /// Assignement operator
  Speed1& operator = (const Speed1& other);
  /// Destructor
  virtual ~Speed1();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual Speed1* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Value
  uint16_t mValue;
  /// Prototype for this message
  static const Speed1 mProto;
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from the network
  virtual void read(BinaryReader& stream);
  /// Writes to the network
  virtual void write(BinaryWriter& stream) const;
  /** @}
    */

};

#endif // SPEED1_H
