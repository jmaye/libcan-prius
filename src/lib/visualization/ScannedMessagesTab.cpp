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

#include "visualization/ScannedMessagesTab.h"

#include "ui_ScannedMessagesTab.h"

#include <sstream>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ScannedMessagesTab::ScannedMessagesTab() :
    mUi(new Ui_ScannedMessagesTab()),
    mNumRows(0),
    mNumCols(0) {
  mUi->setupUi(this);
}

ScannedMessagesTab::~ScannedMessagesTab() {
  delete mUi;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ScannedMessagesTab::readMessage(std::shared_ptr<CANConnection::Message>
    message) {
  std::stringstream idStream;
  idStream << std::hex << message->id;
  std::stringstream contentStream;
  for (int i = 0; i < message->length; ++i)
    contentStream << message->content[i];
  CANMsgDisplay* canMsg = 0;
  if (mMessages.find(message->id) != mMessages.end()) {
    std::pair<int, int> pos = mMessages[message->id];
    QWidget* canWidget =
      mUi->messagesLayout->itemAtPosition(pos.first, pos.second)->widget();
    canMsg = dynamic_cast<CANMsgDisplay*>(canWidget);
  }
  else {
    mMessages[message->id] = std::pair<int, int>(mNumRows, mNumCols);
    canMsg = new CANMsgDisplay(this);
    mUi->messagesLayout->addWidget(canMsg, mNumRows, mNumCols);
    if (mNumRows == 25) {
      mNumRows = 0;
      mNumCols++;
    }
    else
      mNumRows++;
  }
  canMsg->idLabel->setText(QString(idStream.str().c_str()));
  canMsg->contentLabel->setText(QString(contentStream.str().c_str()));
  canMsg->repaint();
}
