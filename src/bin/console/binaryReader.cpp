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

/** \file binaryReader.cpp
    \brief This file is a testing binary for reading binary data from log
  */

#include <iostream>
#include <fstream>
#include <memory>

#include "exceptions/IOException.h"
#include "base/BinaryStreamReader.h"
#include "types/PRIUSMessage.h"
#include "base/Factory.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <LogFilename>"
      << std::endl;
    return -1;
  }
  std::ifstream logFile(argv[1]);
  BinaryStreamReader<std::ifstream> logReader(logFile);
  logFile.seekg (0, std::ios::end);
  const int length = logFile.tellg();
  logFile.seekg (0, std::ios::beg);
  while (logFile.tellg() != length) {
    double timestamp;
    logReader >> timestamp;
    int typeID;
    logReader >> typeID;
    std::shared_ptr<PRIUSMessage>
      priusMessage(Factory<int, PRIUSMessage>::getInstance().create(
      typeID));
    logReader >> *priusMessage;
  }
  return 0;
}
