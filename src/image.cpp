#include <image.h>
#include <graphics.h>

// Load a image in a buffer
void Image::loadImage(const std::string filename) {
    std::vector<unsigned char> image;

    unsigned error = lodepng::decode(image, imgWidth, imgHeight, filename);

    if (error) {
        std::cout << "Error al cargar la imagen: " << lodepng_error_text(error) << std::endl;
        return;
    }

    imagePixelBuffer.clear(); // Clear any previous data

    for (size_t i = 0; i < image.size(); i += 4) {
        unsigned char r = image[i];
        unsigned char g = image[i + 1];
        unsigned char b = image[i + 2];

        imagePixelBuffer.push_back(r); // Red
        imagePixelBuffer.push_back(g); // Green
        imagePixelBuffer.push_back(b); // Blue
    }
}

// Save the pixel data in a matrix
void Image::LoadPixels(int* matrix){
    int index = 0;
    int matrixIndex = 0;

    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            int r = imagePixelBuffer[index++];
            int g = imagePixelBuffer[index++];
            int b = imagePixelBuffer[index++];

            int HexaValue = RGBToHex(r,g,b);

            matrix[matrixIndex] = HexaValue;
            matrixIndex++;
        }
    }
}

// load the font
void Image::setFont(std::string filename) {
    loadImage(filename);
}

// Set the color of font
void Image::setFontColor(int r, int g, int b){
    fontColor[0] = r;
    fontColor[1] = g;
    fontColor[2] = b;
}

// Set the color of font
void Image::Image::setTextSize(int width, int height){
    textWidth = width;
    textHeight = height;
}

// Set the color of font
void Image::setTextPadding(int padding){
    textPadding = padding;
}

void Image::showPartialImageScaledColored(int posX, int posY, int x, int y, int width, int height, int newWidth, int newHeight) {
    double widthRatio = (double)width / (double)newWidth;
    double heightRatio = (double)height / (double)newHeight;

    for (int j = 0; j < newHeight; j++) {
        for (int i = 0; i < newWidth; i++) {
            int originalX = x + static_cast<int>(i * widthRatio);
            int originalY = y + static_cast<int>(j * heightRatio);

            if (originalX < imgWidth && originalY < imgHeight) {
                int index = 3 * (originalY * imgWidth + originalX);

                int r = imagePixelBuffer[index];
                int g = imagePixelBuffer[index + 1];
                int b = imagePixelBuffer[index + 2];

                if (r != 0 || g != 0 || b != 0) {
                    pixel(posX + i, posY + j, fontColor[0], fontColor[1], fontColor[2]);
                }
            }
        }
    }
}

