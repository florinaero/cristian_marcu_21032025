/**
 * @file Image.hpp
 * @brief Declares the Image class for representing an image object.
 *
 * This file defines the `Image` class, which holds the image data for a single image object.
 *
 * @author cristi
 * @date 21.03.2025
 */

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>

#include <memory>
#include <string>
#include <vector>

class Image {
private:
    std::string name_;
    std::string size_;
    std::vector<uint32_t> data_;
};

#endif /* Image_hpp */
