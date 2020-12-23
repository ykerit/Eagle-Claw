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
    if (!(x))         \
        __debugbreak();

#define EGC_ASSERT_MSG(condition, message)                                                                              \
    do                                                                                                                  \
    {                                                                                                                   \
        if (!(condition))                                                                                               \
        {                                                                                                               \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " << __LINE__ << ": " << message \
                      << std::endl;                                                                                     \
            std::terminate();                                                                                           \
        }                                                                                                               \
    } while (false)

#define GLCALL(x)                                     \
    {                                                 \
        GLClearError();                               \
        x;                                            \
        EGC_ASSERT(GLLogCall(#x, __FILE__, __LINE__)) \
    }

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);