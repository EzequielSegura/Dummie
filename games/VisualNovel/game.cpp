#include <game.h>

// Resolution 320x240 

/* Game Config */
unsigned int fps = 60;

/* Text */
Image textTitle_Image;

/* Main Menu */
int textColor = 255;
bool changeDirectionGrad = false;
Image castle_Image;
Image castleFlag_Image;
int castleFlag_Image_Frame_Index = 0;
int castleFlag_Image_FrameRate = 0;
Image pressAnyKey_Text;
void mainMenu();

void Game::start(){
    pressAnyKey_Text.setFont("games/VisualNovel/res/fonts/Perfect-DOS-VGA-437.png");
    textTitle_Image.setFont("games/VisualNovel/res/fonts/Perfect-DOS-VGA-437.png");
    castle_Image.loadImage("games/VisualNovel/res/img/CastleMenu.png");
    castleFlag_Image.loadImage("games/VisualNovel/res/img/Flag_6_0.png");
}

void Game::update(){
    mainMenu();

    /*  Game Control */
    fullScreen(key, window);
    frameRate(fps);
}

void mainMenu(){
    float red = 138.0f / 255.0f;
    float green = 186.0f / 255.0f;
    float blue = 203.0f / 255.0f;

    glClearColor(red, green, blue, 1.0f);

    textTitle_Image.setTextSize(13,24);
    textTitle_Image.setTextPadding(14);
    textTitle_Image.setFontColor(255, 255, 255);
    textTitle_Image.text("the last", 58, 20);
    textTitle_Image.text("first travel", 90, 40);

    castle_Image.showPartialImageScaled(85, 80, 0, 0, 120, 120, 160, 160);

    castleFlag_Image.showPartialImageScaled(115, 118, castleFlag_Image_Frame_Index, 0, 10, 7, 13, 9);
    castleFlag_Image.showPartialImageScaled(151, 85, castleFlag_Image_Frame_Index, 0, 10, 7, 13, 9);
    castleFlag_Image.showPartialImageScaled(186, 118, castleFlag_Image_Frame_Index, 0, 10, 7, 13, 9);

    pressAnyKey_Text.setTextSize(8,24);
    pressAnyKey_Text.setTextPadding(9);
    pressAnyKey_Text.setFontColor(textColor, textColor, textColor);
    pressAnyKey_Text.text("press enter", 110, 200);

    /* Change the graduation and size of the title text*/
    if (textColor >= 100 && !changeDirectionGrad){
        textColor -= 5;
    }else if (textColor <= 249 && changeDirectionGrad){
        textColor += 2;
    }else{
        changeDirectionGrad = !changeDirectionGrad;
    }

    /* Flag animation */
    if (castleFlag_Image_Frame_Index < 40)
    {
        if (castleFlag_Image_FrameRate == 5)
        {
            castleFlag_Image_Frame_Index += 10;
            castleFlag_Image_FrameRate = 0;
        }
    }else{
        castleFlag_Image_Frame_Index = 0;
    }
    if (castleFlag_Image_FrameRate < 5)
    {
        castleFlag_Image_FrameRate++;
    }
    
    
    
}
