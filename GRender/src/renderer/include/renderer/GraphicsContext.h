#pragma once

#include <memory>
#include "core/Log.h"

namespace GRender {
class GraphicsContext
{
public:
    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;

    static std::unique_ptr<GraphicsContext> Create(void *window);
};

} // namespace GRender