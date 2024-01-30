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
    tr.color = malloc(tr.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tr.height; ii++) {
        tr.color[ii] = malloc(tr.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int newJ = (j + decal) % img->width;
            newJ = (newJ < 0) ? img->width + newJ : newJ;
            tr.color[i][newJ] = img->color[i][j];
        }
    }

    savePGM(&tr, "./images/result/translated_image.pgm");
}

void verticalTranslatePGM(struct imageNB* img, int decal)
{
    struct imageNB tr;
    tr.width = img->width;
    tr.height = img->height;
    tr.vmax = img->vmax;
    tr.color = malloc(tr.height * sizeof(unsigned char*));

    for (int ii = 0; ii < tr.height; ii++) {
        tr.color[ii] = malloc(tr.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newI = (j + decal) % img->height;
            newI = (newI < 0) ? img->height + newI : newI;
            tr.color[newI][i] = img->color[j][i];
        }
    }

    savePGM(&tr, "./images/result/translated_image.pgm");
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
        tr.red[i] = malloc(tr.width * sizeof(unsigned char));
        tr.green[i] = malloc(tr.width * sizeof(unsigned char));
        tr.blue[i] = malloc(tr.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int newJ = (j + decal) % img->width;
            newJ = (newJ < 0) ? img->width + newJ : newJ;
            tr.red[i][newJ] = img->red[i][j];
            tr.green[i][newJ] = img->green[i][j];
            tr.blue[i][newJ] = img->blue[i][j];
        }
    }

    savePPM(&tr, "./images/result/translated_image.ppm");
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
        tr.red[i] = malloc(tr.width * sizeof(unsigned char));
        tr.green[i] = malloc(tr.width * sizeof(unsigned char));
        tr.blue[i] = malloc(tr.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int newI = (j + decal) % img->height;
            newI = (newI < 0) ? img->height + newI : newI;
            tr.red[newI][i] = img->red[j][i];
            tr.green[newI][i] = img->green[j][i];
            tr.blue[newI][i] = img->blue[j][i];
        }
    }

    savePPM(&tr, "./images/result/translated_image.ppm");
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

// void histogramme(struct imageNB* img)
// {
//     // Create a histogram with 256 bins (assuming 8-bit grayscale image)
//     int histogram[256] = {0};

//     // Calculate histogram
//     for (int i = 0; i < img->width; i++) {
//         for (int j = 0; j < img->height; j++) {
//             int intensity = img->color[j][i];
//             histogram[intensity]++;
//         }
//     }

//     // Find the maximum histogram value to scale the histogram
//     int maxHistogramValue = 0;
//     for (int i = 0; i < 256; i++) {
//         if (histogram[i] > maxHistogramValue) {
//             maxHistogramValue = histogram[i];
//         }
//     }

//     // Create an image to represent the histogram
//     struct imageNB histo;
//     histo.width = 256; // 256 bins
//     histo.height = maxHistogramValue + 1; // Add 1 to include intensity 0
//     histo.vmax = 255; // Assuming 8-bit intensity values
//     histo.color = malloc(histo.height * sizeof(unsigned char*));

//     for (int ii = 0; ii < histo.height; ii++) {
//         histo.color[ii] = malloc(histo.width * sizeof(unsigned char));
//         for (int jj = 0; jj < histo.width; jj++) {
//             histo.color[ii][jj] = 0; // Initialize to black
//         }
//     }

//     // Populate the histogram image
//     for (int i = 0; i < 256; i++) {
//         int normalizedValue = (histogram[i] * histo.height) / maxHistogramValue;

//         // Draw a vertical line in the histogram image
//         for (int j = 0; j < normalizedValue; j++) {
//             histo.color[histo.height - 1 - j][i] = 255; // Set intensity value (you may adjust this based on your requirements)
//         }
//     }

//     // Save histogram as PGM image
//     savePGM(&histo, "./images/result/histogramme.pgm");
// }

