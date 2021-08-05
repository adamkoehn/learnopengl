#include "manager/Window.h"

int main(int argc, char *argv[])
{
    Manager::Window *window = Manager::Window::instance();
    if (window->isReady())
    {
        window->loop();
    }

    return 0;
}