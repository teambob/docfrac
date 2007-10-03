#ifndef __TSTRING_H__
#define __TSTRING_H__

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

#include <string>
#include <vector>

typedef std::basic_string<wxChar> tstring;
typedef std::vector<tstring> tstringVector;


#endif
