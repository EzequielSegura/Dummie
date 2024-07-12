#ifndef IMAGE_H
#define IMAGE_H

#undef min
#define myMin(a, b) (((a) < (b)) ? (a) : (b))

#include <iostream>
#include <cstdint>
#include <vector>

/* To use LodePNG */
#include <lodepng.h>

class Image
{
private:
    /* Text */
    int textWidth = 10;
    int textHeight = 20;
    int textPadding = 10;
    int fontColor[3] = {255,255,255};

    /* Images */
    std::vector<int> imagePixelBuffer;
    unsigned int imgWidth, imgHeight;

public:
    /* Temporal , creo*/
    void setFont(std::string filename);
    void setFontColor(int r, int g, int b);
    void setTextSize(int width, int height);
    void setTextPadding(int padding);
    void typeChar(char type, int x, int y);
    void text(const std::string& text, int x, int y);

    void showPartialImageScaledColored(int posX, int posY, int x, int y, int width, int height, int newWidth, int newHeight);
    void loadImage(const std::string filename);
    void LoadPixels(int* matrix);
    void showImage(int posX, int posY);
    void showPartialImage(int posX, int posY, int x, int y, int width, int height);
    void showPartialImageScaled(int posX, int posY, int x, int y, int width, int height, int newWidth, int newHeight);

    uint32_t RGBToHex(int r, int g, int b);
    void HexToRGB(uint32_t hexValue, int& r, int& g, int& b);
};


#endif