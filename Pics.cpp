#include "Pics.hpp"

Pics::Pics()
{   
    IMG_Init(IMG_INIT_PNG);

    path = "Images/Final/"; // Correct Address!
    images = {"Title.png", "Bee1.png", "Bee2.png", "Bee3.png", "Grub.png", "Tulip1.png", "Wasp.png", "Wasp2.png", "Wasp3.png", "Top_Flowers.png", "Top_Flowers.png"};

    int index = 0;

    for(string i: images)
    {
        string im_val = path + i;
        files[index] = im_val;
        index++;
    }
}

Pics::~Pics()
{
    IMG_Quit();
}