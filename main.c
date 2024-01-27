#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "effects.h"

int main(){
    char* start = NULL;
    size_t buffer_size = 0;

    printf("Saisissez le chemin vers l'image: ");
    // getline pour saisir la ligne complète, y compris les espaces
    ssize_t imgPath = getline(&start, &buffer_size, stdin);

    if (imgPath != -1) {
        // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
        if (start[imgPath - 1] == '\n') {
            start[imgPath - 1] = '\0';
        }

        // Trouver l'extension du fichier
        char* file_extension = strrchr(start, '.');
        if (file_extension != NULL) {
            // Comparer l'extension pour déterminer le type d'image
            if (strcmp(file_extension, ".pgm") == 0) {
                struct imageNB* img;
                loadPGM(&img, start);
                // horizontalTranslatePGM(&img, 200);
                // verticalTranslatePGM(&img, 200);
                // negatifPGM(&img);
                // verticalMirrorPGM(&img);
                // horizontalMirrorPGM(&img);
                // seuillagePGM(&img, 150);
                // histogramme(&img);
                // floutagePGM(&img, 5);
                // pixeliserPGM(&img, 5);
                // adjustContrastPGM(&img, 2);
                // scalePGM(&img, 0.5);
                // luminositePGM(&img, 100);
            } else if (strcmp(file_extension, ".ppm") == 0) {
                struct imageRGB* img;
                loadPPM(&img, start);
                // horizontalTranslatePPM(&img, 200);
                // verticalTranslatePPM(&img, 200);
                // negatifPPM(&img);
                // horizontalMirrorPPM(&img);
                // verticalMirrorPPM(&img);
                // seuillagePPM(&img, 250);
                // ppmToPgm(&img);
                // floutagePPM(&img, 5);
                // pixeliserPPM(&img, 5);
                // contrastPPM(&img, 3);
                // scalePPM(&img, 0.5);
                // luminositePPM(&img, 100);
            } else {
                fprintf(stderr, "Format d'image non pris en charge.\n");
            }
        } else {
            fprintf(stderr, "L'extension du fichier est introuvable.\n");
        }
        
    } else {
        fprintf(stderr, "Erreur lors de la saisie.\n");
    }

    // Libérer la mémoire allouée
    // free(filename);



    // Vérifier si la lecture a réussi
    // if (img) {
    //     printf("Image lue avec succès!\n");
    //     // Ajoutez le code ici pour effectuer d'autres opérations sur l'image
    //     // ...

    //     // Libérer la mémoire allouée
    //     for (int i = 0; i < img->height; i++) {
    //         free(img->data[i]);
    //     }
    //     free(img->data);
    //     free(img);
    // }
    return 0;
}