#include <memory>

#include "renderer/SimpleTriangleRenderer.h"

int main()
{
    std::unique_ptr<SimpleTriangleRenderer> app = std::make_unique<SimpleTriangleRenderer>();
    app->run();
    return 0;
}
