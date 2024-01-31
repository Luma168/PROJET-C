#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image.h"

void horizontalTranslatePGM(struct imageNB* img, int decal)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color = malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int newJ = (j + decal) % img->width;
            newJ = (newJ < 0) ? img->width + newJ : newJ;
            tmp.color[i][newJ] = img->color[i][j];
        }
    }

    savePGM(&tmp, "./images/result/horizontal_translated_image.pgm");
}

void verticalTranslatePGM(struct imageNB* img, int decal)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color = malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newI = (j + decal) % img->height;
            newI = (newI < 0) ? img->height + newI : newI;
            tmp.color[newI][i] = img->color[j][i];
        }
    }

    savePGM(&tmp, "./images/result/vertical_translated_image.pgm");
}

void horizontalTranslatePPM(struct imageRGB* img, int decal)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    
    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.green[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.blue[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int newJ = (j + decal) % img->width;
            newJ = (newJ < 0) ? img->width + newJ : newJ;
            tmp.red[i][newJ] = img->red[i][j];
            tmp.green[i][newJ] = img->green[i][j];
            tmp.blue[i][newJ] = img->blue[i][j];
        }
    }

    savePPM(&tmp, "./images/result/horizontal_translated_image.ppm");
}

void verticalTranslatePPM(struct imageRGB* img, int decal)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.green[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.blue[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newI = (j + decal) % img->height;
            newI = (newI < 0) ? img->height + newI : newI;
            tmp.red[newI][i] = img->red[j][i];
            tmp.green[newI][i] = img->green[j][i];
            tmp.blue[newI][i] = img->blue[j][i];
        }
    }

    savePPM(&tmp, "./images/result/vertical_translated_image.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void negatifPGM(struct imageNB* img)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color=malloc(tmp.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii]= malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i=0; i < tmp.width; i++ ){
        for (int j=0; j<tmp.height; j++){
            tmp.color[i][j]= 1 - (img->color[i][j]);
        }
    }
    savePGM(&tmp,"./images/result/negatif.pgm");
}

void negatifPPM(struct imageRGB* img)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(img->width * sizeof(unsigned char));
        tmp.green[i] = malloc(img->width * sizeof(unsigned char));
        tmp.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i=0; i < tmp.width; i++ ){
        for (int j=0; j<tmp.height; j++){
            tmp.red[i][j]= 1 - (img->red[i][j]);
            tmp.green[i][j]= 1 - (img->green[i][j]);
            tmp.blue[i][j]= 1 - (img->blue[i][j]);
        }
    }
    savePPM(&tmp,"./images/result/negatif.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void horizontalMirrorPGM(struct imageNB* img)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color=malloc(tmp.height * sizeof(unsigned char*));
    int ii, i,j;
    for (ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii]= malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i=0; i < tmp.height; i++ ){
        for (int j=0; j <= tmp.width/2; j++){
            unsigned char tmpColor = img->color[i][j];
            tmp.color[i][j] = img->color[i][tmp.width-j];
            tmp.color[i][tmp.width-j] = tmpColor;
        }
    }
    savePGM(&tmp,"./images/result/horizontal_mirror.pgm");
}

void horizontalMirrorPPM(struct imageRGB* img)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(img->width * sizeof(unsigned char));
        tmp.green[i] = malloc(img->width * sizeof(unsigned char));
        tmp.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i=0; i < tmp.height; i++ ){
        for (int j=0; j <= tmp.width/2; j++){
            float tmpRed = img->red[i][j];
            float tmpGreen = img->green[i][j];
            float tmpBlue = img->blue[i][j];

            tmp.red[i][j] = img->red[i][tmp.width-j];
            tmp.green[i][j] = img->green[i][tmp.width-j];
            tmp.blue[i][j] = img->blue[i][tmp.width-j];

            tmp.red[i][tmp.width-j] = tmpRed;
            tmp.green[i][tmp.width-j] = tmpGreen;
            tmp.blue[i][tmp.width-j] = tmpBlue;
        }
    }
    savePPM(&tmp,"./images/result/horizontal_mirror.ppm");
}

