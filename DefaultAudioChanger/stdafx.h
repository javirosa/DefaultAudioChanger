// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		 _WIN32_WINNT_WIN7 
#define _WIN32_WINNT _WIN32_WINNT_WIN7 
#define _WIN32_IE	_WIN32_IE_IE80
#define NTDDI_VERSION NTDDI_WIN7

//#define WIN32_LEAN_AND_MEAN

#define _WTL_USE_CSTRING

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlutil.h>
#include <atlmisc.h>
#include <atlcrack.h>
#include <atlctrlw.h>
#include <atltheme.h>
#include <atlctrlx.h>
#include "Aero.h"

#include <Mmdeviceapi.h>
#include "PolicyConfig.h"
#include <Propidl.h>
#include <Functiondiscoverykeys_devpkey.h>

#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
