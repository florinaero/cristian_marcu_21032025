/**
 * @file main.cpp
 * @brief This file contains the main entry point of the program.
 *
 *  This program is designed to run an image processing pipeline that can branch according to the input.
 *
 * @return int 0 = SUCCESS, non-zero otherwise
 *
 * @author cristi
 * @date 21.03.2025
 */

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
