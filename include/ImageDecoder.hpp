//
//  ImageDecoder.hpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

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
