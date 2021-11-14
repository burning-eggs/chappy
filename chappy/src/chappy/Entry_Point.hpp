#pragma once

#ifdef CP_WINDOWS

extern chappy::Application* chappy::createApplication();

int main(int argc, char** argv) {
    chappy::Log::Init();
    CP_INFO("Initialized Log.");

    auto app = chappy::createApplication();
    
    app->run();
    delete(app);
}

#endif