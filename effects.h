#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void horizontalTranslatePGM(struct imageNB* img, int decal)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }
    for(i=0;i< img->width;i++)
    {
        for(j=0;j<img->height;j++)
        {
            if(i+decal <img->width)
            {
                tr.color[j][i+decal] = img->color[j][i];
            }
            else
            {
                tr.color[j][i+decal-img->width] = img->color[j][i];
            }
        }
    }
    savePGM(&tr,"./images/result/translated_image.pgm");
}

void verticalTranslatePGM(struct imageNB* img, int decal)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }
    for(i=0;i< img->width;i++)
    {
        for(j=0;j<img->height;j++)
        {
            if(j+decal < img->height)
            {
                tr.color[j+decal][i] = img->color[j][i];
            }
            else
            {
                tr.color[j+decal-img->height][i] = img->color[j][i];
            }
        }
    }
    savePGM(&tr,"./images/result/translated_image.pgm");
}

void horizontalTranslatePPM(struct imageRGB* img, int decal)
{
    struct imageRGB tr;
    tr.width = img->width;
    tr.height = img->height;

    tr.red = malloc(img->height * sizeof(unsigned char*));
    tr.green = malloc(img->height * sizeof(unsigned char*));
    tr.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tr.red[i] = malloc(img->width * sizeof(unsigned char));
        tr.green[i] = malloc(img->width * sizeof(unsigned char));
        tr.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    int i,j;
    for(i=0;i< img->width;i++)
    {
        for(j=0;j<img->height;j++)
        {
            if(i+decal <img->width)
            {
                tr.red[j][i+decal] = img->red[j][i];
                tr.green[j][i+decal] = img->green[j][i];
                tr.blue[j][i+decal] = img->blue[j][i];
            }
            else
            {
                tr.red[j][i+decal-img->width] = img->red[j][i];
                tr.green[j][i+decal-img->width] = img->green[j][i];
                tr.blue[j][i+decal-img->width] = img->blue[j][i];
            }
        }
    }
    savePPM(&tr,"./images/result/translated_image.ppm");
}

void verticalTranslatePPM(struct imageRGB* img, int decal)
{
    struct imageRGB tr;
    tr.width = img->width;
    tr.height = img->height;

    tr.red = malloc(img->height * sizeof(unsigned char*));
    tr.green = malloc(img->height * sizeof(unsigned char*));
    tr.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tr.red[i] = malloc(img->width * sizeof(unsigned char));
        tr.green[i] = malloc(img->width * sizeof(unsigned char));
        tr.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    int i,j;
    for(i=0;i< img->width;i++)
    {
        for(j=0;j<img->height;j++)
        {
            if(j+decal < img->height)
            {
                tr.red[j+decal][i] = img->red[j][i];
                tr.green[j+decal][i] = img->green[j][i];
                tr.blue[j+decal][i] = img->blue[j][i];
            }
            else
            {
                tr.red[j+decal-img->height][i] = img->red[j][i];
                tr.green[j+decal-img->height][i] = img->green[j][i];
                tr.blue[j+decal-img->height][i] = img->blue[j][i];
            }
        }
    }
    savePPM(&tr,"./images/result/translated_image.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void negatifPGM(struct imageNB* img)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }

    for (int i=0; i < tr.width; i++ ){
        for (int j=0; j<tr.height; j++){
            tr.color[i][j]= 1 - (img->color[i][j]);
        }
    }
    savePGM(&tr,"./images/result/negatif.pgm");
}

void negatifPPM(struct imageRGB* img)
{
    struct imageRGB tr;
    tr.width = img->width;
    tr.height = img->height;

    tr.red = malloc(img->height * sizeof(unsigned char*));
    tr.green = malloc(img->height * sizeof(unsigned char*));
    tr.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tr.red[i] = malloc(img->width * sizeof(unsigned char));
        tr.green[i] = malloc(img->width * sizeof(unsigned char));
        tr.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i=0; i < tr.width; i++ ){
        for (int j=0; j<tr.height; j++){
            tr.red[i][j]= 1 - (img->red[i][j]);
            tr.green[i][j]= 1 - (img->green[i][j]);
            tr.blue[i][j]= 1 - (img->blue[i][j]);
        }
    }
    savePPM(&tr,"./images/result/negatif.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void horizontalMirrorPGM(struct imageNB* img)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }

    for (int i=0; i < tr.height; i++ ){
        for (int j=0; j <= tr.width/2; j++){
            unsigned char tmp = img->color[i][j];
            tr.color[i][j] = img->color[i][tr.width-j];
            tr.color[i][tr.width-j] = tmp;
        }
    }
    savePGM(&tr,"./images/result/mirror.pgm");
}

void horizontalMirrorPPM(struct imageRGB* img)
{
    struct imageRGB tr;
    tr.width = img->width;
    tr.height = img->height;

    tr.red = malloc(img->height * sizeof(unsigned char*));
    tr.green = malloc(img->height * sizeof(unsigned char*));
    tr.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tr.red[i] = malloc(img->width * sizeof(unsigned char));
        tr.green[i] = malloc(img->width * sizeof(unsigned char));
        tr.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i=0; i < tr.height; i++ ){
        for (int j=0; j <= tr.width/2; j++){
            float tmpRed = img->red[i][j];
            float tmpGreen = img->green[i][j];
            float tmpBlue = img->blue[i][j];

            tr.red[i][j] = img->red[i][tr.width-j];
            tr.green[i][j] = img->green[i][tr.width-j];
            tr.blue[i][j] = img->blue[i][tr.width-j];

            tr.red[i][tr.width-j] = tmpRed;
            tr.green[i][tr.width-j] = tmpGreen;
            tr.blue[i][tr.width-j] = tmpBlue;
        }
    }
    savePPM(&tr,"./images/result/mirror.ppm");
}

