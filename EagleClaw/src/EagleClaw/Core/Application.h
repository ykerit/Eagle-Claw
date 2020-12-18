#pragma once

#include "Core.h"

namespace EagleClaw {
	class Application {
	public:
		Application();

		~Application();

		void Run();
	};

	Application* CreateApplication();
}