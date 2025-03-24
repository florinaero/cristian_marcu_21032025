/**
 * @file ImageDecoder.hpp
 * @brief Declares the ImageDecoder class for decoding image data.
 *
 * This file defines the `ImageDecoder` class, which is responsible for decoding
 * image data from an encoded format into a usable `Image` object.
 *
 * @author cristi
 * @date 21.03.2025
 */
#ifndef ImageDecoder_hpp
#define ImageDecoder_hpp

#include "Image.hpp"
#include "Metadata.hpp"
#include <stdio.h>

class ImageDecoder {
public:
    std::pair<std::shared_ptr<Metadata>, std::shared_ptr<Image>> DecodeImage(std::shared_ptr<Image> encoded_image);
};
#endif /* ImageDecoder_hpp */
