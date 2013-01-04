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

#include "com/NetUtils.h"

#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>

#include <sstream>

#include "exceptions/IOException.h"

namespace NetUtils {

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

std::string getHostIP(const std::string &serverHost) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = 0;
  struct addrinfo* result;
  int ret = getaddrinfo(serverHost.c_str(), NULL, &hints, &result);
  if (ret) {
    std::stringstream exceptStream;
    exceptStream << "NetUtils::getServerIP()::getaddrinfo(): ";
    exceptStream << gai_strerror(ret);
    throw IOException(exceptStream.str());
  }
  std::string ipString(inet_ntoa(
    ((const struct sockaddr_in*)result->ai_addr)->sin_addr));
  freeaddrinfo(result);
  return ipString;
}

bool isBase64(char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64Encode(const std::string &input) {
  char const* bytes_to_encode = input.c_str();
  unsigned int in_len = input.size();
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];
  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) +
        ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) +
        ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;
      for(i = 0; (i < 4); ++i)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }
  if (i)
  {
    for(j = i; j < 3; ++j)
      char_array_3[j] = '\0';
    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) +
      ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) +
      ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;
    for (j = 0; (j < i + 1); ++j)
      ret += base64_chars[char_array_4[j]];
    while((i++ < 3))
      ret += '=';
  }
  return ret;
}

std::string base64Decode(const std::string &input) {
  int in_len = input.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;
  while (in_len-- && (input[in_] != '=') &&
      isBase64(input[in_])) {
    char_array_4[i++] = input[in_]; in_++;
    if (i == 4) {
      for (i = 0; i < 4; ++i)
        char_array_4[i] = base64_chars.find(char_array_4[i]);
      char_array_3[0] = (char_array_4[0] << 2) +
        ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) +
        ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +
        char_array_4[3];
      for (i = 0; (i < 3); ++i)
        ret += char_array_3[i];
      i = 0;
    }
  }
  if (i) {
    for (j = i; j < 4; ++j)
      char_array_4[j] = 0;
    for (j = 0; j < 4; ++j)
      char_array_4[j] = base64_chars.find(char_array_4[j]);
    char_array_3[0] = (char_array_4[0] << 2) +
      ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) +
      ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +
      char_array_4[3];
    for (j = 0; (j < i - 1); ++j) ret += char_array_3[j];
  }
  return ret;
}

}