// Show a text
void Image::typeChar(char type, int x, int y) {
    switch (type)
    {
    case 'a':
        showPartialImageScaledColored(x,y,0,0,10,20,textWidth,textHeight);
        break;
    case 'b':
        showPartialImageScaledColored(x,y,10,0,10,20,textWidth,textHeight);
        break;
    case 'c':
        showPartialImageScaledColored(x,y,20,0,10,20,textWidth,textHeight);
        break;
    case 'd':
        showPartialImageScaledColored(x,y,30,0,10,20,textWidth,textHeight);
        break;
    case 'e':
        showPartialImageScaledColored(x,y,40,0,10,20,textWidth,textHeight);
        break;
    case 'f':
        showPartialImageScaledColored(x,y,50,0,10,20,textWidth,textHeight);
        break;
    case 'g':
        showPartialImageScaledColored(x,y,60,0,10,20,textWidth,textHeight);
        break;
    case 'h':
        showPartialImageScaledColored(x,y,70,0,10,20,textWidth,textHeight);
        break;
    case 'i':
        showPartialImageScaledColored(x,y,80,0,10,20,textWidth,textHeight);
        break;
    case 'j':
        showPartialImageScaledColored(x,y,90,0,10,20,textWidth,textHeight);
        break;
    case 'k':
        showPartialImageScaledColored(x,y,100,0,10,20,textWidth,textHeight);
        break;
    case 'l':
        showPartialImageScaledColored(x,y,110,0,10,20,textWidth,textHeight);
        break;
    case 'm':
        showPartialImageScaledColored(x,y,120,0,10,20,textWidth,textHeight);
        break;
    case 'n':
        showPartialImageScaledColored(x,y,130,0,10,20,textWidth,textHeight);
        break;
    case 'o':
        showPartialImageScaledColored(x,y,140,0,10,20,textWidth,textHeight);
        break;
    case 'p':
        showPartialImageScaledColored(x,y,150,0,10,20,textWidth,textHeight);
        break;
    case 'q':
        showPartialImageScaledColored(x,y,160,0,10,20,textWidth,textHeight);
        break;
    case 'r':
        showPartialImageScaledColored(x,y,170,0,10,20,textWidth,textHeight);
        break;
    case 's':
        showPartialImageScaledColored(x,y,180,0,10,20,textWidth,textHeight);
        break;
    case 't':
        showPartialImageScaledColored(x,y,190,0,10,20,textWidth,textHeight);
        break;
    case 'u':
        showPartialImageScaledColored(x,y,200,0,10,20,textWidth,textHeight);
        break;
    case 'v':
        showPartialImageScaledColored(x,y,210,0,10,20,textWidth,textHeight);
        break;
    case 'w':
        showPartialImageScaledColored(x,y,220,0,10,20,textWidth,textHeight);
        break;
    case 'x':
        showPartialImageScaledColored(x,y,230,0,10,20,textWidth,textHeight);
        break;
    case 'y':
        showPartialImageScaledColored(x,y,240,0,10,20,textWidth,textHeight);
        break;
    case 'z':
        showPartialImageScaledColored(x,y,250,0,10,20,textWidth,textHeight);
        break;
    case '0':
        showPartialImageScaledColored(x,y,0,40,10,20,textWidth,textHeight);
        break;
    case '1':
        showPartialImageScaledColored(x,y,10,40,10,20,textWidth,textHeight);
        break;
    case '2':
        showPartialImageScaledColored(x,y,20,40,10,20,textWidth,textHeight);
        break;
    case '3':
        showPartialImageScaledColored(x,y,30,40,10,20,textWidth,textHeight);
        break;
    case '4':
        showPartialImageScaledColored(x,y,40,40,10,20,textWidth,textHeight);
        break;
    case '5':
        showPartialImageScaledColored(x,y,50,40,10,20,textWidth,textHeight);
        break;
    case '6':
        showPartialImageScaledColored(x,y,60,40,10,20,textWidth,textHeight);
        break;
    case '7':
        showPartialImageScaledColored(x,y,70,40,10,20,textWidth,textHeight);
        break;
    case '8':
        showPartialImageScaledColored(x,y,80,40,10,20,textWidth,textHeight);
        break;
    case '9':
        showPartialImageScaledColored(x,y,90,40,10,20,textWidth,textHeight);
        break;
    case '.':
        showPartialImageScaledColored(x,y,100,40,10,20,textWidth,textHeight);
        break;
    case ':':
        showPartialImageScaledColored(x,y,110,40,10,20,textWidth,textHeight);
        break;
    case ',':
        showPartialImageScaledColored(x,y,120,40,10,20,textWidth,textHeight);
        break;
    case ';':
        showPartialImageScaledColored(x,y,130,40,10,20,textWidth,textHeight);
        break;
    case '(':
        showPartialImageScaledColored(x,y,140,40,10,20,textWidth,textHeight);
        break;
    case '*':
        showPartialImageScaledColored(x,y,150,40,10,20,textWidth,textHeight);
        break;
    case '!':
        showPartialImageScaledColored(x,y,160,40,10,20,textWidth,textHeight);
        break;
    case '?':
        showPartialImageScaledColored(x,y,170,40,10,20,textWidth,textHeight);
        break;
    case '}':
        showPartialImageScaledColored(x,y,180,40,10,20,textWidth,textHeight);
        break;
    case '^':
        showPartialImageScaledColored(x,y,190,40,10,20,textWidth,textHeight);
        break;
    case ')':
        showPartialImageScaledColored(x,y,200,40,10,20,textWidth,textHeight);
        break;
    case '#':
        showPartialImageScaledColored(x,y,210,40,10,20,textWidth,textHeight);
        break;
    case '$':
        showPartialImageScaledColored(x,y,220,40,10,20,textWidth,textHeight);
        break;
    case '{':
        showPartialImageScaledColored(x,y,230,40,10,20,textWidth,textHeight);
        break;
    case '%':
        showPartialImageScaledColored(x,y,240,40,10,20,textWidth,textHeight);
        break;
    case '&':
        showPartialImageScaledColored(x,y,260,40,10,20,textWidth,textHeight);
        break;
    case '-':
        showPartialImageScaledColored(x,y,270,40,10,20,textWidth,textHeight);
        break;
    case '+':
        showPartialImageScaledColored(x,y,280,40,10,20,textWidth,textHeight);
        break;
    case '@':
        showPartialImageScaledColored(x,y,290,40,10,20,textWidth,textHeight);
        break;
    default:
        showPartialImageScaledColored(x,y,265,0,10,20,textWidth,textHeight);
        break;
    }
}

