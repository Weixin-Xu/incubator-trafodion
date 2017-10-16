/**********************************************************************
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
**************************************************************************/
//
//
#include "sqltocconv.h"
#include <errno.h>
#include <stdio.h>
#ifdef unixcli
#include <float.h>
#include "unix_extra.h"
#endif
#include <limits.h>
#include <time.h>
#include "sqlcli.h"
#include "DrvrSrvr.h"
#include "mxomsg.h"
#include "drvrglobal.h"
#include "nskieee.h"
#include "diagfunctions.h"
#include "csconvert.h"

unsigned long ODBC::ConvertSQLToC(SQLINTEGER      ODBCAppVersion,
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
                            DWORD           translateOption,
#endif
                            SQLINTEGER*     totalReturnedLength,
                            UCHAR*          errorMsg,
                            SWORD           errorMsgMax,
                            SQLINTEGER      EnvironmentType,
                            BOOL            ColumnwiseData,
                            CHAR*           replacementChar
                            )
{
    unsigned long   retCode     = SQL_SUCCESS;
    SQLINTEGER      Offset      = 0;

    if (errorMsg != NULL)
        *errorMsg = '\0';
    
    if (srcDataPtr == NULL)
        return IDS_HY_000;

    DataLangId = LANG_NEUTRAL;

    if (totalReturnedLength != NULL)
    {
        Offset = *totalReturnedLength;
        *totalReturnedLength = -1;
    }
    else
        Offset = 0;

    if (CDataType == SQL_C_DEFAULT)
        getCDefault(srcDescPtr->m_ODBCDataType, ODBCAppVersion, srcDescPtr->m_SQLCharset, CDataType);

    switch (CDataType)
    {
    case SQL_C_CHAR:
    case SQL_C_WCHAR:
        switch (srcDescPtr->m_ODBCDataType)
        {
        case SQL_CHAR:
            if (SQLDataType == SQLTYPECODE_BOOLEAN)
            {
                ConvFromSQLBool(srcDataPtr, targetDataPtr, targetLength, targetStrLenPtr, CDataType);
                break;
            }
        case SQL_WCHAR:
//            ConvSQLCharToChar();
            break;
        case SQL_VARCHAR:
        case SQL_WVARCHAR:
        case SQL_LONGVARCHAR:
            break;
        default:
            return IDS_07_006;
        }
        break;

    case SQL_C_BINARY:
        break;

    case SQL_C_TINYINT:
    case SQL_C_STINYINT:
    case SQL_C_BIT:
    case SQL_C_UTINYINT:
    case SQL_C_SHORT:
    case SQL_C_SSHORT:
    case SQL_C_USHORT:
    case SQL_C_LONG:
    case SQL_C_SLONG:
    case SQL_C_ULONG:
    case SQL_C_SBIGINT:
    case SQL_C_UBIGINT:
    case SQL_C_FLOAT:
    case SQL_C_DOUBLE:
        switch (srcDescPtr->m_ODBCDataType)
        {
        case SQL_CHAR:
            if (SQLDataType == SQLTYPECODE_BOOLEAN)
            {
                retCode = ConvFromSQLBool(srcDataPtr, targetDataPtr, targetLength, targetStrLenPtr, CDataType);
                break;
            }
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR:
        case SQL_LONGVARCHAR:
                retCode = ConvSQLCharToNumber(srcDataPtr, srcDescPtr, srcLength, CDataType, targetDataPtr, targetStrLenPtr, iconv, errorMsg);
            break;

        case SQL_TINYINT:
        case SQL_SMALLINT:
        case SQL_INTEGER:
        case SQL_BIGINT:
        case SQL_REAL:
        case SQL_DOUBLE:
            retCode = ConvSQLNumberToNumber(srcDataPtr, srcDescPtr, srcLength, SQLDataType, targetDataPtr, targetStrLenPtr, CDataType);
            break;
        case SQL_NUMERIC:
        default:
            return IDS_07_006;
        }
        break;

    case SQL_C_DATE:
    case SQL_C_TYPE_DATE:
        break;
        
    case SQL_C_TIME:
    case SQL_C_TYPE_TIME:
        break;

    case SQL_C_TIMESTAMP:
    case SQL_C_TYPE_TIMESTAMP:
        break;

    case SQL_C_NUMERIC:
        break;

    case SQL_C_INTERVAL_MONTH:
    case SQL_C_INTERVAL_YEAR:
    case SQL_C_INTERVAL_YEAR_TO_MONTH:
    case SQL_C_INTERVAL_DAY:
    case SQL_C_INTERVAL_HOUR:
    case SQL_C_INTERVAL_MINUTE:
    case SQL_C_INTERVAL_SECOND:
    case SQL_C_INTERVAL_DAY_TO_HOUR:
    case SQL_C_INTERVAL_DAY_TO_MINUTE:
    case SQL_C_INTERVAL_DAY_TO_SECOND:
    case SQL_C_INTERVAL_HOUR_TO_MINUTE:
    case SQL_C_INTERVAL_HOUR_TO_SECOND:
    case SQL_C_INTERVAL_MINUTE_TO_SECOND:
        break;

    default:
        return IDS_07_006;
    }

    return retCode;
}