void generateHistogramGray(struct imageNB* image) {
    FILE* file = fopen("./images/result/histo.pgm", "w");
    if (!file) {
        fprintf(stderr, "Erreur lors de la création du fichier PGM pour l'histogramme.\n");
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "256 256\n"); // Taille de l'histogramme
    fprintf(file, "255\n"); // Valeur maximale d'intensité

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



// --------------------------------------------------------------------------------------------------------------------

void floutagePGM(struct imageNB* img, int blurDegree)
{
    struct imageNB blurred;
    blurred.width = img->width;
    blurred.height = img->height;
    blurred.vmax = img->vmax;
    blurred.color = malloc(blurred.height * sizeof(unsigned char*));

    for (int ii = 0; ii < blurred.height; ii++) {
        blurred.color[ii] = malloc(blurred.width * sizeof(unsigned char));
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
            blurred.color[j][i] = sum / (kernelSize * kernelSize); // Normalize by the sum of kernel values
        }
    }

    // Free the dynamically allocated memory for the kernel
    for (int i = 0; i < kernelSize; i++) {
        free(kernel[i]);
    }
    free(kernel);

    savePGM(&blurred, "./images/result/blurred.pgm");
}

void floutagePPM(struct imageRGB* img, int blurDegree)
{
    struct imageRGB blurred;
    blurred.width = img->width;
    blurred.height = img->height;

    blurred.red = malloc(blurred.height * sizeof(unsigned char*));
    blurred.green = malloc(blurred.height * sizeof(unsigned char*));
    blurred.blue = malloc(blurred.height * sizeof(unsigned char*));

    for (int i = 0; i < blurred.height; i++) {
        blurred.red[i] = malloc(blurred.width * sizeof(unsigned char));
        blurred.green[i] = malloc(blurred.width * sizeof(unsigned char));
        blurred.blue[i] = malloc(blurred.width * sizeof(unsigned char));
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
            blurred.red[j][i] = sumRed / (kernelSize * kernelSize); // Normalize by the sum of kernel values
            blurred.green[j][i] = sumGreen / (kernelSize * kernelSize);
            blurred.blue[j][i] = sumBlue / (kernelSize * kernelSize);
        }
    }

    // Free the dynamically allocated memory for the kernel
    for (int i = 0; i < kernelSize; i++) {
        free(kernel[i]);
    }
    free(kernel);

    savePPM(&blurred, "./images/result/blurred.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void pixeliserPGM(struct imageNB* img, int pixelSize)
{
    struct imageNB pixelized;
    pixelized.width = img->width;
    pixelized.height = img->height;
    pixelized.vmax = img->vmax;
    pixelized.color = malloc(pixelized.height * sizeof(unsigned char*));

    for (int ii = 0; ii < pixelized.height; ii++) {
        pixelized.color[ii] = malloc(pixelized.width * sizeof(unsigned char));
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
                    pixelized.color[j + kj][i + ki] = avgIntensity;
                }
            }
        }
    }

    savePGM(&pixelized, "./images/result/pixelized.pgm");
}

void pixeliserPPM(struct imageRGB* img, int pixelSize)
{
    struct imageRGB pixelized;
    pixelized.width = img->width;
    pixelized.height = img->height;

    pixelized.red = malloc(pixelized.height * sizeof(unsigned char*));
    pixelized.green = malloc(pixelized.height * sizeof(unsigned char*));
    pixelized.blue = malloc(pixelized.height * sizeof(unsigned char*));

    for (int i = 0; i < pixelized.height; i++) {
        pixelized.red[i] = malloc(pixelized.width * sizeof(unsigned char));
        pixelized.green[i] = malloc(pixelized.width * sizeof(unsigned char));
        pixelized.blue[i] = malloc(pixelized.width * sizeof(unsigned char));
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
                    pixelized.red[j + kj][i + ki] = avgRed;
                    pixelized.green[j + kj][i + ki] = avgGreen;
                    pixelized.blue[j + kj][i + ki] = avgBlue;
                }
            }
        }
    }

    savePPM(&pixelized, "./images/result/pixelized.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void contrastPGM(struct imageNB* img, float factor)
{
    struct imageNB contrastAdjusted;
    contrastAdjusted.width = img->width;
    contrastAdjusted.height = img->height;
    contrastAdjusted.vmax = img->vmax;
    contrastAdjusted.color = malloc(contrastAdjusted.height * sizeof(unsigned char*));

    for (int ii = 0; ii < contrastAdjusted.height; ii++) {
        contrastAdjusted.color[ii] = malloc(contrastAdjusted.width * sizeof(unsigned char));
    }

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            float adjustedIntensity = (img->color[j][i] - img->vmax / 2.0) * factor + img->vmax / 2.0;

            adjustedIntensity = (adjustedIntensity < 0) ? 0 : adjustedIntensity;
            adjustedIntensity = (adjustedIntensity > img->vmax) ? img->vmax : adjustedIntensity;

            contrastAdjusted.color[j][i] = (unsigned char)adjustedIntensity;
        }
    }

    savePGM(&contrastAdjusted, "./images/result/contrastAdjusted.pgm");
}

