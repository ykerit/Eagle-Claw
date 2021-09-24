#pragma once

#include <cstdint>

namespace GRender {

class Assets
{
public:
    enum AssetsCategory
    {
        SHADERS,
        TEXTURE,
        SCRIP
    };

public:
    Assets() {}

private:
    int64_t assert_id_;
    
};

} // namespace GRender