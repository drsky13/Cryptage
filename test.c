#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"

int main ()
{
  int quitter=1;

  while (quitter)
  {
    quitter = menu();
    switch (quitter)
    {
      case 1:
        cryptePhrase();
        break;
      case 2:
        decryptageCle();
        break;
      case 3:
        decrypteSansCle();
        break;
      case 4:
        cryptageVegenere();
        break;
      case 5:
        decryptageVegenere();
        break;
      default :
        break;
    }
  }
}
