//
//  CompressedData.cpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

#include "CompressedData.hpp"
#include <fstream>
#include <iostream>

CompressedData::CompressedData(const std::string& location)
: location_(location)
, meta_(std::make_shared<Metadata>())
{
    ExtractData();
}

void CompressedData::ExtractData() {
    std::ifstream file(location_);
    if(!file.is_open()) {
        std::cerr << "Couldn't open the file: " << location_ << std::endl;
        meta_->error_ = true;
        return;
    }
    
    meta_->decoded_ = true;
    
//    images_.emplace_back(std::make_shared<Image>());
    
}

std::pair<std::shared_ptr<Metadata>, std::vector<std::shared_ptr<Image>>> CompressedData::GetData() {
    return std::make_pair(meta_, images_);
}