// Show a text
void Image::text(const std::string& text, int x, int y) {
    int padding = 0;
    
    for (size_t index = 0; index < text.size(); index++) {
        typeChar(text[index], x + padding, y);
        
        padding += textPadding;
    }
}

// The name say what do
uint32_t Image::RGBToHex(int r, int g, int b) {
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

// Same
void Image::HexToRGB(uint32_t hexValue, int& r, int& g, int& b) {
    r = (hexValue >> 16) & 0xFF;
    g = (hexValue >> 8) & 0xFF;
    b = hexValue & 0xFF;
}

// Show the image saved
void  Image::showImage(int posX, int posY) {
    int index = 0;

    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            int r = imagePixelBuffer[index++];
            int g = imagePixelBuffer[index++];
            int b = imagePixelBuffer[index++];

            if(r != 0 || g != 0 || b != 0) pixel(x+posX, y+posY, r, g, b);
        }
    }
}


// Show a partial image 
void Image::showPartialImage(int posX, int posY, int x, int y, int width, int height) {
    // Verificar límites de la imagen original y de la región a mostrar
    int maxX = myMin(x + width, imgWidth);
    int maxY = myMin(y + height, imgHeight);
 
    for (int j = y; j < maxY; j++) {
        for (int i = x; i < maxX; i++) {
            // Verificar si el índice está dentro de los límites
            if (i >= 0 && j >= 0 && i < imgWidth && j < imgHeight) {
                int index = 3 * (j * imgWidth + i);

                int r = imagePixelBuffer[index];
                int g = imagePixelBuffer[index + 1];
                int b = imagePixelBuffer[index + 2];

                // Mostrar todos los píxeles, independientemente del color
                pixel(i + posX - x, j + posY - y, r, g, b);
            }
        }
    }
}


// Show a partial image with a scale
void Image::showPartialImageScaled(int posX, int posY, int x, int y, int width, int height, int newWidth, int newHeight) {
    double widthRatio = (double)width / (double)newWidth;
    double heightRatio = (double)height / (double)newHeight;

    for (int j = 0; j < newHeight; j++) {
        for (int i = 0; i < newWidth; i++) {
            int originalX = x + static_cast<int>(i * widthRatio);
            int originalY = y + static_cast<int>(j * heightRatio);

            if (originalX < imgWidth && originalY < imgHeight) {
                int index = 3 * (originalY * imgWidth + originalX);

                int r = imagePixelBuffer[index];
                int g = imagePixelBuffer[index + 1];
                int b = imagePixelBuffer[index + 2];

                if (r != 0 || g != 0 || b != 0) {
                    pixel(posX + i, posY + j, r, g, b);
                }
            }
        }
    }
}
