#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char format[3]; // Ajout d'un champ pour le format
    int width;
    int height;
    int max_value;
    unsigned char** data;
} Image;

Image* readImage(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));

    // Lire le format de l'image (P2 pour PGM, P3 pour PPM)
    fscanf(file, "%2s", img->format);

    // Lire les dimensions de l'image
    int width, height, max_value;
    fscanf(file, "%d %d %d", &width, &height, &max_value);

    // Allouer de la mémoire pour la structure Image
    img->width = width;
    img->height = height;
    img->max_value = max_value;

    // Allouer de la mémoire pour les pixels de l'image
    img->data = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        img->data[i] = (unsigned char*)malloc(width * sizeof(unsigned char));
    }

    // Lire les pixels de l'image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%hhu", &img->data[i][j]);
        }
    }

    // Fermer le fichier
    fclose(file);

    return img;
}

void saveImage(const char* filename, const Image* img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Écrire l'en-tête du fichier image
    fprintf(file, "%s\n", img->format);

    fprintf(file, "%d %d\n%d\n", img->width, img->height, img->max_value);

    // Écrire les pixels de l'image
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(file, "%d ", img->data[i][j]);
        }
        fprintf(file, "\n");
    }

    // Fermer le fichier
    fclose(file);
}

int main() {
    const char* filename = "./images/pgm/brooklyn.512.pgm";  // Remplacez par le nom de votre fichier image
    Image* img = readImage(filename);

    // Vérifier si la lecture a réussi
    if (img) {
        printf("Image lue avec succès!\n");
        // Ajoutez le code ici pour effectuer d'autres opérations sur l'image
        // ...

        // // Libérer la mémoire allouée
        // for (int i = 0; i < img->height; i++) {
        //     free(img->data[i]);
        // }
        // free(img->data);
        // free(img);

        const char* outputFilename = "./images/result/aaa.ppm";  // Remplacez par le nom de sortie souhaité
        saveImage(outputFilename, img);

        printf("Image sauvegardée avec succès!\n");
    }

    return 0;
}
