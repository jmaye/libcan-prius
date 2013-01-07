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

/** \file ScannedMessagesTab.h
    \brief This file defines the ScannedMessagesTab class which displays all the
           scanned messages.
  */

#ifndef SCANNEDMESSAGESTAB_H
#define SCANNEDMESSAGESTAB_H

#include <memory>
#include <map>
#include <utility>

#include <QtGui/QGridLayout>
#include <QtGui/QLabel>

#include "visualization/Control.h"
#include "base/Singleton.h"
#include "com/CANConnection.h"

class Ui_ScannedMessagesTab;

/** The ScannedMessagesTab class is the control for the scanned messages from
    PRIUS
    \brief Scanned messages display
  */
class ScannedMessagesTab :
  public Control,
  public Singleton<ScannedMessagesTab> {

Q_OBJECT

  /** \name Private constructors
    @{
    */
  /// Copy constructor
  ScannedMessagesTab(const ScannedMessagesTab& other);
  /// Assignment operator
  ScannedMessagesTab& operator = (const ScannedMessagesTab& other);
  /** @}
    */

  /** \name Types definitions
    @{
    */
  /// CAN message displaying
  class CANMsgDisplay :
    public QWidget {
  public:
    /// Constructor
    CANMsgDisplay(QWidget* parent = 0) {
      msgLayout = new QGridLayout(this);
      idLabel = new QLabel(this);
      msgLayout->addWidget(idLabel, 0, 0);
      contentLabel = new QLabel(this);
      msgLayout->addWidget(contentLabel, 0, 1);
    }
    QGridLayout* msgLayout;
    QLabel* idLabel;
    QLabel* contentLabel;
  };
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Default constructor
  ScannedMessagesTab();
  /// Destructor
  virtual ~ScannedMessagesTab();
  /** @}
    */

protected:
  /** \name Protected methods
    @{
    */
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Pointer to the UI
  Ui_ScannedMessagesTab* mUi;
  /// Map containing already received messages
  std::map<int, std::pair<int, int>> mMessages;
  /// Number of rows
  int mNumRows;
  /// Number of columns
  int mNumCols;
  /** @}
    */

protected slots:
  /** \name Protected slots
    @{
    */
  /// Message read
  void readMessage(std::shared_ptr<CANConnection::Message> message);
  /** @}
    */

};

#endif // SCANNEDMESSAGESTAB_H