/*unsigned long ODBC::Iso88591Supported()

unsigned long ODBC::ConvSQLCharToChar(srcDataPtr, srcLength, srcCharSet, )
{
    int charlength = 0;
    int DataLen = 0;
    charlength = srcLength - 1;
    if (charlength == 0)
    {
        if (targetStrLenPtr != NULL)
            *targetStrLenPtr = 0;
        if (targetLength > 0)
            ((char*)targetDataPtr)[0] = '\0';
        return retCode;
    }
    DataLen = charlength - Offset;
    if (DataLen = 0)
        return SQL_NO_DATA;
    DataPtr = (char *) srcDataPtr + Offset;
    if (!(iconv->isIso88591Translation()) && DataLen >= targetLength && srcCharSet != SQLCHARSETCODE_UCS2 && srcCharSet != SQLCHARSETCODE_UTF8)
    {
        DataLenTruncated = DataLen;
        if (targetLength > 0)
            DataLen = targetLength-1;
        else
            DataLen = 0;
        return IDS_01_004;
    }
}*/


unsigned long ODBC::ConvertSoftDecimalToDouble(SQLSMALLINT SQLDataType, SQLPOINTER srcDataPtr, SQLINTEGER srcLength, SQLSMALLINT srcScale, double &dTmp)
{
    char *stopStr;
    char cTmpBuf[256];
    double dTmp1;
    short i;

    switch(SQLDataType)
    {
        case SQLTYPECODE_DECIMAL_LARGE:
            memcpy(cTmpBuf, (const char *)srcDataPtr, srcLength);
            // Make it as a display string
            for (i = 1; i < srcLength ; cTmpBuf[i++] += '0');
            cTmpBuf[srcLength] =  '\0';
            dTmp = strtod(cTmpBuf,&stopStr);
            dTmp1 = pow(10, srcScale);
            dTmp = dTmp / dTmp1;
            break;
        case SQLTYPECODE_DECIMAL_LARGE_UNSIGNED:
            memcpy(cTmpBuf, (const char *)srcDataPtr, srcLength);
            // Make it as a display string
            for (i = 0; i < srcLength ; cTmpBuf[i++] += '0');
            cTmpBuf[srcLength] =  '\0';
            dTmp = strtod(cTmpBuf,&stopStr);
            dTmp1 = pow(10, srcScale);
            dTmp = dTmp / dTmp1;
            break;
        default:
            return SQL_ERROR;
    }
    return SQL_SUCCESS;
}


