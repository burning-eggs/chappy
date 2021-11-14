#pragma once

#include "API.hpp"

namespace chappy {
	class CP_API Application {
	public:
		Application();
		~Application();

		void run();
	};

	/* Defined in Client */
	Application* createApplication();
}