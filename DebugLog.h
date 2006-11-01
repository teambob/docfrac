//---------------------------------------------------------------------------

#ifndef debugH
#define debugH
//---------------------------------------------------------------------------
#include <ostream>
#include <vector>

namespace DoxEngine
{
  enum
  {
    DEBUG_DEBUG,
    DEBUG_INFO,
    DEBUG_WARNING,
    DEBUG_ERROR
  };

  typedef std::vector<std::ostream*> DebugLog;
}

#define DEBUG_ID __FILE__ << __LINE__

#endif