void verticalMirrorPGM(struct imageNB* img)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color=malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii]= malloc(tmp.width * sizeof(unsigned char));
    }

     for (int i = 0; i < tmp.height / 2; i++) {
        for (int j = 0; j < tmp.width; j++) {
            unsigned char tmpColor = img->color[i][j];
            tmp.color[i][j] = img->color[tmp.height - 1 - i][j];
            tmp.color[tmp.height - 1 - i][j] = tmpColor;
        }
    }
    savePGM(&tmp,"./images/result/vertical_mirror.pgm");
}

void verticalMirrorPPM(struct imageRGB* img)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(img->width * sizeof(unsigned char));
        tmp.green[i] = malloc(img->width * sizeof(unsigned char));
        tmp.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i = 0; i < tmp.height; i++) {
        for (int j = 0; j < tmp.width; j++) {
            float tmpRed = img->red[i][j];
            float tmpGreen = img->green[i][j];
            float tmpBlue = img->blue[i][j];

            tmp.red[i][j] = img->red[tmp.height - i - 1][j];
            tmp.green[i][j] = img->green[tmp.height - i - 1][j];
            tmp.blue[i][j] = img->blue[tmp.height - i - 1][j];

            tmp.red[tmp.height - i - 1][j] = tmpRed;
            tmp.green[tmp.height - i - 1][j] = tmpGreen;
            tmp.blue[tmp.height - i - 1][j] = tmpBlue;
        }
    }
    savePPM(&tmp,"./images/result/vertical_mirror.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void seuillagePGM(struct imageNB* img, int seuil)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color=malloc(tmp.height * sizeof(unsigned char*));
    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii]= malloc(tmp.width * sizeof(unsigned char));
    }

    for(int i=0;i< img->width;i++)
    {
        for(int j=0;j<img->height;j++)
        {
            if(img->color[i][j] > seuil)
            {
                tmp.color[i][j] = seuil;
            }
            else
            {
                tmp.color[i][j] = img->color[i][j];
            }
        }
    }
    savePGM(&tmp,"./images/result/seuillage.pgm");
}