void verticalMirrorPGM(struct imageNB* img)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }

     for (int i = 0; i < tr.height / 2; i++) {
        for (int j = 0; j < tr.width; j++) {
            unsigned char tmp = img->color[i][j];
            tr.color[i][j] = img->color[tr.height - 1 - i][j];
            tr.color[tr.height - 1 - i][j] = tmp;
        }
    }
    savePGM(&tr,"./images/result/mirror.pgm");
}

void verticalMirrorPPM(struct imageRGB* img)
{
    struct imageRGB tr;
    tr.width = img->width;
    tr.height = img->height;

    tr.red = malloc(img->height * sizeof(unsigned char*));
    tr.green = malloc(img->height * sizeof(unsigned char*));
    tr.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tr.red[i] = malloc(img->width * sizeof(unsigned char));
        tr.green[i] = malloc(img->width * sizeof(unsigned char));
        tr.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i = 0; i < tr.height; i++) {
        for (int j = 0; j < tr.width; j++) {
            float tmpRed = img->red[i][j];
            float tmpGreen = img->green[i][j];
            float tmpBlue = img->blue[i][j];

            tr.red[i][j] = img->red[tr.height - i - 1][j];
            tr.green[i][j] = img->green[tr.height - i - 1][j];
            tr.blue[i][j] = img->blue[tr.height - i - 1][j];

            tr.red[tr.height - i - 1][j] = tmpRed;
            tr.green[tr.height - i - 1][j] = tmpGreen;
            tr.blue[tr.height - i - 1][j] = tmpBlue;
        }
    }
    savePPM(&tr,"./images/result/mirror.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void seuillagePGM(struct imageNB* img, int seuil)
{
    struct imageNB seu;
    seu.width = img->width;
    seu.height = img->height;
    seu.vmax = img->vmax;
    seu.color=malloc(seu.height * sizeof(unsigned char*));
    for (int ii = 0; ii < seu.height; ii++) {
        seu.color[ii]= malloc(seu.width * sizeof(unsigned char));
    }

    for(int i=0;i< img->width;i++)
    {
        for(int j=0;j<img->height;j++)
        {
            if(img->color[i][j] > seuil)
            {
                seu.color[i][j] = seuil;
            }
            else
            {
                seu.color[i][j] = img->color[i][j];
            }
        }
    }
    savePGM(&seu,"./images/result/seuillage.pgm");
}

void seuillagePPM(struct imageRGB* img, int seuil)
{
    struct imageRGB seu;
    seu.width = img->width;
    seu.height = img->height;

    seu.red = malloc(img->height * sizeof(unsigned char*));
    seu.green = malloc(img->height * sizeof(unsigned char*));
    seu.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        seu.red[i] = malloc(img->width * sizeof(unsigned char));
        seu.green[i] = malloc(img->width * sizeof(unsigned char));
        seu.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for(int i=0;i< img->width;i++)
    {
        for(int j=0;j<img->height;j++)
        {
            if(img->red[i][j] > seuil)
            {
                seu.red[i][j] = seuil;
            }
            else
            {
                seu.red[i][j] = img->red[i][j];
            }

            if(img->green[i][j] > seuil)
            {
                seu.green[i][j] = seuil;
            }
            else
            {
                seu.green[i][j] = img->green[i][j];
            }

            if(img->blue[i][j] > seuil)
            {
                seu.blue[i][j] = seuil;
            }
            else
            {
                seu.blue[i][j] = img->blue[i][j];
            }
        }
    }
    savePPM(&seu,"./images/result/seuillage.ppm");
}

#endif