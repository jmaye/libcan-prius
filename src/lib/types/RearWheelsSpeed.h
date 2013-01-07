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

/** \file RearWheelsSpeed.h
    \brief This file defines the RearWheelsSpeed class, which represents the
           velocity of the rear wheels.
  */

#ifndef REARWHEELSSPEED_H
#define REARWHEELSSPEED_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class RearWheelsSpeed contains the velocity of the rear wheels.
    \brief Velocity of the rear wheels.
  */
class RearWheelsSpeed :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  RearWheelsSpeed();
  /// Copy constructor
  RearWheelsSpeed(const RearWheelsSpeed& other);
  /// Assignement operator
  RearWheelsSpeed& operator = (const RearWheelsSpeed& other);
  /// Destructor
  virtual ~RearWheelsSpeed();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual RearWheelsSpeed* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Right wheel speed
  uint16_t mRight;
  /// Left wheel speed
  uint16_t mLeft;
  /// Prototype for this message
  static const RearWheelsSpeed mProto;
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

#endif // REARWHEELSSPEED_H
