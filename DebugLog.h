//---------------------------------------------------------------------------

#ifndef debugH
#define debugH
//---------------------------------------------------------------------------
#include <ostream>
#include <vector>

namespace DoxEngine
{
  typedef vector<ostream*> Debug;
}

#define DEBUG_ID __FILE__ << __LINE__

#endif
