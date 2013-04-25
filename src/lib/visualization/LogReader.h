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

/** \file LogReader.h
    \brief This file defines the LogReader class which handles reading from a
           log file.
  */

#ifndef LOGREADER_H
#define LOGREADER_H

#include <memory>
#include <string>

#include <QtCore/QObject>
#include <QtCore/QTimer>

template <typename T> class BinaryStreamReader;
class PRIUSMessage;

/** The LogReader class handles playback from a log file
    \brief Playback from a log file
  */
class LogReader :
  public QObject {

Q_OBJECT

  /** \name Private constructors
    @{
    */
  /// Copy constructor
  LogReader(const LogReader& other);
  /// Assignment operator
  LogReader& operator = (const LogReader& other);
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Constructs reader with polling time and device
  LogReader(BinaryStreamReader<std::ifstream>& device, double pollingTime = 1);
  /// Destructor
  virtual ~LogReader();
  /** @}
    */

  /** \name Accessors
    @{
    */
  /// Returns the polling time
  double getPollingTime() const;
  /// Sets the polling time
  void setPollingTime(double pollingTime);
  /// Returns the file length
  int getFileLength() const;
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Device
  BinaryStreamReader<std::ifstream>& mDevice;
  /// Timer
  QTimer mTimer;
  /// Polling time
  double mPollingTime;
  /// Length of the file
  int mFileLength;
  /// Done reading file
  bool mDone;
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
  void readMessage(std::shared_ptr<PRIUSMessage> message);
  /// Start reading file
  void start();
  /// EOF
  void eof();
  /// Device connected
  void deviceConnected(bool connected);
  /** @}
    */

};

#endif // LOGREADER_H
