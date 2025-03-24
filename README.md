# cristian_marcu_21032025

This SDK is designed to read an uri and then process the data(images) found at the location. 
Based on the extension of the file next scenarios for the pipeline are considred:

1. JSON file: File is parsed and is looking for the compressed field. If the data is compressed next step is to uncompress the data and then to decode the images. If data is not compressed it means that the images could run through the decoding phase.
   JSON -> UNCOMPRESS DATA -> DECODE IMAGES
   JSON -> DECODE IMAGES

2. Compressed Data: Data must be uncompressed and then images are decoded.
   UNCOMPRESS DATA -> DECODE IMAGES

3. ENCODED IMAGES: Images are decoded
   DECODE IMAGES

## Structure of the SDK

- **CompressedData Class**  
  Extracts data from a specified location, decompresses it, and generates a metadata file.

- **ImageDecoder Class**  
  Decodes images and creates a metadata file for each image.

- **ComputePipeline Class**  
  Defines the processing pipeline and makes decisions based on the output of each action.

- **Metadata Struct**  
  Contains metadata fields applicable to both compressed data and images.

- **Image Class**  
  Represents an image entity within the SDK.


   
