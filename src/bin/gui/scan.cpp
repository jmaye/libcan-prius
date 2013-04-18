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

/** \file scan.cpp
    \brief This file is a testing binary for scanning PRIUS CAN bus.
  */

#include <string>

#include <QtGui/QApplication>
#include <QtCore/QThread>
#include <QtCore/QMetaType>

#include "com/CANConnection.h"
#include "visualization/CANScanCom.h"
#include "visualization/MainWindow.h"
#include "visualization/ScannedMessagesTab.h"

Q_DECLARE_METATYPE(std::shared_ptr<CANConnection::Message>);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char** argv) {
  qRegisterMetaType<std::shared_ptr<CANConnection::Message> >();
  qRegisterMetaType<std::string>();
  QApplication application(argc, argv);
  CANConnection device;
  CANScanCom canCom(device);
//  QThread* canThread = new QThread;
//  canCom.moveToThread(canThread);
//  canThread->start();
  MainWindow mainWindow;
  mainWindow.setWindowTitle("Toyota PRIUS CAN Scan");
  ScannedMessagesTab scannedMessagesTab;
  mainWindow.addControl("Scanned Messages", scannedMessagesTab);
  QObject::connect(&canCom,
    SIGNAL(comException(const std::string&)),
    &mainWindow,
    SLOT(comException(const std::string&)));
  QObject::connect(&canCom,
    SIGNAL(readMessage(std::shared_ptr<CANConnection::Message>)),
    &scannedMessagesTab,
    SLOT(readMessage(std::shared_ptr<CANConnection::Message>)));
  mainWindow.show();
  const int ret = application.exec();
  QObject::disconnect(&canCom,
    SIGNAL(comException(const std::string&)),
    &mainWindow,
    SLOT(comException(const std::string&)));
  QObject::disconnect(&canCom,
    SIGNAL(readMessage(std::shared_ptr<CANConnection::Message>)),
    &scannedMessagesTab,
    SLOT(readMessage(std::shared_ptr<CANConnection::Message>)));
  return ret;
}
