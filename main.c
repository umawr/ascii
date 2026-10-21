#include<stdio.h>
#include<stdlib.h>

#define STB_INCLUDE_IMPLEMENTATION
#include "stb_image.h"
 
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main (void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("apple.jpg", &width, &heigth, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading image\n");
        exit(1);
    }
    pritnf("Loaded image of width %d pixels, height %d pixels & %d channels\n", width, height, channels);
}