//
//  CompressedData.hpp
//  cristian_marcu_21032025
//
//  Created by cristi on 21.03.2025.
//

#ifndef CompressedData_hpp
#define CompressedData_hpp

#include "Image.hpp"
#include "Metadata.hpp"
#include <stdio.h>
#include <memory>
#include <vector>

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
    CompressedData(const std::string& location);
    
    std::pair<std::shared_ptr<Metadata>, std::vector<std::shared_ptr<Image>>> GetData();
};
#endif /* CompressedData_hpp */
