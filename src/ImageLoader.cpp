//
// Created by Jun on 2025/4/11.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image_custom.h"

#include "ImageLoader.hpp"
#include <stdexcept>

ImageLoader::ImageLoader(const std::string& filepath) {
    int channels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 4);
    if (!data) {
        throw std::runtime_error("Failed to load image: " + filepath);
    }

    pixels.assign(data, data + (width * height * 4));
    stbi_image_free(data);
}

bool ImageLoader::IsPixelOpaque(int x, int y) const {
    if (x < 0 || y < 0 || x >= width || y >= height) return false;
    int index = (y * width + x) * 4;
    return pixels[index + 3] != 0;  // Alpha != 0 表示不透明
}
