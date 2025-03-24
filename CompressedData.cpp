/**
 * @file CompressedData.cpp
 * @brief Implements the CompressedData class for handling compressed file extraction.
 *
 * This file contains the implementation of the CompressedData class, which is responsible
 * for extracting data from compressed files and managing metadata.
 *
 * @author cristi
 * @date 21.03.2025
 */

#include "CompressedData.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief Constructs a CompressedData object and initializes extraction.
 *
 * @param[in] location The file path of the compressed data.
 */
CompressedData::CompressedData(const std::string& location)
: location_(location)
, meta_(std::make_shared<Metadata>())
{
    ExtractData();
}

/**
 * @brief Extracts data from the compressed file.
 *
 * Opens the file and sets metadata flags based on extraction success.
 */
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

/**
 * @brief Retrieves extracted metadata and image data.
 *
 * @return A pair containing metadata and a vector of extracted images.
 */
std::pair<std::shared_ptr<Metadata>, std::vector<std::shared_ptr<Image>>> CompressedData::GetData() {
    return std::make_pair(meta_, images_);
}
