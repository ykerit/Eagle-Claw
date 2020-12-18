#pragma once

#ifdef EGC_PLATFORM_WINDOWS
#ifdef EGC_BUILD_DLL
#define EGC_API __declspec(dllexport)
#else
#define EGC_API __declspec(dllimport)
#endif
#else
#error EagleClaw only support Windows!
#endif

#define EGC_ASSERT(x) \
  if (!(x))           \
    __debugbreak();