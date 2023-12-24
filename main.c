#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "images.c"

int main(){
    char* filename = NULL;
    size_t buffer_size = 0;
    char* resultfilename = NULL;

    printf("Saisissez le chemin vers l'image: ");
    // getline pour saisir la ligne complète, y compris les espaces
    ssize_t characters_read = getline(&filename, &buffer_size, stdin);

    if (characters_read != -1) {
        // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
        if (filename[characters_read - 1] == '\n') {
            filename[characters_read - 1] = '\0';
        }

        struct imageNB* img;
        loadPPM(&img, filename);
        savePPM(&img,"./images/result/aaa.ppm");
        
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