unsigned long ODBC::ConvSQLNumberToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLINTEGER srcLength, SQLSMALLINT SQLDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    double              dTmp = 0;
    __int64             tempVal64 = 0;
    unsigned __int64            utempVal64 = 0;

    bool                useDouble = TRUE;

    switch (srcDescPtr->m_ODBCDataType)
    {
        case SQL_TINYINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((UCHAR *) srcDataPtr);
            }
            else
            {
                dTmp = *((SCHAR *) srcDataPtr);
            }
            break;

        case SQL_SMALLINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((USHORT *) srcDataPtr);
            }
            else
            {
                dTmp = *((SSHORT *) srcDataPtr);
            }
            break;

        case SQL_INTEGER:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((ULONG_P *) srcDataPtr);
            }
            else
            {
                dTmp = *((SLONG_P *) srcDataPtr);
            }
            break;
            
        case SQL_BIGINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                utempVal64 = *((unsigned __int64 *) srcDataPtr);
            }
            else
            {
                tempVal64 = *((__int64 *) srcDataPtr);
            }
            useDouble = FALSE;
            break;

        case SQL_REAL:
            if ((SQLDataType == SQLTYPECODE_DECIMAL_LARGE_UNSIGNED) ||
                (SQLDataType == SQLTYPECODE_DECIMAL_LARGE))
            {
                if (ConvertSoftDecimalToDouble(SQLDataType, srcDataPtr, srcLength, srcDescPtr->m_ODBCScale, dTmp)  != SQL_SUCCESS)
                    return IDS_07_006;
            }
            else
                dTmp = *(SFLOAT *)srcDataPtr;
            break;
        case SQL_DOUBLE:
                dTmp =  *(DOUBLE *)srcDataPtr;
            break;

        default:
			return IDS_07_006;
    }
    if (useDouble)
        ConvDoubleToCNumber(dTmp, targetDataPtr, targetStrLenPtr, CDataType);
    else
    {
        ConvInt64ToCNumber(tempVal64, utempVal64, srcDescPtr->m_DescUnsigned, targetDataPtr, targetStrLenPtr, CDataType);
    }

    return retCode;
}


unsigned long ODBC::ConvFromSQLBool(SQLPOINTER srcDataPtr, SQLPOINTER targetDataPtr, SQLINTEGER targetLength, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long   retCode  = SQL_SUCCESS;
    double      dTmp     = 0;
    SQLINTEGER  DataLen  = 0;
    rTrim((char *)srcDataPtr);
    DataLen = strlen((char *)srcDataPtr);
    switch (CDataType)
    {
        case SQL_C_CHAR:
            if (DataLen + 1 > targetLength)
                return IDS_22_003;
            *targetStrLenPtr = snprintf((char *)targetDataPtr, targetLength, "%s", srcDataPtr);
            break;
            
        case SQL_C_WCHAR:
            if (DataLen * 2 + 1 > targetLength)
                return IDS_22_003;
            *targetStrLenPtr = swprintf((wchar_t *)targetDataPtr, targetLength, L"%s", srcDataPtr);
            break;

        case SQL_C_BIT:
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
        case SQL_C_UTINYINT:
        case SQL_C_SHORT:
        case SQL_C_SSHORT:
        case SQL_C_USHORT:
        case SQL_C_LONG:
        case SQL_C_SLONG:
        case SQL_C_ULONG:
        case SQL_C_SBIGINT:
        case SQL_C_UBIGINT:
        case SQL_C_FLOAT:
        case SQL_C_DOUBLE:
            dTmp = strtod((char*)srcDataPtr, NULL);
            retCode = ConvDoubleToCNumber(dTmp, targetDataPtr, targetStrLenPtr, CDataType);
            break;
        default:
            return IDS_07_006;
    }
    
    return retCode;
}

