#include<stdio.h>
#include<stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
 
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main (void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("apple.jpg", &width, &height, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading image\n");
        exit(1);
    }
    printf("Loaded image of width %d pixels, height %d pixels & %d channels\n", width, height, channels);

    size_t img_size = width * height * channels;

 // for greyscale image
    /*
    int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_img_size = width * height * gray_channels;
    unsigned char *gray_img = malloc(gray_img_size);
    if (gray_img == NULL)
    {
        printf("Error in loading the gray image\n");
        exit(1);
    }
    for (unsigned char *p = img, *pg = gray_img; p != img_size + img; p += channels, pg += gray_channels)
    {
        *pg = (*p + *(p + 1) + *(p + 2))/3;
        if (channels == 4)
            *(pg + 1) = *(p + 3) ;  
    }

    stbi_write_jpg("apple_gray1.jpg", width, height, gray_channels, gray_img, 100);
    */

 // for sepia filter

    size_t sepia_img_size = width * height * channels;
    unsigned char * sepia_img = malloc(sepia_img_size);
    if (sepia_img == 0)
    {
        printf("Error in loadinng image\n");
        exit(EXIT_FAILURE);
    }
    for (unsigned char *p = img, *pg = sepia_img;p != img_size + img; p += channels, pg += channels)
    {
        *pg = fmin((*p * 0.393 ) + ((*p + 1) * 0.769) + (*(p + 2) * 0.189), 255);
        *(pg + 1) = fmin((*p * 0.349 ) + ((*p + 1) * 0.686) + (*(p + 2) * 0.168), 255);
        *(pg + 2) = fmin((*p * 0.272 ) + ((*p + 1) * 0.534) + (*(p + 2) * 0.131), 255);
    }
    stbi_write_jpg("apple_sepia.jpg", width, height, channels, sepia_img, 100 );



    // printd the image in jpg and png format

    // stbi_write_png("apple2.png", width, height, channels, img, width * channels);
    // stbi_write_jpg("apple2.jpg", width, height, channels, img, 1);

    stbi_image_free(img); // freeeing the image memory from the heap
    // free(gray_img);
    free(sepia_img);
}
