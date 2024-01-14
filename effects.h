#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void translatePGM(struct imageNB* img, int decal)
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
            // tr.color[j][i] = img->color[j][i];
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

void translatePPM(struct imageRGB* img, int decal)
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
            // tr.color[j][i] = img->color[j][i];
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

void mirrorPGM(struct imageNB* img)
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
            float tmp = img->color[i][j];
            tr.color[i][j] = img->color[i][tr.width-j];
            tr.color[i][tr.width-j] = tmp;
        }
    }
    savePGM(&tr,"./images/result/mirror.pgm");
}

void mirrorPPM(struct imageRGB* img)
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
#endif