/**
 * @file Metadata.hpp
 * @brief Declares the Metadata struct for storing metadata information.
 *
 * This file defines the `Metadata` struct, which holds basic metadata information
 * about a file or image, including its size, status flags, and type.
 *
 * @author cristi
 * @date 21.03.2025
 */

#ifndef Metadata_h
#define Metadata_h

struct Metadata {
    int size_ = 0;
    bool error_ = false;
    bool decoded_ = true;
    std::string name_ = "";
    std::string type_ = "";
};
#endif /* Metadata_h */
