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

/** \file binaryLogger.cpp
    \brief This file is a testing binary for logging binary data.
  */

#include <iostream>
#include <fstream>
#include <memory>

#include "com/CANConnection.h"
#include "sensor/PRIUSReader.h"
#include "exceptions/IOException.h"
#include "base/BinaryStreamWriter.h"
#include "base/Timestamp.h"
#include "types/PRIUSMessage.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <LogFilename>"
      << std::endl;
    return -1;
  }
  CANConnection device;
  PRIUSReader reader(device);
  while (true) {
    try {
      std::shared_ptr<PRIUSMessage> message = reader.readMessage();
      std::ofstream logFile(argv[1], std::ios_base::app);
      BinaryStreamWriter<std::ofstream> binaryWriter(logFile);
      binaryWriter << Timestamp::now();
      binaryWriter << *message;
    }
    catch (IOException& e) {
      std::cerr << e.what() << std::endl;
      continue;
    }
  }
  return 0;
}
