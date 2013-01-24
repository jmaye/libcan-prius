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

/** \file FrontWheelsSpeed.h
    \brief This file defines the FrontWheelsSpeed class, which represents the
           velocity of the front wheels.
  */

#ifndef FRONTWHEELSSPEED_H
#define FRONTWHEELSSPEED_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class FrontWheelsSpeed contains the velocity of the front wheels.
    \brief Velocity of the front wheels.
  */
class FrontWheelsSpeed :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  FrontWheelsSpeed();
  /// Copy constructor
  FrontWheelsSpeed(const FrontWheelsSpeed& other);
  /// Assignement operator
  FrontWheelsSpeed& operator = (const FrontWheelsSpeed& other);
  /// Destructor
  virtual ~FrontWheelsSpeed();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual FrontWheelsSpeed* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Right wheel speed [m/s]
  double mRight;
  /// Left wheel speed [m/s]
  double mLeft;
  /// Prototype for this message
  static const FrontWheelsSpeed mProto;
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

#endif // FRONTWHEELSSPEED_H
