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

/** \file Acceleration1.h
    \brief This file defines the Acceleration1 class, which represents the
           transverse acceleration sensor.
  */

#ifndef ACCELERATION1_H
#define ACCELERATION1_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class Acceleration1 contains the transverse acceleration sensor.
    \brief Transverse acceleration sensor
  */
class Acceleration1 :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  Acceleration1();
  /// Copy constructor
  Acceleration1(const Acceleration1& other);
  /// Assignement operator
  Acceleration1& operator = (const Acceleration1& other);
  /// Destructor
  virtual ~Acceleration1();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual Acceleration1* clone() const;
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
  static const Acceleration1 mProto;
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

#endif // ACCELERATION1_H
