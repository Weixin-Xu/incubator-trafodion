//===============================================================================================
// @@@ START COPYRIGHT @@@
// //
// // Licensed to the Apache Software Foundation (ASF) under one
// // or more contributor license agreements.  See the NOTICE file
// // distributed with this work for additional information
// // regarding copyright ownership.  The ASF licenses this file
// // to you under the Apache License, Version 2.0 (the
// // "License"); you may not use this file except in compliance
// // with the License.  You may obtain a copy of the License at
// //
// //   http://www.apache.org/licenses/LICENSE-2.0
// //
// // Unless required by applicable law or agreed to in writing,
// // software distributed under the License is distributed on an
// // "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// // KIND, either express or implied.  See the License for the
// // specific language governing permissions and limitations
// // under the License.
// //
// // @@@ END COPYRIGHT @@@
// // ===============================================================================================

#include "PubInterface.h"
#include "st2evl.h"
#include "CommonLogger.h"

#define MAX_EVT_BUF_SIZE 1024
#define MS_MON_MAX_PROCESS_NAME 1024

static std::string T2_COMPONENT = "JAVAT2";

inline bool findString(char *p, int *idx, string msg)
{
   *idx = msg.find(p);
   if (*idx == string::npos)
   {
      return false;
   }
   return true;
   ;
}


void send_to_eventlog (short evt_num, short EventLogType, char *ComponentName, char *ObjectRef, short nToken, va_list marker)
{
    BOOL    found = FALSE;
    short    i,j;
    int err, tokIdLen, idx;
    char *TokenPtr;
    char *tmpBuf;
    size_t szBuf = MAX_EVT_BUF_SIZE;
    logLevel severity;
    string logMsg;
    logMsg.reserve(MAX_EVT_BUF_SIZE);

    MEMORY_ALLOC_ARRAY(tmpBuf, char, MS_MON_MAX_PROCESS_NAME + 64);

    for (i = 0, found = FALSE; eventDataMap[i].eventId != 0L ; i++)
    {
        if (eventDataMap[i].eventId == evt_num)
        {
           found = TRUE;
           //sprintf(tmpBuf, "%.30s (%d,%d): %ld ",process_name, nid, pid, getLongEventId(1, SQEVL_NDCS, evt_num, 9));
           sprintf(tmpBuf, " PIN:%ld, , , ,", getpid());
           logMsg.append(tmpBuf);
           for (j=0;eventDataMap[i].msgPtr[j] !=NULL || j>6 ;j++ )
           {
              logMsg.append(eventDataMap[i].msgPtr[j]);
           }
           break;
        }
   }
   if (!found)
   {
       stringstream ss("ODBCMXEventMsg::send_to_eventlog: eventDataMap entry not found ");
       throw(ss.str()) ;
   }

   _itoa(EventLogType, tmpBuf, 10);

//   if (findString("<1>",&idx, logMsg))
//      logMsg.replace( logMsg.find("<1>"), 3, tmpBuf );
//   if (findString("<2>",&idx, logMsg))
//      logMsg.replace( logMsg.find("<2>"), 3, ComponentName );
//   if (findString("<3>",&idx, logMsg))
//      logMsg.replace( logMsg.find("<3>"), 3, ObjectRef );

   for ( i=0,j=4; i<nToken; i++,j++ )
   {
       TokenPtr = va_arg(marker, char *);
       //errno = strstr(TokenPtr, "4126");
       tokIdLen = sprintf(tmpBuf,"<%d>",j);
       if (!findString(tmpBuf,&idx, logMsg))
          logMsg.append( TokenPtr );
       else
           logMsg.replace( idx, tokIdLen, TokenPtr );
   }
   va_end(marker);

   const char *logMsgStr = logMsg.c_str();

   switch (EventLogType)
   {
   case EVENTLOG_ERROR_TYPE:
      severity = LL_ERROR;
      break;
   case EVENTLOG_WARNING_TYPE:
      severity = LL_WARN;
      break;
   case EVENTLOG_INFORMATION_TYPE:
      severity = LL_INFO;
      break;
   default:
      severity = LL_ERROR;
   }


   MEMORY_DELETE_ARRAY(tmpBuf);
   CommonLogger::log(T2_COMPONENT, severity, logMsgStr);

}

void SendEventMsg(DWORD EventId, short EventLogType, DWORD Pid, char *ComponentName,
            char *ObjectRef, short nToken, ...){
    va_list marker;
    va_start( marker, nToken);

	send_to_eventlog(EventId & 0x0FFFF, EventLogType, ComponentName, ObjectRef, nToken, marker);

	va_end(marker);

	return;
}


