#pragma once

#include "Application.hpp"

#ifdef CP_WINDOWS

extern chappy::Application* chappy::createApplication();

int main(int argc, char** argv) {
    auto app = chappy::createApplication();
    
    app->run();
    delete(app);
}

#endif