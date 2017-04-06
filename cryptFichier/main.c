#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctFichier.h"
#include "vegenere.h"

int main ()
{
  int compteur=0, taille;
  //int* ptCompteur=&compteur;
  char* cle=NULL;
  char caractere, caractereCrypt;
  FILE* fichier=NULL;
  FILE* fichierCrypt=NULL;
  ouvertureFichier(&fichier, &fichierCrypt);
  taille=allocationDynamique(&cle);
  if(!taille){
    exit(0);
  }
  printf("\n taille cle pal - > %d\n", taille);
//récupération de la clé de cryptage
  printf("rentrer votre clé : ");
  purge();
  if(!lirePhrase(cle, taille)){
    printf("erreur lors de la récupération de la clé");
    exit(0);
  }
  //printf("\n taille cle - > %d\n", taille);

  do{
    caractere=carFichier(fichier);
    caractereCrypt=filtreCar(caractere, compteur, cle);
    //printf("%c - > %c\n", caractere, caractereCrypt);
    if(caractereCrypt!=EOF){
    insertionCar(caractereCrypt, fichierCrypt);
    }
    //insertionCar(filtreCar(caractere, compteur, cle), fichierCrypt);
    if ((caractere>='A' && caractere<='Z') || (caractere>='a' && caractere<='z')){
      compteur++;
    }
  }while(caractere!=EOF);

  //fermeture des fichiers
  fclose(fichier);
  fclose(fichierCrypt);
  free(cle);
  printf("-----fichiers fermés-----\n");
  return 0;
}
