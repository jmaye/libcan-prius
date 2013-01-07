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

/** \file MainWindow.h
    \brief This file defines the MainWindow class which is the main window
           for live visualization of PRIUS data
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtCore/QString>

#include "visualization/Control.h"

class Ui_MainWindow;

/** The MainWindow class is the main window for live visualization of
    Applanix data.
    \brief Live visualization of Applanix data
  */
class MainWindow :
  public QMainWindow {

Q_OBJECT

  /** \name Private constructors
    @{
    */
  /// Copy constructor
  MainWindow(const MainWindow& other);
  /// Assignment operator
  MainWindow& operator = (const MainWindow& other);
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Default constructor
  MainWindow();
  /// Destructor
  virtual ~MainWindow();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Adds a control to the main window
  void addControl(const QString& title, Control& control);
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Pointer to the UI
  Ui_MainWindow* mUi;
  /** @}
    */

protected slots:
  /** \name Protected slots
    @{
    */
  /// Is the PRIUS connected?
  void deviceConnected(bool connected);
  /// Com exception
  void comException(const std::string& msg);
  /** @}
    */

};

#endif // MAINWINDOW_H
