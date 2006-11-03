//---------------------------------------------------------------------------

#ifndef debugH
#define debugH
//---------------------------------------------------------------------------
#include <ostream>
#include <sstream>
#include <map>

// Globally defined debug logging constant ENABLE_LOG_DEBUG

namespace DoxEngine
{
  typedef std::stringstream NullStream;

  enum LogLevel
  {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
  };


  typedef  std::map<LogLevel, std::ostream*> LevelToStreamMap;

  class DebugLog
  {
    public:
      DebugLog();
      DebugLog(const DebugLog &rhs);
      ~DebugLog();
      DebugLog& operator=(const  DebugLog &rhs);

      // Note: DebugLog does not take ownership or copy of stream
      void SetStream(LogLevel level, std::ostream &stream);
      std::ostream& GetStream(LogLevel level);
      std::ostream& operator[](LogLevel level);
      
    private:
      LevelToStreamMap map;
      NullStream defaultStream;

  };
}

#define DEBUG_ID __FILE__ << __LINE__

#endif
