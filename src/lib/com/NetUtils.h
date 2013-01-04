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

/** \file NetUtils.h
    \brief This file defines the NetUtils namespace which contains utilities
           for networking.
  */

#ifndef NETUTILS_H
#define NETUTILS_H

#include <string>

/** The class NetUtils contains networking utilities.
    \brief Networking utilities
  */
namespace NetUtils {
  /** \name Members
    @{
    */
  /// Static base64 characters
  const std::string base64_chars = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
 /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a host's IP from its hostname
  std::string getHostIP(const std::string &serverHost);
  /// Check if a character is base64 encoded
  bool isBase64(char c);
  /// Encodes to base64 representation
  std::string base64Encode(const std::string &input);
  /// Decodes base64 representation
  std::string base64Decode(const std::string &input);
 /** @}
    */

};

#endif // NETUTILS_H