void contrastPPM(struct imageRGB* img, float factor)
{
    struct imageRGB contrastAdjusted;
    contrastAdjusted.width = img->width;
    contrastAdjusted.height = img->height;

    contrastAdjusted.red = malloc(img->height * sizeof(unsigned char*));
    contrastAdjusted.green = malloc(img->height * sizeof(unsigned char*));
    contrastAdjusted.blue = malloc(img->height * sizeof(unsigned char*));

    for (int i = 0; i < img->height; i++) {
        contrastAdjusted.red[i] = malloc(img->width * sizeof(unsigned char));
        contrastAdjusted.green[i] = malloc(img->width * sizeof(unsigned char));
        contrastAdjusted.blue[i] = malloc(img->width * sizeof(unsigned char));
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

            contrastAdjusted.red[j][i] = (unsigned char)adjustedRed;
            contrastAdjusted.green[j][i] = (unsigned char)adjustedGreen;
            contrastAdjusted.blue[j][i] = (unsigned char)adjustedBlue;
        }
    }

    savePPM(&contrastAdjusted, "./images/result/contrastAdjusted.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void scalePGM(struct imageNB* img, float scale)
{
    int newWidth = (int)(img->width * scale);
    int newHeight = (int)(img->height * scale);

    struct imageNB scaledImg;
    scaledImg.width = newWidth;
    scaledImg.height = newHeight;
    scaledImg.vmax = img->vmax;

    scaledImg.color = malloc(newHeight * sizeof(unsigned char*));
    for (int ii = 0; ii < newHeight; ii++) {
        scaledImg.color[ii] = malloc(newWidth * sizeof(unsigned char));
    }

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int originalX = (int)(i / scale);
            int originalY = (int)(j / scale);

            originalX = (originalX < 0) ? 0 : originalX;
            originalY = (originalY < 0) ? 0 : originalY;
            originalX = (originalX >= img->width) ? img->width - 1 : originalX;
            originalY = (originalY >= img->height) ? img->height - 1 : originalY;

            scaledImg.color[j][i] = img->color[originalY][originalX];
        }
    }

    savePGM(&scaledImg, "./images/result/scaled_image.pgm");
}

void scalePPM(struct imageRGB* img, float scale)
{
    int newWidth = (int)(img->width * scale);
    int newHeight = (int)(img->height * scale);

    struct imageRGB scaledImg;
    scaledImg.width = newWidth;
    scaledImg.height = newHeight;

    scaledImg.red = malloc(newHeight * sizeof(unsigned char*));
    scaledImg.green = malloc(newHeight * sizeof(unsigned char*));
    scaledImg.blue = malloc(newHeight * sizeof(unsigned char*));

    for (int i = 0; i < newHeight; i++) {
        scaledImg.red[i] = malloc(newWidth * sizeof(unsigned char));
        scaledImg.green[i] = malloc(newWidth * sizeof(unsigned char));
        scaledImg.blue[i] = malloc(newWidth * sizeof(unsigned char));
    }

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int originalX = (int)(i / scale);
            int originalY = (int)(j / scale);

            originalX = (originalX < 0) ? 0 : originalX;
            originalY = (originalY < 0) ? 0 : originalY;
            originalX = (originalX >= img->width) ? img->width - 1 : originalX;
            originalY = (originalY >= img->height) ? img->height - 1 : originalY;

            scaledImg.red[j][i] = img->red[originalY][originalX];
            scaledImg.green[j][i] = img->green[originalY][originalX];
            scaledImg.blue[j][i] = img->blue[originalY][originalX];
        }
    }

    savePPM(&scaledImg, "./images/result/scaled_image.ppm");
}

// --------------------------------------------------------------------------------------------------------------------

void luminositePGM(struct imageNB* img, int brightness)
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

void luminositePPM(struct imageRGB* img, int brightness)
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
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------


#endif