unsigned long ODBC::ConvSQLCharToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLINTEGER srcLength, SQLSMALLINT CDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, ICUConverter* iconv, UCHAR *errorMsg)
{
    int             TransStringLength   = 0;
    double          dTmp                = 0;
    unsigned long   retCode             = SQL_SUCCESS;
    char            cTmpBuf[1024]       = {0};
    char*           error               = NULL;
    __int64         tempVal64           = 0;
    SQLINTEGER      DataLen             = 0;
    if (srcDescPtr->m_ODBCDataType == SQL_CHAR || srcDescPtr->m_ODBCDataType == SQL_WCHAR)
    {
        if (srcDescPtr->m_SQLCharset == SQLCHARSETCODE_UCS2) // convert from UTF-16 to UTF-8
        {
            UChar* spaceStart = u_strchr((UChar*)srcDataPtr, L' ');
            if (spaceStart != NULL)
                srcLength = (spaceStart - (UChar*)srcDataPtr) + 1;
            if(iconv->WCharToUTF8((UChar*)srcDataPtr, srcLength-1, (char*)cTmpBuf,
                                sizeof(cTmpBuf), &TransStringLength, (char*)errorMsg) != SQL_SUCCESS)
            {
                return IDS_22_003;
            }
            srcLength = strlen(cTmpBuf) + 1;
        }
        else
        {
            char* spaceStart = strchr((char*)srcDataPtr, ' ');
            if (spaceStart != NULL)
                srcLength = (spaceStart - (char*)srcDataPtr) + 1;
            if (srcLength <= sizeof (cTmpBuf))
            {
                strncpy(cTmpBuf, (char*)srcDataPtr, srcLength - 1);
                cTmpBuf[srcLength - 1] = 0;
            }
            else
                return IDS_22_003;
        }
        if (!ctoi64(cTmpBuf, tempVal64 ))
            return IDS_22_003;
    }
    else // SQL_VARCHAR
    {
       if (srcDescPtr->m_SQLMaxLength < 32768) //VARCHAR
       {
           DataLen = *(USHORT *)srcDataPtr;
           if (DataLen == 0)
               return SQL_NO_DATA;
           if (srcDescPtr->m_SQLCharset == SQLCHARSETCODE_UCS2)
           {
               if(iconv->WCharToUTF8((UChar*)srcDataPtr+1, DataLen/2, (char*)cTmpBuf, //srcDataPtr+1?
                                    (sizeof(cTmpBuf)) , &TransStringLength, (char*)errorMsg) != SQL_SUCCESS)
               {
                   return IDS_22_003;
               }
               srcLength = TransStringLength + 1;
           }
           else
           {
               if((DataLen + 1) <= sizeof(cTmpBuf))
               {
                   memcpy(cTmpBuf, (char*)srcDataPtr+2, DataLen);
                   srcLength = DataLen + 1;
                   cTmpBuf[DataLen] = 0;
               }
               else
                   return IDS_22_003;
           }
           if (!ctoi64(cTmpBuf, tempVal64 ))
               return IDS_22_003;
       }
       else //LONG VARCHAR
       {
           DataLen = *(UINT *)srcDataPtr;
           if (DataLen == 0)
               return SQL_NO_DATA;
           if (srcDescPtr->m_SQLCharset == SQLCHARSETCODE_UCS2) //convert from UTF-16 to UTF-8
           {
               if(iconv->WCharToUTF8((UChar*)srcDataPtr+2, DataLen/2, (char*)cTmpBuf,
                                    (sizeof(cTmpBuf)) , &TransStringLength, (char*)errorMsg) != SQL_SUCCESS)
                {
                    return IDS_22_003;
                }
               srcLength = TransStringLength + 1;
           }
           else
           {
               if((DataLen + 1) <= sizeof(cTmpBuf))
               {
                   memcpy(cTmpBuf, (char*)srcDataPtr+4, DataLen);
                   srcLength = DataLen + 1;
                   cTmpBuf[DataLen] = 0;
               }
               else
                   return IDS_22_003;
           }
           if (!ctoi64(cTmpBuf, tempVal64 ))
               return IDS_22_003;
       }
    }
    dTmp = strtod(cTmpBuf, &error);
    if (errno == ERANGE || error < (cTmpBuf + strlen(cTmpBuf)))
        return IDS_22_018;
    retCode = ConvDoubleToCNumber(dTmp, targetDataPtr, targetStrLenPtr, CDataType);
    return retCode;
}


