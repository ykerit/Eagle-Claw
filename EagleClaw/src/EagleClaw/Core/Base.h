#pragma once

#include <iostream>

#define EGC_ASSERT(x) assert(x);

#define EGC_ASSERT_MSG(condition, message)                                                                              \
    do                                                                                                                  \
    {                                                                                                                   \
        if (!(condition))                                                                                               \
        {                                                                                                               \
            std::cerr << "Assertion `" #condition "` failed in: " << __FILE__ << " line: " << __LINE__ << ": " << message \
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

#define BIND_EVENT_FUNC(func) \
    [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }
