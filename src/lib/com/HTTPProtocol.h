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

/** \file HTTPProtocol.h
    \brief This file defines the HTTPProtocol namespace which contains utilities
           for HTTP protocol.
  */

#ifndef HTTPPROTOCOL_H
#define HTTPPROTOCOL_H

#include <string>
#include <vector>

class BinaryReader;

/** The class HTTPProtocol contains HTTP protocol utilities.
    \brief HTTP protocol utilities
  */
namespace HTTPProtocol {
  /** \name Type definitions
    @{
    */
  /// Method
  enum Method {
    OPTIONS,
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    TRACE,
    CONNECT,
  };
  /// General header
  enum GeneralHeader {
    CacheControl,
    Connection,
    Date,
    Pragma,
    Trailer,
    TransferEncoding,
    Upgrade,
    Via,
    Warning
  };
  /// Request headers
  enum RequestHeader {
    Accept,
    AcceptCharset,
    AcceptEncoding,
    AcceptLanguage,
    Authorization,
    Expect,
    From,
    Host,
    IfMatch,
    IfModifiedSince,
    IfNoneMatch,
    IfRange,
    IfUnmodifiedSince,
    MaxForwards,
    ProxyAuthorization,
    Range,
    Referer,
    TE,
    UserAgent
  };
  /// Entity headers
  enum EntityHeader {
    Allow,
    ContentEncoding,
    ContentLanguage,
    ContentLength,
    ContentLocation,
    ContentMD5,
    ContentRange,
    ContentType,
    Expires,
    LastModified,
  };
  /// Response headers
  enum ResponseHeader {
    AcceptRanges,
    Age,
    ETag,
    Location,
    ProxyAuthenticate,
    RetryAfter,
    Server,
    Vary,
    WWWAuthenticate
  };
 /** @}
    */

  /** \name Members
    @{
    */
  /// Methods string
  static std::vector<std::string> methods = {
    "OPTIONS",
    "GET",
    "HEAD",
    "POST",
    "PUT",
    "DELETE",
    "TRACE",
    "CONNECT"
  };
  /// General headers string
  static std::vector<std::string> generalHeaders = {
    "Cache-Control",
    "Connection",
    "Date",
    "Pragma",
    "Trailer",
    "Transfer-Encoding",
    "Upgrade",
    "Via",
    "Warning"
  };
  /// Request headers string
  static std::vector<std::string> requestHeaders = {
    "Accept",
    "Accept-Charset",
    "Accept-Encoding",
    "Accept-Language",
    "Authorization",
    "Expect",
    "From",
    "Host",
    "If-Match",
    "If-Modified-Since",
    "If-None-Match",
    "If-Range",
    "If-Unmodified-Since",
    "Max-Forwards",
    "Proxy-Authorization",
    "Range",
    "Referer",
    "TE",
    "User-Agent"
  };
  /// Entity headers string
  static std::vector<std::string> entityHeaders = {
    "Allow",
    "Content-Encoding",
    "Content-Language",
    "Content-Length",
    "Content-Location",
    "Content-MD5",
    "Content-Range",
    "Content-Type",
    "Expires",
    "Last-Modified"
  };
  /// Response headers string
  static std::vector<std::string> responseHeaders = {
    "Accept-Ranges",
    "Age",
    "ETag",
    "Location",
    "Proxy-Authenticate",
    "Retry-After",
    "Server",
    "Vary",
    "WWW-Authenticate"
  };
 /** @}
    */

  /** \name Methods
    @{
    */
  /// Write request line
  std::string writeRequestLine(Method method,
    const std::string& uri = "", const std::string& httpVersion = "1.1") ;
  /// Write response line
  std::string writeResponseLine(const std::string& httpVersion, size_t
    statusCode, const std::string& reasonPhrase);
  /// Read response status line
  void readResponseStatusLine(const std::string& line, std::string& protocol,
    std::string& statusCode, std::string& reasonPhrase);
  /// Write general header line
  std::string writeGeneralHeaderLine(GeneralHeader generalHeader, const
    std::string& value);
  /// Write request header line
  std::string writeRequestHeaderLine(RequestHeader requestHeader, const
    std::string& value);
  /// Write request header line
  std::string writeEntityHeaderLine(EntityHeader entityHeader, const
    std::string& value);
  /// Write response header line
  std::string writeResponseHeaderLine(ResponseHeader responseHeader, const
    std::string& value);
  /// Write user header line
  std::string writeUserHeaderLine(const std::string& userHeader, const
    std::string& value);
  /// Read header line
  void readHeaderLine(const std::string& line, std::string& header, std::string&
    value);
  /// Read line
  std::string readLine(BinaryReader& stream);
  /// Read data chunk
  std::string readDataChunk(BinaryReader& stream);
 /** @}
    */

};

#endif // HTTPPROTOCOL_H
