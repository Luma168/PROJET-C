#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "image.h"
#include "effects.h"

    // char start[256];
    // printf("Saisissez le chemin vers l'image: ");

    // if(fgets(start,sizeof(start), stdin) != NULL){
    //     start[strcspn(start,"\n")] = '\0';

int main(){
    char* start = NULL;
    size_t buffer_size = 0;

    printf("Saisissez le chemin vers l'image: ");
    ssize_t imgPath = getline(&start, &buffer_size, stdin);

    if (imgPath != -1) {
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

                int choice;
                printf("Choisissez l'effet:\n");
                printf("1. Translation horizontale\n");
                printf("2. Translation verticale\n");
                printf("3. Negatif\n");
                printf("4. Miroir vertical\n");
                printf("5. Miroir horizontal\n");
                printf("6. Seuillage\n");
                printf("7. Histogramme\n");
                printf("8. Floutage\n");
                printf("9. Pixeliser\n");
                printf("10. Ajuster le contraste\n");
                printf("11. Redimensionner (scale)\n");
                printf("12. Ajuster la luminosite\n");
                printf("13. Rotate\n");

                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        // Translation horizontale
                        {
                            int decal;
                            printf("Saisissez le decalage horizontal: ");
                            scanf("%d", &decal);
                            horizontalTranslatePGM(&img, decal);
                            break;
                        }
                    case 2:
                        // Translation verticale
                        {
                            int decalV;
                            printf("Saisissez le decalage vertical: ");
                            scanf("%d", &decalV);
                            verticalTranslatePGM(&img, decalV);
                            break;
                        }
                    case 3:
                        // Négatif
                        {
                            negatifPGM(&img);
                            break;
                        }
                    case 4:
                        // Miroir vertical
                        {
                            verticalMirrorPGM(&img);
                            break;
                        }
                    case 5:
                        // Miroir horizontal
                        {
                            horizontalMirrorPGM(&img);
                            break;
                        }
                    case 6:
                        // Seuillage
                        {
                            int seuil;
                            printf("Saisissez le seuil de seuillage: ");
                            scanf("%d", &seuil);
                            seuillagePGM(&img, seuil);
                            break;
                        }
                    case 7:
                        // Histogramme
                        {
                            generateHistogramGray(&img);
                            break;
                        }
                    case 8:
                        // Floutage
                        {
                            int rayon;
                            printf("Saisissez le rayon de floutage: ");
                            scanf("%d", &rayon);
                            floutagePGM(&img, rayon);
                            break;
                        }
                    case 9:
                        // Pixeliser
                        {
                            int pixelSize;
                            printf("Saisissez la taille des pixels: ");
                            scanf("%d", &pixelSize);
                            pixeliserPGM(&img, pixelSize);
                            break;
                        }
                    case 10:
                        // Ajuster le contraste
                        {
                            float facteurContraste;
                            printf("Saisissez le facteur de contraste: ");
                            scanf("%f", &facteurContraste);
                            contrastPGM(&img, facteurContraste);
                            break;
                        }
                    case 11:
                        // Redimensionner (scale)
                        {
                            float facteurEchelle;
                            printf("Saisissez le facteur d'echelle: ");
                            scanf("%f", &facteurEchelle);
                            scalePGM(&img, facteurEchelle);
                            break;
                        }
                    case 12:
                        // Ajuster la luminosité
                        {
                            int valeurLuminosite;
                            printf("Saisissez la valeur de luminosite: ");
                            scanf("%d", &valeurLuminosite);
                            luminositePGM(&img, valeurLuminosite);
                            break;
                        }
                    case 13:
                        // Rotate
                        {
                            double angle;
                            printf("Entrez l'angle de rotation en degres : ");
                            scanf("%lf", &angle);

                            // Assurez-vous que l'angle est dans la plage souhaitée, par exemple -360 à 360 degrés
                            angle = fmod(angle, 360.0);

                            rotatePGM(&img, angle);
                            savePGM(&img, "./images/result/rotate.pgm");
                            break;
                        }
                    default:
                        fprintf(stderr, "Choix non valide.\n");
                }

            } else if (strcmp(file_extension, ".ppm") == 0) {
                struct imageRGB* img;
                loadPPM(&img, start);
                
                int choice;
                printf("Choisissez l'effet:\n");
                printf("1. Translation horizontale\n");
                printf("2. Translation verticale\n");
                printf("3. Negatif\n");
                printf("4. Miroir vertical\n");
                printf("5. Miroir horizontal\n");
                printf("6. Seuillage\n");
                printf("7. Histogramme\n");
                printf("8. Floutage\n");
                printf("9. Pixeliser\n");
                printf("10. Ajuster le contraste\n");
                printf("11. Redimensionner (scale)\n");
                printf("12. Ajuster la luminosite\n");

                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        // Translation horizontale
                        {
                            int decal;
                            printf("Saisissez le decalage horizontal: ");
                            scanf("%d", &decal);
                            horizontalTranslatePPM(&img, decal);
                            break;
                        }
                    case 2:
                        // Translation verticale
                        {
                            int decalV;
                            printf("Saisissez le decalage vertical: ");
                            scanf("%d", &decalV);
                            verticalTranslatePPM(&img, decalV);
                            break;
                        }
                    case 3:
                        // Négatif
                        {
                            negatifPPM(&img);
                            break;
                        }
                    case 4:
                        // Miroir vertical
                        {
                            verticalMirrorPPM(&img);
                            break;
                        }
                    case 5:
                        // Miroir horizontal
                        {
                            horizontalMirrorPPM(&img);
                            break;
                        }
                    case 6:
                        // Seuillage
                        {
                            int seuil;
                            printf("Saisissez le seuil de seuillage: ");
                            scanf("%d", &seuil);
                            seuillagePPM(&img, seuil);
                            break;
                        }
                    case 7:
                        // Histogramme
                        {
                            // generateHistogramRGB(&img);
                            break;
                        }
                    case 8:
                        // Floutage
                        {
                            int rayon;
                            printf("Saisissez le rayon de floutage: ");
                            scanf("%d", &rayon);
                            floutagePPM(&img, rayon);
                            break;
                        }
                    case 9:
                        // Pixeliser
                        {
                            int pixelSize;
                            printf("Saisissez la taille des pixels: ");
                            scanf("%d", &pixelSize);
                            pixeliserPPM(&img, pixelSize);
                            break;
                        }
                    case 10:
                        // Ajuster le contraste
                        {
                            float facteurContraste;
                            printf("Saisissez le facteur de contraste: ");
                            scanf("%f", &facteurContraste);
                            contrastPPM(&img, facteurContraste);
                            break;
                        }
                    case 11:
                        // Redimensionner (scale)
                        {
                            float facteurEchelle;
                            printf("Saisissez le facteur d'echelle: ");
                            scanf("%f", &facteurEchelle);
                            scalePPM(&img, facteurEchelle);
                            break;
                        }
                    case 12:
                        // Ajuster la luminosité
                        {
                            int valeurLuminosite;
                            printf("Saisissez la valeur de luminosite: ");
                            scanf("%d", &valeurLuminosite);
                            luminositePPM(&img, valeurLuminosite);
                            break;
                        }
                    default:
                        fprintf(stderr, "Choix non valide.\n");
                }
            } else {
                fprintf(stderr, "Format d'image non pris en charge.\n");
            }
        } else {
            fprintf(stderr, "L'extension du fichier est introuvable.\n");
        }
    } else {
        fprintf(stderr, "Erreur lors de la saisie.\n");
    }

    return 0;
}