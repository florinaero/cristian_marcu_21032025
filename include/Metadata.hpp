//
//  Metadata.hpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

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
