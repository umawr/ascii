#include<stdio.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int main(void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("apple.jpg", &width, &height, &channels, 0);
    int new_width = width / 2;
    int new_height = height / 2;
    size_t img_size = width * height * channels;
    unsigned char * resize_img = malloc(img_size);

    if (resize_img == NULL)
    {
        printf("Error in loading image\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned char * original_image = img, * resize_image = resize_img; original_image != img + img_size; original_image += channels, resize_image += channels)
    {
        * resize_image = (*original_image + *(original_image +1) + *(original_image + 2))/255
        if (channels == 4)
            exit(EXIT_FAILURE);
        
    }
}
// float color_converter(int)