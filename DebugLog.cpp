//---------------------------------------------------------------------------


#pragma hdrstop

#include "DebugLog.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace DoxEngine
{
   DebugLog::DebugLog()
   {

   }

   DebugLog::DebugLog(const DebugLog &rhs):defaultStream()
   {
     map = rhs.map;
   }

   DebugLog::~DebugLog()
   {

   }

   DebugLog& DebugLog::operator=(const DebugLog &rhs)
   {
     if (this == &rhs)
       return *this;
       
     map = rhs.map;
     return *this;
   }

  // Note: DebugLog does not take ownership or copy of stream
  void DebugLog::SetStream(LogLevel level, std::ostream &stream)
  {
    map.insert(LevelToStreamMap::value_type(level, &stream));
  }

  std::ostream& DebugLog::GetStream(LogLevel level)
  {
    LevelToStreamMap::iterator streamIterator = map.find(level);
    if (streamIterator != map.end())
      return *(streamIterator->second);
    else
      return defaultStream;

  }

  std::ostream& DebugLog::operator[](LogLevel level)
  {
    return GetStream(level);
  }





}