unsigned long ODBC::ConvDoubleToCNumber(double dTmp, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    switch (CDataType)
    {
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
            if (dTmp < SCHAR_MIN || dTmp > SCHAR_MAX)
                return IDS_22_003;
            *((SCHAR *)targetDataPtr) = (SCHAR)dTmp;    
            if (*((SCHAR *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SCHAR); 
            break;

        case SQL_C_BIT:
            if(dTmp < 0 || dTmp > 2)
                return IDS_22_003; 
        case SQL_C_UTINYINT:
            if (dTmp < 0 || dTmp > UCHAR_MAX)
                return IDS_22_003;
            *((UCHAR *)targetDataPtr) = (UCHAR)dTmp;
            if (*((UCHAR *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(UCHAR); 
            break;

        case SQL_C_SHORT:
        case SQL_C_SSHORT:
            if (dTmp < SHRT_MIN || dTmp > SHRT_MAX)
                return IDS_22_003;
            *((SHORT *)targetDataPtr) = (SHORT)dTmp;
            if (*((SHORT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SHORT); 
            break;

        case SQL_C_USHORT:
            if (dTmp < 0 || dTmp > USHRT_MAX)
                return IDS_22_003;
            *((USHORT *)targetDataPtr) = (USHORT)dTmp;
            if (*((USHORT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(USHORT); 
            break;

        case SQL_C_LONG:
        case SQL_C_SLONG:
            if (dTmp < LONG_MIN || dTmp > LONG_MAX)
                return IDS_22_003;
            *((SLONG_P *)targetDataPtr) = (SLONG_P)dTmp;
            if (*((SLONG_P *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SLONG_P); 
            break;

        case SQL_C_ULONG:
            if (dTmp < 0 ||dTmp > ULONG_MAX)
                return IDS_22_003;
            *((ULONG_P *)targetDataPtr) = (ULONG_P)dTmp;
            if (*((ULONG_P *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(ULONG_P); 
            break;

        case SQL_C_SBIGINT:
            if (dTmp < LLONG_MIN || dTmp > LLONG_MAX)
                return IDS_22_003;
            *((__int64 *)targetDataPtr) = (__int64)dTmp;
            if (*((__int64 *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__int64); 
            break;

        case SQL_C_UBIGINT:
            if (dTmp < 0 || dTmp > ULLONG_MAX)
                return IDS_22_003;
            *((unsigned __int64 *)targetDataPtr) = (unsigned __int64)dTmp;
            if (*((unsigned __int64 *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(unsigned __int64); 
            break;

        case SQL_C_FLOAT:
            if (dTmp < -FLT_MAX || dTmp > FLT_MAX)
                return IDS_22_003;
            *((FLOAT *)targetDataPtr) = (FLOAT)dTmp;
            if (*((FLOAT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(FLOAT); 
            break;

        case SQL_C_DOUBLE:
            *((SQLDOUBLE *)targetDataPtr) = dTmp;
            if (*((SQLDOUBLE *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLDOUBLE); 
            break;

        default:
			return IDS_07_006;
    }

    return retCode;
}


unsigned long ODBC::ConvInt64ToCNumber(__int64 tempVal64, unsigned __int64 utempVal64, bool unsignedValue, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    switch (CDataType)
    {
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
            if (tempVal64 < SCHAR_MIN || tempVal64 > SCHAR_MAX)
                return IDS_22_003;
            *((SCHAR *)targetDataPtr) = (unsignedValue ?
                                        (SCHAR)utempVal64: (SCHAR)tempVal64);
            if (*((SCHAR *)targetDataPtr) != (unsignedValue ?
                                        (SCHAR)utempVal64: (SCHAR)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SCHAR); 
            break;

        case SQL_C_BIT:
            if (unsignedValue && (utempVal64 < 0 || utempVal64 > 1))
                return IDS_22_003;
            if (!unsignedValue && (tempVal64 < 0 || tempVal64 > 1))
                return IDS_22_003;
        case SQL_C_UTINYINT:
            if (tempVal64 > UCHAR_MAX)
                return IDS_22_003;
            *((UCHAR *)targetDataPtr) = (unsignedValue ?
                                        (UCHAR)utempVal64: (UCHAR)tempVal64);
            if (*((UCHAR *)targetDataPtr) != (unsignedValue ?
                                        (UCHAR)utempVal64: (UCHAR)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(UCHAR); 
            break;

        case SQL_C_SHORT:
        case SQL_C_SSHORT:
            if (tempVal64 < SHRT_MIN || tempVal64 > SHRT_MAX)
                return IDS_22_003;
            *((SHORT *)targetDataPtr) = (unsignedValue ?
                                        (SHORT)utempVal64: (SHORT)tempVal64);
            if (*((SHORT *)targetDataPtr) != (unsignedValue ?
                                        (SHORT)utempVal64: (SHORT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SHORT); 
            break;

        case SQL_C_USHORT:
            if (tempVal64 > USHRT_MAX)
                return IDS_22_003;
            *((USHORT *)targetDataPtr) = (unsignedValue ?
                                        (USHORT)utempVal64: (USHORT)tempVal64);
            if (*((USHORT *)targetDataPtr) != (unsignedValue ?
                                        (USHORT)utempVal64: (USHORT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(USHORT); 
            break;

        case SQL_C_LONG:
        case SQL_C_SLONG:
            if (tempVal64 < LONG_MIN || tempVal64 > LONG_MAX)
                return IDS_22_003;
            *((SLONG_P *)targetDataPtr) = (unsignedValue ?
                                        (SLONG_P)utempVal64: (SLONG_P)tempVal64);
            if (*((SLONG_P *)targetDataPtr) != (unsignedValue ?
                                        (SLONG_P)utempVal64: (SLONG_P)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SLONG_P); 
            break;

        case SQL_C_ULONG:
            if (tempVal64 > ULONG_MAX)
                return IDS_22_003;
            *((ULONG_P *)targetDataPtr) = (unsignedValue ?
                                        (ULONG_P)utempVal64: (ULONG_P)tempVal64);
            if (*((ULONG_P *)targetDataPtr) != (unsignedValue ?
                                        (ULONG_P)utempVal64: (ULONG_P)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(ULONG_P); 
            break;

        case SQL_C_SBIGINT:
            if (tempVal64 < LLONG_MIN || tempVal64 > LLONG_MAX)
                return IDS_22_003;
            *((__int64 *)targetDataPtr) = (unsignedValue ?
                                        (__int64)utempVal64: tempVal64);
            if (*((__int64 *)targetDataPtr) != (unsignedValue ?
                                        (__int64)utempVal64: tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__int64); 
            break;

        case SQL_C_UBIGINT:
            if (tempVal64 > ULLONG_MAX)
                return IDS_22_003;
            *((unsigned __int64 *)targetDataPtr) = (unsignedValue ?
                                        utempVal64: (unsigned __int64)tempVal64);
            if (*((unsigned __int64 *)targetDataPtr) != (unsignedValue ?
                                        utempVal64: (unsigned __int64)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(unsigned __int64); 
            break;

        case SQL_C_FLOAT:
            if (tempVal64 < -FLT_MAX || tempVal64 > FLT_MAX)
                return IDS_22_003;
            *((FLOAT *)targetDataPtr) = (unsignedValue ?
                                            (FLOAT)utempVal64: (FLOAT)tempVal64);
            if (*((FLOAT *)targetDataPtr) = (unsignedValue ?
                                            (FLOAT)utempVal64: (FLOAT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(FLOAT); 
            break;

        case SQL_C_DOUBLE:
            *((SQLDOUBLE*)targetDataPtr) = (unsignedValue ?
                                                (SQLDOUBLE)utempVal64: (SQLDOUBLE)tempVal64);
            if (*((SQLDOUBLE*)targetDataPtr) = (unsignedValue ?
                                            (SQLDOUBLE)utempVal64: (SQLDOUBLE)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLDOUBLE); 
            break;

        default:
			return IDS_07_006;
    }

    return retCode;
}
