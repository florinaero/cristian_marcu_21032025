//
//  Image.hpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

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
