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

/** \file Acceleration2.h
    \brief This file defines the Acceleration2 class, which represents the
           longitudinal acceleration sensor.
  */

#ifndef ACCELERATION2_H
#define ACCELERATION2_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class Acceleration2 contains the longitudinal acceleration sensor.
    \brief Longitudinal acceleration sensor
  */
class Acceleration2 :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  Acceleration2();
  /// Copy constructor
  Acceleration2(const Acceleration2& other);
  /// Assignement operator
  Acceleration2& operator = (const Acceleration2& other);
  /// Destructor
  virtual ~Acceleration2();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual Acceleration2* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Value 1
  uint16_t mValue1;
  /// Value 2
  uint16_t mValue2;
  /// Prototype for this message
  static const Acceleration2 mProto;
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

#endif // ACCELERATION2_H
