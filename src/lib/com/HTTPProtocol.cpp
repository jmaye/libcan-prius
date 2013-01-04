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

#include "com/HTTPProtocol.h"

#include <sstream>

#include "base/BinaryReader.h"
#include "exceptions/IOException.h"

namespace HTTPProtocol {

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

std::string writeRequestLine(Method method, const std::string& uri, const
    std::string& httpVersion) {
  std::stringstream requestLine;
  requestLine << methods[method] << " ";
  if (uri.empty())
    requestLine << "/";
  else
    requestLine << uri;
  requestLine << " HTTP/" << httpVersion << "\r\n";
  return requestLine.str();
}

std::string writeResponseLine(std::string& httpVersion, size_t statusCode,
    const std::string& reasonPhrase) {
  std::stringstream responseLine;
  responseLine << "HTTP/" << httpVersion << " " << statusCode << " "
    << reasonPhrase;
  return responseLine.str();
}

void readResponseStatusLine(const std::string& line, std::string& protocol,
    std::string& statusCode, std::string& reasonPhrase) {
  std::stringstream lineStream(line);
  lineStream >> protocol;
  lineStream >> statusCode;
  lineStream >> reasonPhrase;
}

std::string writeGeneralHeaderLine(GeneralHeader generalHeader, const
    std::string& value) {
  return writeUserHeaderLine(generalHeaders[generalHeader], value);
}

std::string writeRequestHeaderLine(RequestHeader requestHeader, const
    std::string& value) {
  return writeUserHeaderLine(requestHeaders[requestHeader], value);
}

std::string writeEntityHeaderLine(EntityHeader entityHeader, const
    std::string& value) {
  return writeUserHeaderLine(entityHeaders[entityHeader], value);
}

std::string writeResponseHeaderLine(ResponseHeader responseHeader, const
    std::string& value) {
  return writeUserHeaderLine(responseHeaders[responseHeader], value);
}

std::string writeUserHeaderLine(const std::string& userHeader, const
    std::string& value) {
  std::stringstream headerLine;
  headerLine << userHeader << ": " << value << "\r\n";
  return headerLine.str();
}

void readHeaderLine(const std::string& line, std::string& header, std::string&
    value) {
  std::stringstream lineStream(line);
  lineStream >> header;
  header.erase(header.size() - 1);
  value = line.substr(lineStream.tellg());
  value.erase(0, 1);
}

std::string readLine(BinaryReader& stream) {
  uint8_t currentByte = 0;
  uint8_t previousByte = 0;
  std::string line;
  do {
    previousByte = currentByte;
    stream >> currentByte;
    line.push_back(currentByte);
  }
  while (currentByte != '\n' && previousByte != '\r');
  return line;
}

std::string readDataChunk(BinaryReader& stream) {
  std::string line = readLine(stream);
  std::stringstream lineStream(line);
  size_t bytes;
  lineStream >> std::hex >> bytes;
  if (bytes) {
    char buffer[bytes];
    stream.read(buffer, bytes);
    readLine(stream);
    return std::string(buffer, bytes);
  }
  else
    return std::string();
}

}
