#include <Chappy.hpp>

class App : public chappy::Application {
public:
    App() {}

    ~App() {}
};

chappy::Application* chappy::createApplication() {
    return new App;
}