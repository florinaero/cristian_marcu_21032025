//
//  ImageDecoder.cpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

#include "ImageDecoder.hpp"

std::pair<std::shared_ptr<Metadata>, std::shared_ptr<Image>> ImageDecoder::DecodeImage(std::shared_ptr<Image> encoded_image) {
    auto meta = std::make_shared<Metadata>();
    meta->decoded_ = true;
    
    // Encode the image and return the pointer
    
    return std::make_pair(meta, encoded_image);
    
}
