/**
 * @file ImageDecoder.cpp
 * @brief This file implements the image decoding functionality.
 *
 * @author cristi
 * @date 21.03.2025
 */

#include "ImageDecoder.hpp"

/**
 * @brief Decode image.
 *
 * @param[in] encoded_image Shared Pointer to the encoded image
 * @return Pair of the decoded image and metadata
 */
std::pair<std::shared_ptr<Metadata>, std::shared_ptr<Image>> ImageDecoder::DecodeImage(std::shared_ptr<Image> encoded_image) {
    auto meta = std::make_shared<Metadata>();
    meta->decoded_ = true;
    
    // Encode the image and return the pointer
    return std::make_pair(meta, encoded_image);
    
}
