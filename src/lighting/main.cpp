#include "../manager/Window.h"

int main(int argc, char *argv[])
{
    Manager::Window *window = Manager::Window::instance();
    if (window->isReady())
    {
        // window->setScene();
        // window->setShader();
        window->loop();
    }

    Manager::Window::destroy();
    return 0;
}