void seuillagePPM(struct imageRGB* img, int seuil)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(img->width * sizeof(unsigned char));
        tmp.green[i] = malloc(img->width * sizeof(unsigned char));
        tmp.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for(int i=0;i< img->width;i++)
    {
        for(int j=0;j<img->height;j++)
        {
            if(img->red[i][j] > seuil)
            {
                tmp.red[i][j] = seuil;
            }
            else
            {
                tmp.red[i][j] = img->red[i][j];
            }

            if(img->green[i][j] > seuil)
            {
                tmp.green[i][j] = seuil;
            }
            else
            {
                tmp.green[i][j] = img->green[i][j];
            }

            if(img->blue[i][j] > seuil)
            {
                tmp.blue[i][j] = seuil;
            }
            else
            {
                tmp.blue[i][j] = img->blue[i][j];
            }
        }
    }
    savePPM(&tmp,"./images/result/seuillage.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void ppmToPgm(struct imageRGB* img)
{
    struct imageNB pgm;
    pgm.width = img->width;
    pgm.height = img->height;
    pgm.vmax = 255;
    pgm.color=malloc(pgm.height * sizeof(unsigned char*));
    for (int ii = 0; ii < pgm.height; ii++) {
        pgm.color[ii]= malloc(pgm.width * sizeof(unsigned char));
    }

    for(int i=0;i< img->width;i++)
    {
        for(int j=0;j<img->height;j++)
        {
            pgm.color[i][j] = 0.299*img->red[i][j] + 0.587*img->green[i][j] + 0.114*img->blue[i][j];
        }

    }
    savePGM(&pgm,"./images/result/niveauGris.pgm");
}

// --------------------------------------------------------------------------------------------------------------------

void generateHistogramGray(struct imageNB* image) {
    FILE* file = fopen("./images/result/histo.pgm", "w");
    if (!file) {
        fprintf(stderr, "Erreur lors de la création du fichier PGM pour l'histogramme.\n");
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "256 256\n");
    fprintf(file, "255\n"); 

    // Calculer l'histogramme
    int pixels[256] = {0};
    for (int i = 0; i < image->width; ++i) {
        for (int j = 0; j < image->height; ++j) {
            pixels[image->color[j][i]]++;
        }
    }

    // Trouver la valeur maximale de l'histogramme
    int maxFrequency = 0;
    for (int i = 0; i < 256; ++i) {
        if (pixels[i] > maxFrequency) {
            maxFrequency = pixels[i];
        }
    }

    // Normaliser et écrire l'histogramme dans le fichier PGM
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i <= 255; ++i) {
            int normalizedHeight = (pixels[i] * 255) / maxFrequency;
            if (j >= 255 - normalizedHeight) {
                fprintf(file, "0 ");  // attribuer 0 pour les pixels représentant l'histogramme
            } else {
                fprintf(file, "255 ");  // attribuer 255 pour les pixels qui ne représentent pas l'histogramme
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void generateHistogramRed(struct imageRGB* image) {
    FILE* file = fopen("./images/result/histo_red.pgm", "w");
    if (!file) {
        fprintf(stderr, "Erreur lors de la création du fichier PGM pour l'histogramme du canal rouge.\n");
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "256 256\n");
    fprintf(file, "255\n");

    // Calculer l'histogramme du canal rouge
    int pixels[256] = {0};
    for (int i = 0; i < image->width; ++i) {
        for (int j = 0; j < image->height; ++j) {
            pixels[image->red[j][i]]++;
        }
    }

    // Trouver la valeur maximale de l'histogramme
    int maxFrequency = 0;
    for (int i = 0; i < 256; ++i) {
        if (pixels[i] > maxFrequency) {
            maxFrequency = pixels[i];
        }
    }

    // Normaliser et écrire l'histogramme dans le fichier PGM
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i <= 255; ++i) {
            int normalizedHeight = (pixels[i] * 255) / maxFrequency;
            if (j >= 255 - normalizedHeight) {
                fprintf(file, "0 ");  // attribuer 0 pour les pixels représentant l'histogramme
            } else {
                fprintf(file, "255 ");  // attribuer 255 pour les pixels qui ne représentent pas l'histogramme
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void generateHistogramGreen(struct imageRGB* image) {
    FILE* file = fopen("./images/result/histo_green.pgm", "w");
    if (!file) {
        fprintf(stderr, "Erreur lors de la création du fichier PGM pour l'histogramme du canal vert.\n");
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "256 256\n");
    fprintf(file, "255\n");

    // Calculer l'histogramme du canal vert
    int pixels[256] = {0};
    for (int i = 0; i < image->width; ++i) {
        for (int j = 0; j < image->height; ++j) {
            pixels[image->green[j][i]]++;
        }
    }

    // Trouver la valeur maximale de l'histogramme
    int maxFrequency = 0;
    for (int i = 0; i < 256; ++i) {
        if (pixels[i] > maxFrequency) {
            maxFrequency = pixels[i];
        }
    }

    // Normaliser et écrire l'histogramme dans le fichier PGM
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i <= 255; ++i) {
            int normalizedHeight = (pixels[i] * 255) / maxFrequency;
            if (j >= 255 - normalizedHeight) {
                fprintf(file, "0 ");  // attribuer 0 pour les pixels représentant l'histogramme
            } else {
                fprintf(file, "255 ");  // attribuer 255 pour les pixels qui ne représentent pas l'histogramme
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void generateHistogramBlue(struct imageRGB* image) {
    FILE* file = fopen("./images/result/histo_blue.pgm", "w");
    if (!file) {
        fprintf(stderr, "Erreur lors de la création du fichier PGM pour l'histogramme du canal bleu.\n");
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "256 256\n");
    fprintf(file, "255\n");

    // Calculer l'histogramme du canal bleu
    int pixels[256] = {0};
    for (int i = 0; i < image->width; ++i) {
        for (int j = 0; j < image->height; ++j) {
            pixels[image->blue[j][i]]++;
        }
    }

    // Trouver la valeur maximale de l'histogramme
    int maxFrequency = 0;
    for (int i = 0; i < 256; ++i) {
        if (pixels[i] > maxFrequency) {
            maxFrequency = pixels[i];
        }
    }

    // Normaliser et écrire l'histogramme dans le fichier PGM
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i <= 255; ++i) {
            int normalizedHeight = (pixels[i] * 255) / maxFrequency;
            if (j >= 255 - normalizedHeight) {
                fprintf(file, "0 ");  // attribuer 0 pour les pixels représentant l'histogramme
            } else {
                fprintf(file, "255 ");  // attribuer 255 pour les pixels qui ne représentent pas l'histogramme
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}


// --------------------------------------------------------------------------------------------------------------------

void blurPGM(struct imageNB* img, int blurDegree)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color = malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii] = malloc(tmp.width * sizeof(unsigned char));
    }

    // Calculate the blur kernel size based on the blur degree
    int kernelSize = 2 * blurDegree + 1;

    // Allocate memory for the blur kernel dynamically
    int** kernel = malloc(kernelSize * sizeof(int*));
    for (int i = 0; i < kernelSize; i++) {
        kernel[i] = malloc(kernelSize * sizeof(int));
    }

    // Fill the blur kernel with 1's
    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            kernel[i][j] = 1;
        }
    }

    // Convolution operation
    for (int i = blurDegree; i < img->width - blurDegree; i++) {
        for (int j = blurDegree; j < img->height - blurDegree; j++) {
            int sum = 0;
            for (int ki = -blurDegree; ki <= blurDegree; ki++) {
                for (int kj = -blurDegree; kj <= blurDegree; kj++) {
                    sum += img->color[j + kj][i + ki] * kernel[kj + blurDegree][ki + blurDegree];
                }
            }
            tmp.color[j][i] = sum / (kernelSize * kernelSize); // Normalize by the sum of kernel values
        }
    }

    savePGM(&tmp, "./images/result/blurred.pgm");
}

void blurPPM(struct imageRGB* img, int blurDegree)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(tmp.height * sizeof(unsigned char*));
    tmp.green = malloc(tmp.height * sizeof(unsigned char*));
    tmp.blue = malloc(tmp.height * sizeof(unsigned char*));

    for (int i = 0; i < tmp.height; i++) {
        tmp.red[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.green[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.blue[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    // Calculate the blur kernel size based on the blur degree
    int kernelSize = 2 * blurDegree + 1;

    // Allocate memory for the blur kernel dynamically
    int** kernel = malloc(kernelSize * sizeof(int*));
    for (int i = 0; i < kernelSize; i++) {
        kernel[i] = malloc(kernelSize * sizeof(int));
    }

    // Fill the blur kernel with 1's
    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            kernel[i][j] = 1;
        }
    }

    // Convolution operation
    for (int i = blurDegree; i < img->width - blurDegree; i++) {
        for (int j = blurDegree; j < img->height - blurDegree; j++) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            for (int ki = -blurDegree; ki <= blurDegree; ki++) {
                for (int kj = -blurDegree; kj <= blurDegree; kj++) {
                    sumRed += img->red[j + kj][i + ki] * kernel[kj + blurDegree][ki + blurDegree];
                    sumGreen += img->green[j + kj][i + ki] * kernel[kj + blurDegree][ki + blurDegree];
                    sumBlue += img->blue[j + kj][i + ki] * kernel[kj + blurDegree][ki + blurDegree];
                }
            }
            tmp.red[j][i] = sumRed / (kernelSize * kernelSize); // Normalize by the sum of kernel values
            tmp.green[j][i] = sumGreen / (kernelSize * kernelSize);
            tmp.blue[j][i] = sumBlue / (kernelSize * kernelSize);
        }
    }

    savePPM(&tmp, "./images/result/blurred.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void pixelatePGM(struct imageNB* img, int pixelSize)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color = malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii] = malloc(tmp.width * sizeof(unsigned char));
    }

    // Parcourir l'image avec un pas egal a la taille du Grospixel
    for (int i = 0; i < img->width; i += pixelSize) {
        for (int j = 0; j < img->height; j += pixelSize) {
            int sum = 0;
            int count = 0;

            // Calculer l'intensite moyenne dans le pixel
            for (int ki = 0; ki < pixelSize && i + ki < img->width; ki++) {
                for (int kj = 0; kj < pixelSize && j + kj < img->height; kj++) {
                    sum += img->color[j + kj][i + ki];
                    count++;
                }
            }
            // Intensite moyenne = somme des intensties / nb de pixels
            unsigned char avgIntensity = (unsigned char)(sum / count);

            // Affecter l'intensite moyenne a tous les pixels 
            for (int ki = 0; ki < pixelSize && i + ki < img->width; ki++) {
                for (int kj = 0; kj < pixelSize && j + kj < img->height; kj++) {
                    tmp.color[j + kj][i + ki] = avgIntensity;
                }
            }
        }
    }

    savePGM(&tmp, "./images/result/pixelized.pgm");
}

void pixelatePPM(struct imageRGB* img, int pixelSize)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(tmp.height * sizeof(unsigned char*));
    tmp.green = malloc(tmp.height * sizeof(unsigned char*));
    tmp.blue = malloc(tmp.height * sizeof(unsigned char*));

    for (int i = 0; i < tmp.height; i++) {
        tmp.red[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.green[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.blue[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i += pixelSize) {
        for (int j = 0; j < img->height; j += pixelSize) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            for (int ki = 0; ki < pixelSize && i + ki < img->width; ki++) {
                for (int kj = 0; kj < pixelSize && j + kj < img->height; kj++) {
                    sumRed += img->red[j + kj][i + ki];
                    sumGreen += img->green[j + kj][i + ki];
                    sumBlue += img->blue[j + kj][i + ki];
                    count++;
                }
            }

            unsigned char avgRed = (unsigned char)(sumRed / count);
            unsigned char avgGreen = (unsigned char)(sumGreen / count);
            unsigned char avgBlue = (unsigned char)(sumBlue / count);

            for (int ki = 0; ki < pixelSize && i + ki < img->width; ki++) {
                for (int kj = 0; kj < pixelSize && j + kj < img->height; kj++) {
                    tmp.red[j + kj][i + ki] = avgRed;
                    tmp.green[j + kj][i + ki] = avgGreen;
                    tmp.blue[j + kj][i + ki] = avgBlue;
                }
            }
        }
    }

    savePPM(&tmp, "./images/result/pixelized.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void contrastPGM(struct imageNB* img, float factor)
{
    struct imageNB tmp;
    tmp.width = img->width;
    tmp.height = img->height;
    tmp.vmax = img->vmax;
    tmp.color = malloc(tmp.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tmp.height; ii++) {
        tmp.color[ii] = malloc(tmp.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            float adjustedIntensity = (img->color[j][i] - img->vmax / 2.0) * factor + img->vmax / 2.0;

            adjustedIntensity = (adjustedIntensity < 0) ? 0 : adjustedIntensity;
            adjustedIntensity = (adjustedIntensity > img->vmax) ? img->vmax : adjustedIntensity;

            tmp.color[j][i] = (unsigned char)adjustedIntensity;
        }
    }

    savePGM(&tmp, "./images/result/contrastAdjusted.pgm");
}

void contrastPPM(struct imageRGB* img, float factor)
{
    struct imageRGB tmp;
    tmp.width = img->width;
    tmp.height = img->height;

    tmp.red = malloc(img->height * sizeof(unsigned char*));
    tmp.green = malloc(img->height * sizeof(unsigned char*));
    tmp.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        tmp.red[i] = malloc(img->width * sizeof(unsigned char));
        tmp.green[i] = malloc(img->width * sizeof(unsigned char));
        tmp.blue[i] = malloc(img->width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            float adjustedRed = ((float)img->red[j][i] - 128) * factor + 128;
            float adjustedGreen = ((float)img->green[j][i] - 128) * factor + 128;
            float adjustedBlue = ((float)img->blue[j][i] - 128) * factor + 128;

            adjustedRed = (adjustedRed < 0) ? 0 : adjustedRed;
            adjustedGreen = (adjustedGreen < 0) ? 0 : adjustedGreen;
            adjustedBlue = (adjustedBlue < 0) ? 0 : adjustedBlue;

            adjustedRed = (adjustedRed > 255) ? 255 : adjustedRed;
            adjustedGreen = (adjustedGreen > 255) ? 255 : adjustedGreen;
            adjustedBlue = (adjustedBlue > 255) ? 255 : adjustedBlue;

            tmp.red[j][i] = (unsigned char)adjustedRed;
            tmp.green[j][i] = (unsigned char)adjustedGreen;
            tmp.blue[j][i] = (unsigned char)adjustedBlue;
        }
    }

    savePPM(&tmp, "./images/result/contrastAdjusted.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void scalePGM(struct imageNB* img, float scale)
{
    int newWidth = (int)(img->width * scale);
    int newHeight = (int)(img->height * scale);

    struct imageNB tmp;
    tmp.width = newWidth;
    tmp.height = newHeight;
    tmp.vmax = img->vmax;

    tmp.color = malloc(newHeight * sizeof(unsigned char*));
    for (int ii = 0; ii < newHeight; ii++) {
        tmp.color[ii] = malloc(newWidth * sizeof(unsigned char));
    }

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int originalX = (int)(i / scale);
            int originalY = (int)(j / scale);

            originalX = (originalX < 0) ? 0 : originalX;
            originalY = (originalY < 0) ? 0 : originalY;
            originalX = (originalX >= img->width) ? img->width - 1 : originalX;
            originalY = (originalY >= img->height) ? img->height - 1 : originalY;

            tmp.color[j][i] = img->color[originalY][originalX];
        }
    }

    savePGM(&tmp, "./images/result/scaled_image.pgm");
}

void scalePPM(struct imageRGB* img, float scale)
{
    int newWidth = (int)(img->width * scale);
    int newHeight = (int)(img->height * scale);

    struct imageRGB tmp;
    tmp.width = newWidth;
    tmp.height = newHeight;

    tmp.red = malloc(newHeight * sizeof(unsigned char*));
    tmp.green = malloc(newHeight * sizeof(unsigned char*));
    tmp.blue = malloc(newHeight * sizeof(unsigned char*));

    for (int i = 0; i < newHeight; i++) {
        tmp.red[i] = malloc(newWidth * sizeof(unsigned char));
        tmp.green[i] = malloc(newWidth * sizeof(unsigned char));
        tmp.blue[i] = malloc(newWidth * sizeof(unsigned char));
    }

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int originalX = (int)(i / scale);
            int originalY = (int)(j / scale);

            originalX = (originalX < 0) ? 0 : originalX;
            originalY = (originalY < 0) ? 0 : originalY;
            originalX = (originalX >= img->width) ? img->width - 1 : originalX;
            originalY = (originalY >= img->height) ? img->height - 1 : originalY;

            tmp.red[j][i] = img->red[originalY][originalX];
            tmp.green[j][i] = img->green[originalY][originalX];
            tmp.blue[j][i] = img->blue[originalY][originalX];
        }
    }

    savePPM(&tmp, "./images/result/scaled_image.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void luminosityPGM(struct imageNB* img, int brightness)
{
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newPixelValue = img->color[i][j] + brightness;

            newPixelValue = (newPixelValue < 0) ? 0 : (newPixelValue > img->vmax) ? img->vmax : newPixelValue;

            img->color[i][j] = newPixelValue;
        }
    }

    savePGM(img, "./images/result/adjusted_brightness.pgm");
}

void luminosityPPM(struct imageRGB* img, int brightness)
{
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newRed = img->red[i][j] + brightness;
            int newGreen = img->green[i][j] + brightness;
            int newBlue = img->blue[i][j] + brightness;

            newRed = (newRed < 0) ? 0 : (newRed > 255) ? 255 : newRed;
            newGreen = (newGreen < 0) ? 0 : (newGreen > 255) ? 255 : newGreen;
            newBlue = (newBlue < 0) ? 0 : (newBlue > 255) ? 255 : newBlue;

            img->red[i][j] = newRed;
            img->green[i][j] = newGreen;
            img->blue[i][j] = newBlue;
        }
    }

    savePPM(img, "./images/result/adjusted_brightness.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void rotatePGM(struct imageNB* img, double angle) {
    // Conversion degrés vers radians
    double angleRad = angle * M_PI / 180.0;

    // Calcul des nouvelles dimensions de l'image
    int newWidth = (int)(fabs(img->width * cos(angleRad)) + fabs(img->height * sin(angleRad)));
    int newHeight = (int)(fabs(img->width * sin(angleRad)) + fabs(img->height * cos(angleRad)));

    // Création d'une nouvelle image avec les nouvelles dimensions
    struct imageNB tmp;
    tmp.width = newWidth;
    tmp.height = newHeight;
    tmp.vmax = img->vmax;

    tmp.color = malloc(tmp.height * sizeof(unsigned char*));
    for (int i = 0; i < tmp.height; i++) {
        tmp.color[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    // Calcul des coordonnées du centre de l'image d'origine
    int centerX = img->width / 2;
    int centerY = img->height / 2;

    // Calcul des coordonnées du centre de la nouvelle image
    int newCenterX = tmp.width / 2;
    int newCenterY = tmp.height / 2;

    // Effectuer la rotation
    for (int i = 0; i < tmp.width; i++) {
        for (int j = 0; j < tmp.height; j++) {
            // Translations pour recentrer l'image pendant la rotation
            int x = i - newCenterX;
            int y = j - newCenterY;

            // Calcul des coordonnées d'origine après rotation
            int originalX = (int)(x * cos(angleRad) - y * sin(angleRad) + centerX);
            int originalY = (int)(x * sin(angleRad) + y * cos(angleRad) + centerY);

            // Vérification des limites pour éviter le dépassement
            if (originalX >= 0 && originalX < img->width && originalY >= 0 && originalY < img->height) {
                tmp.color[j][i] = img->color[originalY][originalX];
            } else {
                tmp.color[j][i] = 0;  // Remplir les pixels hors limite avec une intensité de 0
            }
        }
    }

    // Mettre à jour les dimensions de l'image d'origine
    img->width = tmp.width;
    img->height = tmp.height;
    img->vmax = tmp.vmax;

    // Copier les données de l'image tournée dans l'image d'origine
    img->color = tmp.color;
}

void rotatePPM(struct imageRGB* img, double angle) {
    // Conversion degrés vers radians
    double angleRad = angle * M_PI / 180.0;

    // Calcul des nouvelles dimensions de l'image
    int newWidth = (int)(fabs(img->width * cos(angleRad)) + fabs(img->height * sin(angleRad)));
    int newHeight = (int)(fabs(img->width * sin(angleRad)) + fabs(img->height * cos(angleRad)));

    // Création d'une nouvelle image avec les nouvelles dimensions
    struct imageRGB tmp;
    tmp.width = newWidth;
    tmp.height = newHeight;

    tmp.red = malloc(tmp.height * sizeof(unsigned char*));
    tmp.green = malloc(tmp.height * sizeof(unsigned char*));
    tmp.blue = malloc(tmp.height * sizeof(unsigned char*));

    for (int i = 0; i < tmp.height; i++) {
        tmp.red[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.green[i] = malloc(tmp.width * sizeof(unsigned char));
        tmp.blue[i] = malloc(tmp.width * sizeof(unsigned char));
    }

    // Calcul des coordonnées du centre de l'image d'origine
    int centerX = img->width / 2;
    int centerY = img->height / 2;

    // Calcul des coordonnées du centre de la nouvelle image
    int newCenterX = tmp.width / 2;
    int newCenterY = tmp.height / 2;

    // Effectuer la rotation
    for (int i = 0; i < tmp.width; i++) {
        for (int j = 0; j < tmp.height; j++) {
            // Translations pour recentrer l'image pendant la rotation
            int x = i - newCenterX;
            int y = j - newCenterY;

            // Calcul des coordonnées d'origine après rotation
            int originalX = (int)(x * cos(angleRad) - y * sin(angleRad) + centerX);
            int originalY = (int)(x * sin(angleRad) + y * cos(angleRad) + centerY);

            // Vérification des limites pour éviter le dépassement
            if (originalX >= 0 && originalX < img->width && originalY >= 0 && originalY < img->height) {
                tmp.red[j][i] = img->red[originalY][originalX];
                tmp.green[j][i] = img->green[originalY][originalX];
                tmp.blue[j][i] = img->blue[originalY][originalX];
            } else {
                tmp.red[j][i] = 0;  // Remplir les pixels hors limite avec une intensité de 0
                tmp.green[j][i] = 0;
                tmp.blue[j][i] = 0;
            }
        }
    }

    // Mettre à jour les dimensions de l'image d'origine
    img->width = tmp.width;
    img->height = tmp.height;

    // Copier les données de l'image tournée dans l'image d'origine
    img->red = tmp.red;
    img->green = tmp.green;
    img->blue = tmp.blue;
}


#endif