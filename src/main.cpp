
#include <memory>

#include "renderer/ImageRendererNV.h"

int main()
{
    std::unique_ptr<ImageRendererNV> app = std::make_unique<ImageRendererNV>();
    app->run();
    return 0;
}
