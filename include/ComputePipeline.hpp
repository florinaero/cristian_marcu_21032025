//
//  ComputePipeline.hpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

#ifndef ComputePipeline_hpp
#define ComputePipeline_hpp

#include "CompressedData.hpp"
#include "Image.hpp"
#include <stdio.h>
#include <string_view>
#include <string>
#include <vector>

struct JSONData {
    std::string name_;
    std::string type_;
    std::string path_;
    std::string creation_date_;
    bool        compressed_;
    int size_;
    int files_number_;
};


/**
 * @class ComputePipeline
 * @brief This class decides the action types and runs them based on the file type.
 *
 */
class ComputePipeline {
public:
    /**
     * @brief Check for valid uir based on the prefix and also check for a valid file extension
     *
     * @param[in] uri       Input path
     * @return          True if the prefix and extension are correct.
     */
    bool LoadUri(std::string_view uri);
    
    /**
     * @brief Based on the file type of the uri it will be decided the content of the pipeline \n
     *                 sequence: JSON -> Decompress Data -> Decode Images
     *
     * @return False in case an operation fails
     */
    bool ExecutePipeline();
    
    std::vector<std::pair<std::shared_ptr<Metadata>, std::shared_ptr<Image>>> GetImages() const {
        return images_;
    }
    ComputePipeline();
private:
    enum class FileType {
        Invalid,
        Image,
        Compressed,
        Json
    };
    std::string uri_type_;
    std::string uri_;
    FileType file_type_;
    std::shared_ptr<CompressedData> ptr_compressed_;
    std::vector<std::pair<std::shared_ptr<Metadata>, std::shared_ptr<Image>>> images_;
    std::vector<std::string> uri_types_str_ = {"file://", "http://", "https://"
                                        ,  "bundle://"};
    std::vector<std::string> images_extensions_ = {".png", ".jpeg", ".tiff"};
    std::vector<std::string> compress_extensions_ = {".zip", ".rar", ".gz"};
    

    
    /**
     * @brief Read the JSON file and search for the relevant parameters
     *
     * @return Return false if the JSON doesn't contain all the necessary parameters
     */
    std::optional<JSONData> ParseJSON();
    bool DecompressData(const std::string& data_path = "");
    void DecodeImages(const std::string& data_path = "");
    
};
#endif /* ComputePipeline_hpp */
