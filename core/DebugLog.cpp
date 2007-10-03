//---------------------------------------------------------------------------


#include "DebugLog.h"

//---------------------------------------------------------------------------



namespace DoxEngine
{

   // basic_ostream::basic_ostream(NULL) generates a NULL stream
   DebugLog::DebugLog():nullstream(NULL)
   {

   }

   // basic_ostream::basic_ostream(NULL) generates a NULL stream   
   DebugLog::DebugLog(const DebugLog &rhs):nullstream(NULL)
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
  void DebugLog::SetStream(const LogLevel level, std::ostream &stream)
  {
    map.insert(LevelToStreamMap::value_type(level, &stream));
  }

  std::ostream& DebugLog::GetStream(const LogLevel level)
  {
    LevelToStreamMap::iterator streamIterator = map.find(level);
    if (streamIterator != map.end())
      return *(streamIterator->second);
    else
      return nullstream;

  }

  std::ostream& DebugLog::operator[](const LogLevel level)
  {
    return GetStream(level);
  }





}
