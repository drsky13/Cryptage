#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void decryptageCle ()
{
  int i=0, diff, test=1, taille, cle;
  char* phrase=NULL;

  //récupération des info sur la phrase à crypter
  printf("Qu'elle taille fait la phrase à decrypter (ordre grandeur) : ");
  scanf ("%d", &taille);
  //incrementation, place pour symbole fin de phrase
  taille++;

  //verification si la variable taille est bien supérieur à 0
  if (taille > 0)
  {
    phrase = malloc(taille*sizeof(char));
    if (phrase == NULL)
    {
      exit (0);
    }
    purge();
    printf("rentrer votre phrase : ");
    if(!lirePhrase (phrase, taille))
    {
      printf("erreur");
    }
    printf("entrer un entier : ");
    scanf ("%d", &cle);
    cle=cle%26;
  }
  else
    printf("la taille de votre phrase doit être supérieur à 0");

  while ((i<taille) && test)
  {
    if (phrase[i]=='\0')
    {
      test=0;
    }
    else if ((phrase[i]<'a')||(phrase[i]>'z'))
    {}
    else
    {
      diff=phrase[i]-'a';
      if ((diff-cle) >= 0)
      {
        phrase[i]-=cle;
      }
      else
      {
        phrase[i]='z'-(cle-diff)+1;
      }
    }
    i++;
  }
  printf("\n-----MESSAGE DECRYPTE-----\n");
  for (i=0 ; i<taille ; i++)
  {
    printf("%c", phrase[i]);
  }
  printf("\n--------------------------\n");
  free(phrase);
}

void cryptePhrase ()
{
  int i=0, diff, test=1, taille, cle;
  char* phrase=NULL;
  //récupération des info sur la phrase à crypter
  printf("Qu'elle taille fait la phrase à crypter (ordre grandeur) : ");
  scanf ("%d", &taille);
  //incrementation, place pour symbole fin de phrase
  taille++;
  //verification si la variable taille est bien supérieur à 0
  if (taille > 0)
  {
    phrase = malloc(taille*sizeof(char));
    if (phrase == NULL)
    {
      exit (0);
    }
    purge();
    printf("rentrer votre phrase : ");
    if(!lirePhrase (phrase, taille))
    {
      printf("erreur");
    }
    printf("entrer un entier : ");
    scanf ("%d", &cle);
    cle=cle%26;
  }
  else
    printf("la taille de votre phrase doit être supérieur à 0");

  while ((i<taille) && test )
  {
    if (phrase[i]=='\0')
    {
      test=0;
    }
    else if ((phrase[i]<'a')||(phrase[i]>'z'))
    {}
    else
    {
      diff='z'-phrase[i];
      if ((diff-cle) >= 0)
      {
        phrase[i]+=cle;
      }
      else
      {
        phrase[i]='a'+(cle-diff)-1;
      }
    }
    i++;
  }
  printf("\n-----MESSAGE CRYPTE-----\n");
  for (i=0 ; i<taille ; i++)
  {
    printf("%c", phrase[i]);
  }
  printf("\n------------------------\n");
  free(phrase);
}

void decrypteSansCle ()
{
  int i, longueur;
  char* phrase=NULL;
  printf("quel taille fait le message à decrypter ?");
  scanf("%d", &longueur);
  longueur++;
  if(taille>0)
  {
    phrase = malloc(longueur*sizeof(char))
  }
}


int menu ()
{
  int choix, test=1;
  do {
    printf("\nbonjour, bienvenu dans ce programme de cryptage. vous souhaitez : \n1 : crypter un message\n");
    printf("2 : decrypter un message avec une cle\n3 : decrypter un message sans cle\n0 : quitter\n--> ");
    scanf("%d", &choix);
    if ((choix<0)||(choix>3))
    {
      printf("ce choix n'existe pas");
      test=0;
    }
    else
      test=1;
    purge();
  } while(!test);
  return choix;
}
