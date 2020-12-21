#pragma once

#ifdef EGC_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See
// github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "EagleClaw/Core/Base.h"
#include "EagleClaw/Core/Log.h"

#ifdef EGC_PLATFORM_WINDOWS
#include <Windows.h>
#endif
