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

/** \file PRIUSReader.h
    \brief This file defines the PRIUSReader class which is an interface for
           reading CAN messages from the PRIUS.
  */

#ifndef PRIUSREADER_H
#define PRIUSREADER_H

#include <memory>

class PRIUSMessage;
class CANConnection;

/** The PRIUSReader class is an interface for reading CAN messages from
    the PRIUS.
    \brief PRIUS reading interface for CAN messages
  */
class PRIUSReader {
  /** \name Private constructors
    @{
    */
  /// Copy constructor
  PRIUSReader(const PRIUSReader& other);
  /// Assignment operator
  PRIUSReader& operator = (const PRIUSReader& other);
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Constructs with CAN device to read from
  PRIUSReader(CANConnection& device);
  /// Destructor
  virtual ~PRIUSReader();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Reads a message from the PRIUS
  std::shared_ptr<PRIUSMessage> readMessage();
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// CAN device to read from
  CANConnection& mDevice;
  /** @}
    */

};

#endif // PRIUSREADER_H
