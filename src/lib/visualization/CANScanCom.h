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

/** \file CANScanCom.h
    \brief This file defines the CANScanCom class which scans CAN communication
           with the PRIUS.
  */

#ifndef CANSCANCOM_H
#define CANSCANCOM_H

#include <memory>

#include <QtCore/QObject>
#include <QtCore/QTimer>

#include "com/CANConnection.h"

/** The CANScanCom class scans CAN communication with the PRIUS.
    \brief Scanner for CAN communication with the PRIUS
  */
class CANScanCom :
  public QObject {

Q_OBJECT

  /** \name Private constructors
    @{
    */
  /// Copy constructor
  CANScanCom(const CANScanCom& other);
  /// Assignment operator
  CANScanCom& operator = (const CANScanCom& other);
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Constructs reader with polling time and device
  CANScanCom(CANConnection& device, double pollingTime = 0.0);
  /// Destructor
  virtual ~CANScanCom();
  /** @}
    */

  /** \name Accessors
    @{
    */
  /// Returns the polling time
  double getPollingTime() const;
  /// Sets the polling time
  void setPollingTime(double pollingTime);
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Device
  CANConnection& mDevice;
  /// Timer
  QTimer mTimer;
  /// Polling time
  double mPollingTime;
  /** @}
    */

protected slots:
  /** \name Qt slots
    @{
    */
  /// Timeout of the timer
  void timerTimeout();
  /** @}
    */

signals:
  /** \name Qt signals
    @{
    */
  /// Message read
  void readMessage(std::shared_ptr<CANConnection::Message> message);
  /// Com exception
  void comException(const std::string& msg);
  /** @}
    */

};

#endif // CANSCANCOM_H
