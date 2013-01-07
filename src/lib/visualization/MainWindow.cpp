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

#include "visualization/MainWindow.h"

#include "ui_MainWindow.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

MainWindow::MainWindow() :
    mUi(new Ui_MainWindow()) {
  mUi->setupUi(this);
  while (mUi->tabsWidget->count())
    mUi->tabsWidget->removeTab(0);
  mUi->statusBar->showMessage("Disconnected");
}

MainWindow::~MainWindow() {
  delete mUi;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void MainWindow::addControl(const QString& title, Control& control) {
  mUi->tabsWidget->addTab(&control, title);
  if (!control.getMenu().isEmpty())
    mUi->menuBar->addMenu(&control.getMenu())->setText(title);
}

void MainWindow::deviceConnected(bool connected) {
  if (connected == true)
    mUi->statusBar->showMessage("Connected");
  else
    mUi->statusBar->showMessage("Disconnected");
}

void MainWindow::comException(const std::string& msg) {
  mUi->statusBar->showMessage(QString(msg.c_str()));
}
