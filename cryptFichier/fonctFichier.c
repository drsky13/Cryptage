#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctFichier.h"
void purge ()
{
  int c;
  while (c!='\n' && c!=EOF )
  {
    c=getchar();
  }
}

int lirePhrase (char *phrase, int longueur)
{
  char* positionEntre=NULL;
  if (fgets(phrase, longueur, stdin)!=NULL)
  {
    positionEntre = strchr(phrase, '\n');

    if (positionEntre != NULL )
      *positionEntre = '\0';
    else
      purge ();

    return 1;
  }
  else
  {
    purge();
    return 0;
  }

}

void ouvertureFichier(FILE** fichier, FILE** fichierCrypt)
{
  char nomFichier[100];
  char nomDest[100];
  //récupération du nom du fichier à crypter et ouverture du fichier
  do{
    printf("chemin/nom du fichier :");
    lirePhrase(nomFichier, sizeof(nomFichier));
    *fichier=fopen(nomFichier, "r");
  }while(*fichier==NULL);
//récupération de la destination du fichier crypté
  do{
    printf("chemin/nom destination du fichier crypte : ");
    lirePhrase(nomDest, sizeof(nomDest));
    testExistenceFichier(nomDest);
    *fichierCrypt=fopen(nomDest, "a");
  }while(*fichierCrypt==NULL);

  printf("-----fichiers ouverts-----\n");
}

//fonction qui renvoie le caractère courant
//du fichier à crypter
char carFichier(FILE* fichier)
{
  char car;
  car=fgetc(fichier);
  return car;
}

// TODO: fonction pas vérifier. doute sur le parametre char.char* cle ou char cle
char carCle(char* cle, int place)
{
  int taille=strlen(cle);
  //printf("caractere cle -> %c\n", cle[place%taille]);
  return cle[place%taille];
}

int allocationDynamique(char** tableau)
{
  int taille;
  printf("quelle taille fait la phrase : ");
  scanf("%d", &taille);
//utilisation de calloc pour pouvoir utiliser sizeof pour l'appel
//de la fonction lirePhrase
  *tableau=calloc(taille, sizeof(char));
  if(*tableau==NULL){
    printf("-----l'allocation a échoué-----\n");
    return 0;
  }
  else{
    printf("-----allocation réussite-----\n");
    return taille;
  }
}

int insertionCar (char caractere, FILE* fichierCrypter)
{
  if(fputc(caractere, fichierCrypter)==EOF){
    return 0;
  }
  else{
    return 1;
  }
}

int testExistenceFichier(char* nom)
{
  FILE* fichier=NULL;
  fichier=fopen(nom, "r");
  if(fichier==NULL){
    printf("ce fichier n'existe pas. Il va être créé\n");
    return 0;
  }
  else{
    fclose(fichier);
    return 1;
  }
}
