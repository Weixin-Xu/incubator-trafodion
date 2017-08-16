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
********************************************************************/
//****************************************************************************
//*
//*  Header of the Messages file
//*
//****************************************************************************
//* MessageIdTypeDef = A symbolic name that is output as the typedef name
//* for each numeric MessageId value
//* SeverityNames = Two most significant bits in the MessageId which define
//* the type of message
//* FacilityNames = Defines the set of names that are allowed as the value
//* of the Facility keyword
//			Application=0xFFF
//* LanguageNames = Defines the set of names that are allowed as the value
//* of the language keyword.  It maps to the message file for that language
//LanguageNames=(USEnglish=9:tdm_odbcSrvrMsg_009)
//**** end of header section; what follows are the message definitions *****
//*
//*  All error message definitions start with the keyword "MessageId"
//*  if no value is specified, the number will be the last number used for the
//*  facility plus one.  Instead of providing a number, we can provide +NUMBER
//*  where number is the offset to be added to the last number used in
//*  the facility
//*  MessageId numbers are limited to 16 bit values
//*
//*  Severity and Facility if not specified will use the last option selected
//*  the names used must match the names defined in the header
//*
//*  SymbolicName is a symbols used to associate a C symbolic ocnstant name
//*  with the final 32-bit message code that is the result of ORing together
//*  the MessageId | Severity | Facility bits.  The constant definition is
//*  output in the generated .h file
//*
//*  After the message definition keywords comes one or more message text
//*  definitions.  Each message text definition starts with the "Language"
//*  keyword that identifies which binary output file the message text is
//*  to be output to.  The message text is terminated by a line containing
//*  a single period at the beginning of the line, immediately followed by
//*  a new line.  No spaces allowed around keyword.  Within the message text,
//*  blank lines and white space are preserved as part of the message.
//*
//*  Escape sequences supported in the message text:
//*    %0 - terminates a message text line without a trailing new line
//*        (for prompts)
//*    %n!printf format string! - Identifies an insert (parameter);
//*         n can be between 1 and 99; defaults to !s!
//*  Inserts refer to parameters used with FormatMessage API call,
//*    if not passed, an error is generated
//*    %% - a single percent sign
//*    %n - a hard line break
//*    %r - output a hard carriage return
//*    %b - space in the formatted message text
//*    %t - output a tab
//*    %. - a single period
//*    %! - a single exclamation point
//*
//*
//*  Values are 32 bit values layed out as follows:
//*
//*   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//*   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//*  +---+-+-+-----------------------+-------------------------------+
//*  |Sev|C|R|     Facility          |               Code            |
//*  +---+-+-+-----------------------+-------------------------------+
//*
//*  where
//*
//*      Sev - is the severity code
//*
//*          00 - Success
//*          01 - Informational
//*          10 - Warning
//*          11 - Error
//*
//*      C - is the Customer code flag
//*
//*      R - is a reserved bit
//*
//*      Facility - is the facility code
//*
//*      Code - is the facility's status code
//*
//*************************************************************************
//*
//*      Actual Messages follow this line and have the following
//*      structure:
//*          Characters 1 to 5  of the Msg Text will contain SQLState
//*          Characters 7 to 10 of the Msg Text will contain a Help ID number
//*          Characters from 11 to the end of the Msg Text will contain the text
//*
//*************************************************************************
//************************************************************************
//*
//*           Server Component messages from the string table
//*
//************************************************************************
//************************************************************************
//*
//*	MessageId:	CFG_CANNOT_DROP_DEFAULT_DSN(1)
//*	Severity:	Error
//*	Cause:
//*	Effect:
//*	Recovery:
//*
//************************************************************************
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//

//



/**********************ERROR   START ********************************/

//
// MessageId: JDBC_TYPE2_TEST_ERROR
//
// MessageText:
//
//  zzzzz zzzzz Test jdbc_type2 error event message
//
#define JDBC_TYPE2_TEST_ERROR     ((DWORD)0xC0005208L)

/**********************SUCCESS START ********************************/


//
// MessageId: JDBC_TYPE2_TEST_SUCCESS
//
// MessageText:
//
//  zzzzz zzzzz Test jdbc_type2 success event message
//
#define JDBC_TYPE2_TEST_SUCCESS     ((DWORD)0x00007918L)

