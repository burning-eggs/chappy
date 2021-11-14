#pragma once

#ifdef CP_WINDOWS
#ifdef CHAPPY
#define CP_API _declspec(dllexport)
#else
#define CP_API _declspec(dllimport)
#endif // CHAPPY
#else
#error Currently only Windows is supported.
#endif // CP_WINDOWS
