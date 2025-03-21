//
//  ComputePipeline.cpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

#include "ComputePipeline.hpp"
#include "CompressedData.hpp"
#include "ImageDecoder.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>


ComputePipeline::ComputePipeline()
: file_type_(FileType::Invalid) {
    uri_types_str_ = {"file://", "http://", "https://", "bundle://"};
    images_extensions_ = {".png", ".jpeg", ".tiff"};
    compress_extensions_ = {".zip", ".rar", ".gz"};
}

bool ComputePipeline::LoadUri(std::string_view uri) {
    bool valid = false;
    
    for (const auto& el : uri_types_str_) {
        if (uri.starts_with(el)) {
            uri_type_ = el;
            valid = true;
            break;
        }
    }
    
    if (valid == false) {
        return false;
    }
    
    // Identify the type of the file
    std::filesystem::path uri_path(uri);
    if (uri_path.has_extension()) {
        auto extension = uri_path.extension();
        auto ext_str = extension.string();
        if (ext_str == ".JSON" || ext_str == ".json") {
            file_type_ = FileType::Json;
            return true;
        }
        for (const auto& el : images_extensions_) {
            if (ext_str == el) {
                file_type_ = FileType::Image;
                return true;
            }
        }
        for (const auto& el : compress_extensions_) {
            if (ext_str == el) {
                file_type_ = FileType::Compressed;
                return true;
            }
        }
    }
    uri_ = std::string(uri);
    
    // Find the type of file by extracting the extension
    return false;
}


std::optional<JSONData> ComputePipeline::ParseJSON() {
    std::ifstream file(uri_);
    JSONData result;
    
    if (!file.is_open()) {
        std::cerr << "Couldn't open the file: " << uri_ << std::endl;
        return std::nullopt;
    }
    
    // Could parse the json with nlohmann::json, for the moment I m hardcoding some values
    result.creation_date_ = "21032025";
    result.name_ = "image_lib";
    result.path_ = "/images";
    result.type_ = "PNG";
    result.size_ = 1024;
    result.files_number_ = 10;
    
    return result;
}


void ComputePipeline::DecodeImages(const std::string& data_path) {
    // Images have been uncompressed and are stored in a vector
    
    ImageDecoder decoder;
    
    if (data_path.empty()) {
        for (const auto& el : ptr_compressed_->GetData().second) {
            images_.emplace_back(decoder.DecodeImage(el));
        }
    }
    else {
        std::filesystem::path location = data_path;
        if (std::filesystem::exists(data_path)) {
            if(std::filesystem::is_directory(location)) {
                for (const auto& file : std::filesystem::directory_iterator(location)) {
                    // Suppose a read function for the image
                    auto file_image = std::make_shared<Image>();
                    images_.emplace_back(decoder.DecodeImage(file_image));
                }
            }
            else {
                auto file_image = std::make_shared<Image>();
                images_.emplace_back(decoder.DecodeImage(file_image));
            }
        }
    }
}

bool ComputePipeline::DecompressData(const std::string& data_path) {
    
    if (!data_path.empty()) {
        return false;
    }
    
    ptr_compressed_ = std::make_shared<CompressedData>(data_path);
    if (ptr_compressed_->GetData().first->error_) {
        return false;
    }
    
    return true;
}


bool ComputePipeline::ExecutePipeline() {
    JSONData json_obj;
    
    if (file_type_ == FileType::Json) {
        auto obj = ParseJSON();
        if (obj.has_value() == false) {
            return false;
        }
        else {
            json_obj = obj.value();
        }
        // Decompress the data found at the location pointed by the json
        if (json_obj.compressed_) {
            bool res = DecompressData(json_obj.path_);
            if (!res)  {
                return false;
            }
            DecodeImages();
        }
        else {
            DecodeImages(uri_);
        }
       
        
    }
    
    if (file_type_ == FileType::Compressed) {
        bool res = DecompressData(uri_);
        if (!res)  {
            return false;
        }
        DecodeImages();
    }
    
    if (file_type_ == FileType::Image) {
        DecodeImages(uri_);
    }
    
    return true;
}
