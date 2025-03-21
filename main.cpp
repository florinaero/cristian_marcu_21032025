#include "ComputePipeline.hpp"

int main() {
    auto pipeline = std::make_unique<ComputePipeline>();
    if (pipeline->LoadUri("https://something.JSON")) {
        bool result = pipeline->ExecutePipeline();
        if (result) {
            auto imgs = pipeline->GetImages();
        }
    }
    
}
