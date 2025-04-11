    //
// Created by Jun on 2025/4/11.
//

#ifndef IMAGELOADER_HPP
#define IMAGELOADER_HPP

#pragma once

#include <vector>
#include <string>

class ImageLoader {
public:
    int width = 0;
    int height = 0;
    std::vector<unsigned char> pixels;  // RGBA 格式，每像素 4 bytes

    explicit ImageLoader(const std::string& filepath);

    bool IsPixelOpaque(int x, int y) const;
};

#endif //IMAGELOADER_HPP
