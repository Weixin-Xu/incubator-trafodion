// @@@ START COPYRIGHT @@@
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
// @@@ END COPYRIGHT @@@
//
//
#ifndef SQLTOCCONV_H
#define SQLTOCCONV_H

#ifdef unixcli
#include "unix_extra.h"
#endif
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include "drvrglobal.h"
#include "charsetconv.h"
#include "cdesc.h"

namespace ODBC {

unsigned long ConvertSQLToC(SQLINTEGER      ODBCAppVersion,
                            DWORD           DataLangId,
                            CDescRec*       srcDescPtr,
                            SQLSMALLINT     SQLDataType,
                            SQLPOINTER      srcDataPtr,
                            SQLINTEGER      srcLength,
                            SQLSMALLINT     CDataType,
                            SQLPOINTER      targetDataPtr,
                            SQLINTEGER      targetLength,
                            SQLLEN*         targetStrLenPtr,
                            BOOL            bigEndian,
#ifdef unixcli
                            ICUConverter*   iconv,
#else
                            DWORD           translateOption = 0,
#endif
                            SQLINTEGER*     totalReturnedLength = NULL,//offset in Input
                            UCHAR*          errorMsg = NULL,
                            SWORD           errorMsgMax = 0,
                            SQLINTEGER      EnvironmentType = NSK_BUILD_1,
                            BOOL            ColumnwiseData = FALSE,//catalog api set TRUE
                            CHAR*           replacementChar = NULL
                            );


unsigned long ConvFromSQLBool(SQLPOINTER srcDataPtr, SQLPOINTER targetDataPtr, SQLINTEGER targetLength, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvSQLCharToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLINTEGER srcLength, SQLSMALLINT CDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, ICUConverter* iconv, UCHAR *errorMsg = NULL);
unsigned long ConvSQLNumberToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLINTEGER srcLength, SQLSMALLINT SQLDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvertSoftDecimalToDouble(SQLSMALLINT SQLDataType, SQLPOINTER srcDataPtr, SQLINTEGER srcLength, SQLSMALLINT srcScale, double &dTmp);
unsigned long ConvDoubleToCNumber(double dTmp, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvInt64ToCNumber(__int64 tempVal64, unsigned __int64 utempVal64, bool unsignedValue, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);


}


#endif
