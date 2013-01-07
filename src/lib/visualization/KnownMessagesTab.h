/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
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

/** \file KnownMessagesTab.h
    \brief This file defines the KnownMessagesTab class which displays all the
           known messages.
  */

#ifndef KNOWNMESSAGESTAB_H
#define KNOWNMESSAGESTAB_H

#include <memory>

#include "visualization/Control.h"
#include "base/Singleton.h"

class Ui_KnownMessagesTab;
class PRIUSMessage;

/** The KnownMessagesTab class is the control for the known messages from the
    PRIUS
    \brief Known messages display
  */
class KnownMessagesTab :
  public Control,
  public Singleton<KnownMessagesTab> {

Q_OBJECT

  /** \name Private constructors
    @{
    */
  /// Copy constructor
  KnownMessagesTab(const KnownMessagesTab& other);
  /// Assignment operator
  KnownMessagesTab& operator = (const KnownMessagesTab& other);
  /** @}
    */

public:
  /** \name Constructors/destructor
    @{
    */
  /// Default constructor
  KnownMessagesTab();
  /// Destructor
  virtual ~KnownMessagesTab();
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
  Ui_KnownMessagesTab* mUi;
  /** @}
    */

protected slots:
  /** \name Protected slots
    @{
    */
  /// Message read
  void readMessage(std::shared_ptr<PRIUSMessage> message);
  /** @}
    */

};

#endif // KNOWNMESSAGESTAB_H
