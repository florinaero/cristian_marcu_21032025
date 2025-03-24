/**
 * @file CompressedData.hpp
 * @brief Declares the CompressedData class for handling compressed file extraction.
 *
 * This file defines the CompressedData class, which is responsible
 * for extracting data from compressed files and managing metadata.
 *
 * @author cristi
 * @date 21.03.2025
 */

#ifndef CompressedData_hpp
#define CompressedData_hpp

#include "Image.hpp"
#include "Metadata.hpp"
#include <stdio.h>
#include <memory>
#include <vector>

/**
 * @class CompressedData
 * @brief Manages the extraction of compressed data.
 */
class CompressedData {
private:
    std::string location_;
    std::vector<std::shared_ptr<Image>> images_;
    std::shared_ptr<Metadata> meta_;
    
    /**
    * @brief Reading from path and uncompress the data and store it for further usage
    */
    void ExtractData();
    
public:
    /**
     * @brief Constructs a CompressedData object and initializes extraction.
     *
     * @param location The file path of the compressed data.
     */
    CompressedData(const std::string& location);
    
    std::pair<std::shared_ptr<Metadata>, std::vector<std::shared_ptr<Image>>> GetData();
};
#endif /* CompressedData_hpp */
