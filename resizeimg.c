#include<stdio.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int color_converter(unsigned char * red1, unsigned char * green1, unsigned char * blue1,
                    unsigned char * red2, unsigned char * green2, unsigned char * blue2,
                    unsigned char * red3, unsigned char * green3, unsigned char * blue3,
                    unsigned char * red4, unsigned char * green4, unsigned char * blue4);


int main(void)
{
    int width, height, channels, color;
    unsigned char *img = stbi_load("apple1000x1000.jpg", &width, &height, &channels, 0);
    int new_width = width / 2;
    int new_height = height / 2;
    // size_t img_size = width * height * channels;
    size_t resize_img_size = new_width * new_height * channels;
    // unsigned char * resize_img = malloc(img_size);
    unsigned char * resize_img = malloc(resize_img_size);

    if (img == NULL)
    {
        printf("Error in loading image\n");
        exit(EXIT_FAILURE);
    }

    printf("Loaded image of width %d pixels, height %d pixels & %d channels\n", width, height, channels);

    for (unsigned char * original_image = img, * resize_image = resize_img;
        original_image != img + resize_img_size;
        original_image += channels * 2, resize_image += channels * 1)
    {
        color = color_converter(original_image, original_image + 1, original_image + 2,
                                original_image + 3, original_image + 4, original_image + 5,
                                (original_image + (width * 3)), (original_image + (width) * 3 + 1), (original_image + (width) * 3 + 2),
                                (original_image + (width * 3) + 3), (original_image + (width) * 3 + 4), (original_image + (width) * 3 + 5));
        if (color == 0)
        {
            *resize_image = 0;
            *(resize_image + 1) = 0;
            *(resize_image + 2) = 0;
        }
        else 
        {
            *resize_image = 255;
            *(resize_image + 1) = 255;
            *(resize_image + 2) = 255;
        }

        // original_image = original_image + channels * 2;
        // resize_image = resize_image + channels * 1;

        if (channels == 4)
            exit(EXIT_FAILURE);
        
    }
    stbi_write_jpg("apple_resize3.jpg", new_width, new_height, channels, resize_img, 100);
    stbi_image_free(img);
    free(resize_img);
}

// yes i write pointers like that ;)
int color_converter(unsigned char * red1, unsigned char * green1, unsigned char * blue1,
                    unsigned char * red2, unsigned char * green2, unsigned char * blue2,
                    unsigned char * red3, unsigned char * green3, unsigned char * blue3,
                    unsigned char * red4, unsigned char * green4, unsigned char * blue4)
{
    int y, y1, y2, y3, y4;
    y1 = *red1 * 0.299 + *green1 * 0.587 + *blue1 * 0.114;
    y2 = *red2 * 0.299 + *green2 * 0.587 + *blue2 * 0.114;
    y3 = *red3 * 0.299 + *green3 * 0.587 + *blue3 * 0.114;
    y4 = *red4 * 0.299 + *green4 * 0.587 + *blue4 * 0.114;
    y = (y1 + y2 + y3 + y4)/4;
    if (y >= 128)
        return 0;
    else 
        return 1;
}
