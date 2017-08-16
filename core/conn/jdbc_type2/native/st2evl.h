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
#ifndef ST2EVL_H
#define ST2EVL_H
#include "zt2c.h"

typedef struct EVENTDATA_TABLE
{
   DWORD eventId;
   char* msgPtr[10];
} EVENTDATA_TABLE;

/*------------------------------------------------------------------------------
 When transferring these messages over from ems/smxotmpl, tokens 1, 2 and 3 are
 reserved for Event Type, component Name and Object Reference. 99% of the
 messages fit in this category. These token are labelled as:

 Token
 ---------------------
 Event Type        <1>
 Component Name    <2>
 Object Reference  <3>

 All remaining tokens must begin with <4>, <5> ... <n>

Therefore any messages that do NOT use tokens alll three of the first three
tokens, will have a gap in the numbering scheme, i.e

{ZMXO_EVT_COLLECTOR_ERROR,
   "ODBC/MX server failed to write to <7> collector due to error <5>. \n",
   "Session ID: <4>\n",


   "Error Message: <6>\n",
   "Collector Name: <8>\n",
   NULL, NULL, NULL, NULL },

In this case, Event Type is not in the message, so token <1> is not used

------------------------------------------------------------------------------*/

EVENTDATA_TABLE eventDataMap[] =
{
//  eventId, msgPtr1-msgPtr10 ...

{JDBCT2_TEST_ERROR,
"Jdbct2 message error test!. \n",

/*---------------------------------------------------
---------------------------------------------------*/
    NULL, NULL, NULL, NULL, NULL, NULL },

{JDBCT2_TEST_SUCCESS,
"Jdbct2 message success test!. \n",

/*---------------------------------------------------
---------------------------------------------------*/
    NULL, NULL, NULL, NULL, NULL, NULL },



//SIGNALS END OF ARRAY, DO NOT REMOVE
{0L, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
 };

#endif
