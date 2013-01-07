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

/** \file Speed.h
    \brief This file defines the Speed class, which represents the
           velocity of the vehicle.
  */

#ifndef SPEED_H
#define SPEED_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class Speed contains the velocity of the vehicle.
    \brief Velocity of the vehicle
  */
class Speed :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  Speed();
  /// Copy constructor
  Speed(const Speed& other);
  /// Assignement operator
  Speed& operator = (const Speed& other);
  /// Destructor
  virtual ~Speed();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual Speed* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Velocity
  uint8_t mSpeed;
  /// Prototype for this message
  static const Speed mProto;
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

#endif // SPEED_H
