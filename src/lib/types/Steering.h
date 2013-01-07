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

/** \file Steering.h
    \brief This file defines the Steering class, which represents the
           steering angle.
  */

#ifndef STEERING_H
#define STEERING_H

#include <stdint.h>

#include "types/PRIUSMessage.h"

/** The class Steering contains the steering angle.
    \brief Steering angle
  */
class Steering :
  public PRIUSMessage {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  Steering();
  /// Copy constructor
  Steering(const Steering& other);
  /// Assignement operator
  Steering& operator = (const Steering& other);
  /// Destructor
  virtual ~Steering();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this message
  virtual Steering* clone() const;
  /// Fill data into the message
  virtual void fillData(const unsigned char* data);
  /** @}
    */

  /** \name Members
    @{
    */
  /// Steering angle
  int16_t mAngle;
  /// Prototype for this message
  static const Steering mProto;
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

#endif // STEERING_H
