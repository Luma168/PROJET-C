#ifndef _IMAGE_
#define _IMAGE_
#include <stdio.h>

struct imageNB{
    int width;
    int height;
    unsigned char** color;
    int vmax;
};

struct imageRGB{
    int width;
    int height;
    unsigned char ** red;
    unsigned char ** green;
    unsigned char ** blue;
};

// ------------------------------------------------------------------------------------------------------------------------------
void loadPGM(struct imageNB* img, char* nomImage)
{
    FILE*fichier = fopen(nomImage, "rb");

    if(fichier != NULL){
        char chaine [3];
        int verif = fscanf(fichier,"%s", chaine);

        printf("%s\n", chaine);

        if (chaine[1] == '5') // Egal au format p5
        {
            fscanf(fichier, "%d %d", &img->width, &img->height);

            fscanf(fichier, "%d", &img->vmax);

            img->color=malloc(img->height * sizeof(unsigned char*));
            if(img->color == NULL) printf("ERROR");
            int i;
            int j;

            for (i = 0; i < img->height; i++) {
                img->color[i]= malloc(img->width * sizeof(unsigned char));
                if(img->color[i] == NULL) printf("ERROR %d",i);
            }

            printf("Height = %d\nWidth = %d, %d\n", img->height, img->width,img->vmax);
            for (i=0; i < img->width; i++ ){
                for (j=0; j<img->height; j++){
                    unsigned char tmp;
                    fread(&tmp, sizeof(unsigned char), 1, fichier);
                    img->color[i][j] = tmp;
                }
            }
            fclose(fichier);
        }
        else
        {
            printf(" format inconnu\n");
        }
    }else{
    printf("--> %s est introuvable \n", nomImage);
    }
}

void savePGM(struct imageNB* img, char* nomImage)
{
    FILE*fichier = fopen(nomImage, "wb");
    if(fichier != NULL){
        fprintf(fichier, "P5\n");
        fprintf(fichier, "%d %d\n255\n", img->width, img->height);
        unsigned char tmp = 0;
        int i = 0;
        int j = 0;
        for (i=0; i < img->width; i++ ){
            for (j=0; j<img->height; j++){
                tmp = (unsigned char) (img->color[i][j]);
                fwrite(&tmp, sizeof(unsigned char), 1, fichier);
            }
        }
        fclose(fichier);
    }else{
        printf("Creation du fichier impossible %s \n", nomImage);
    }
}
// ------------------------------------------------------------------------------------------------------------------------------
void loadPPM(struct imageRGB* img, char* nomImage) {
    FILE* fichier = fopen(nomImage, "rb");

    if (fichier != NULL) {
        char chaine[3];
        int verif = fscanf(fichier, "%s", chaine);

        if (verif != 1 || chaine[1] != '6') {
            printf("Format inconnu\n");
            fclose(fichier);
            return;
        }

        fscanf(fichier, "%d %d", &img->width, &img->height);

        int vmax;
        fscanf(fichier, "%d", &vmax);

        img->red = malloc(img->height * sizeof(unsigned char*));
        img->green = malloc(img->height * sizeof(unsigned char*));
        img->blue = malloc(img->height * sizeof(unsigned char*));

        for (int i = 0; i < img->height; i++) {
            img->red[i] = malloc(img->width * sizeof(unsigned char));
            img->green[i] = malloc(img->width * sizeof(unsigned char));
            img->blue[i] = malloc(img->width * sizeof(unsigned char));
        }

        printf("Height = %d\nWidth = %d, %d\n", img->height, img->width, vmax);

        for (int i = 0; i < img->width; i++) {
            for (int j = 0; j < img->height; j++) {
                unsigned char tmp[3];
                fread(tmp, sizeof(unsigned char), 3, fichier);
                img->red[i][j] = tmp[0];
                img->green[i][j] = tmp[1];
                img->blue[i][j] = tmp[2];
            }
        }

        fclose(fichier);
    } else {
        printf("--> %s est introuvable\n", nomImage);
    }
}

void savePPM(struct imageRGB* img, char* nomImage) {
    FILE* fichier = fopen(nomImage, "wb");
    if (fichier != NULL) {
        fprintf(fichier, "P6\n");
        fprintf(fichier, "%d %d\n255\n", img->width, img->height);

        for (int i = 0; i < img->width; i++) {
            for (int j = 0; j < img->height; j++) {
                unsigned char tmp[3] = {img->green[i][j], img->blue[i][j], img->red[i][j]};
                fwrite(tmp, sizeof(unsigned char), 3, fichier);
            }
        }

        fclose(fichier);
    } else {
        printf("Création du fichier impossible %s\n", nomImage);
    }
}
#endif