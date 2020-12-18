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

// opengl base util
#include <Glad/glad.h>

#define ASSERT(x) \
  if (!(x))       \
    __debugbreak();
#define GLCALL(x)                             \
  {                                           \
    GLClearError();                           \
    x;                                        \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) \
  }

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);