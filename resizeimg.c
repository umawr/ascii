#include<stdio.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int main(void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("apple.jpg", &width, &height, &channels, 0);
    // int new_width = width / 2;
    // int new_height = height / 2;
    size_t img_size = width * height * channels;
    unsigned char * resize_img = malloc(img_size);

    if (resize_img == NULL)
    {
        printf("Error in loading image\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned char * original_image = img, * resize_image = resize_img; original_image != img + img_size; original_image += channels, resize_image += channels)
    {
        int color;
        color = color_convertor(img, img + 1, img + 2,
                                img + 3, img + 4, img + 5,
                                (img + (width * 3)), (img + (width) * 3 + 1), (img + (width) * 3 + 2),
                                (img + (width * 3) + 3), (img + (width) * 3 + 4), (img + (width) * 3 + 5));

        img = img + channels * 2;
        if (channels == 4)
            exit(EXIT_FAILURE);
        
    }
}
// yes i write pointers like that ;)
int color_converter(int * red1, int * green1, int * blue1,
                    int * red2, int * green2, int * blue2,
                    int * red3, int * green3, int * blue3,
                    int * red4, int * green4, int * blue4)
{
    int y, y1, y2, y3, y4;
    y1 = *red1 + *green1 + *blue1;
    y2 = *red2 + *green2 + *blue2;
    y3 = *red3 + *green3 + *blue3;
    y4 = *red4 + *green4 + *blue4;
    y = (y1 + y2 + y3 + y4)/4;
    if (y >= 128)
        return 0;
    else 
        return 1,
}
