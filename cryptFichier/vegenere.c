#include <stdio.h>
#include <stdlib.h>
#include "fonctFichier.h"

/* TODO:solution provisoire, en amélioration on pourra créer une fonction qui
initialise le tableau au démarrage du programme plutôt que de le
recréer pour chaque caractère*/

char tableauVegenere(int lig, int col)
{
  int l,c;
  char tab[26][26];
  for (l=0 ; l<26 ; l++)
  {
    for (c=0 ; c<26 ; c++)
    {
      tab[l][c]='a'+(l+c)%26;
    }
  }
  return tab[lig][col];
}

char tableauVegenereMAJ(int lig, int col)
{
  int l,c;
  char tab[26][26];
  for (l=0 ; l<26 ; l++)
  {
    for (c=0 ; c<26 ; c++)
    {
      tab[l][c]='A'+(l+c)%26;
    }
  }
  return tab[lig][col];
}

char chiffreCrypt(char chiffre, int i)
{
  if(('9'-chiffre)<i%10){
    return '0'+((i%10)-('9'-chiffre)-1);
  }
  else{
    return chiffre+(i%10);
  }
}

char filtreCar(char caractere, int i, char* cle)
{
  if (caractere>='A' && caractere<='Z'){
    return tableauVegenereMAJ(25-('Z'-carCle(cle, i)),25-('Z'-caractere));
  }
  else if(caractere>='a' && caractere<='z'){
    return tableauVegenere( 25-('z'-carCle(cle, i)), 25-('z'-caractere));
  }
  else if(caractere>='1' && caractere<='9'){
    return chiffreCrypt(25-('z'-caractere), i);
  }
  else{
    return caractere;
  }

}
