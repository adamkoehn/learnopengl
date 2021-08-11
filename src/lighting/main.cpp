#include "../scene/Lighting.h"
#include "../manager/Window.h"

int main(int argc, char *argv[])
{
    Scene::Lighting *lighting;

    Manager::Window *window = new Manager::Window();
    if (window->isReady())
    {
        lighting = new Scene::Lighting();
        window->setScene(lighting);
        window->loop();
    }
    delete window;

    return 0;
}