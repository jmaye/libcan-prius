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

/** \file view.cpp
    \brief This file is a testing binary for live visualization of PRIUS
           messages.
  */

#include <string>

#include <QtGui/QApplication>
#include <QtCore/QThread>
#include <QtCore/QMetaType>

#include "com/CANConnection.h"
#include "sensor/PRIUSReader.h"
#include "visualization/CANCom.h"
#include "visualization/MainWindow.h"
#include "visualization/KnownMessagesTab.h"
#include "types/PRIUSMessage.h"

Q_DECLARE_METATYPE(std::shared_ptr<PRIUSMessage>);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char** argv) {
  qRegisterMetaType<std::shared_ptr<PRIUSMessage> >();
  qRegisterMetaType<std::string>();
  QApplication application(argc, argv);
  CANConnection device;
  PRIUSReader reader(device);
  CANCom canCom(reader);
//  QThread* canThread = new QThread;
//  canCom.moveToThread(canThread);
//  canThread->start();
  MainWindow mainWindow;
  mainWindow.setWindowTitle("Toyota PRIUS CAN View");
  KnownMessagesTab knownMessagesTab;
  mainWindow.addControl("Known Messages", knownMessagesTab);
  QObject::connect(&canCom,
    SIGNAL(comException(const std::string&)),
    &mainWindow,
    SLOT(comException(const std::string&)));
  QObject::connect(&canCom,
    SIGNAL(deviceConnected(bool)),
    &mainWindow,
    SLOT(deviceConnected(bool)));
  QObject::connect(&canCom,
    SIGNAL(readMessage(std::shared_ptr<PRIUSMessage>)),
    &knownMessagesTab,
    SLOT(readMessage(std::shared_ptr<PRIUSMessage>)));
  mainWindow.show();
  const int ret = application.exec();
  QObject::disconnect(&canCom,
    SIGNAL(comException(const std::string&)),
    &mainWindow,
    SLOT(comException(const std::string&)));
  QObject::connect(&canCom,
    SIGNAL(deviceConnected(bool)),
    &mainWindow,
    SLOT(deviceConnected(bool)));
  QObject::disconnect(&canCom,
    SIGNAL(readMessage(std::shared_ptr<PRIUSMessage>)),
    &knownMessagesTab,
    SLOT(readMessage(std::shared_ptr<PRIUSMessage>)));
  return ret;
}
