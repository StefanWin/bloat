#include <memory>

#include "App.h"

int main()
{
    std::unique_ptr<App> app = std::make_unique<App>();
    app->render();
    return 0;
}
