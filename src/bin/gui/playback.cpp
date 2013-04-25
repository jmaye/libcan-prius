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

/** \file playback.cpp
    \brief This file is a testing binary for playback visualization of PRIUS
           messages.
  */

#include <iostream>
#include <fstream>

#include <QtGui/QApplication>
#include <QtCore/QMetaType>

#include "visualization/LogReader.h"
#include "visualization/MainWindow.h"
#include "visualization/KnownMessagesTab.h"
#include "types/PRIUSMessage.h"
#include "base/BinaryStreamReader.h"

Q_DECLARE_METATYPE(std::shared_ptr<PRIUSMessage>);

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <logFile>" << std::endl;
    return 1;
  }
  qRegisterMetaType<std::shared_ptr<PRIUSMessage> >();
  QApplication application(argc, argv);
  MainWindow mainWindow;
  mainWindow.setWindowTitle("Toyota PRIUS CAN Playback");
  KnownMessagesTab knownMessagesTab;
  mainWindow.addControl("Known Messages", knownMessagesTab);
  std::ifstream logFile(argv[1]);
  BinaryStreamReader<std::ifstream> binaryStreamReader(logFile);
  LogReader logReader(binaryStreamReader);
  QObject::connect(&logReader,
    SIGNAL(deviceConnected(bool)),
    &mainWindow,
    SLOT(deviceConnected(bool)));
  QObject::connect(&logReader,
    SIGNAL(readMessage(std::shared_ptr<PRIUSMessage>)),
    &knownMessagesTab,
    SLOT(readMessage(std::shared_ptr<PRIUSMessage>)));
  mainWindow.show();
  const int ret = application.exec();
  QObject::disconnect(&logReader,
    SIGNAL(deviceConnected(bool)),
    &mainWindow,
    SLOT(deviceConnected(bool)));
  QObject::disconnect(&logReader,
    SIGNAL(readMessage(std::shared_ptr<PRIUSMessage>)),
    &knownMessagesTab,
    SLOT(readMessage(std::shared_ptr<PRIUSMessage>)));
  return ret;
}
