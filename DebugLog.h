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
      void SetStream(const LogLevel level, std::ostream &stream);
      std::ostream& GetStream(const LogLevel level);
      std::ostream& operator[](const LogLevel level);
      
    private:
      LevelToStreamMap map;
      std::ostream nullstream;

  };
}

#define DEBUG_ID __FILE__ << __LINE__

#endif
