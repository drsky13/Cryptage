#ifndef HEADER
#define HEADER

void purge ();
int lirePhrase (char* phrase, int longueur);
void cryptePhrase ();
void decryptageCle ();
void decrypteSansCle ();
char tableauVegenere();
void cryptageVegenere ();
void decryptageVegenere();
void initTableauFrequence (int tableau[2][26]);
void analyseFrequentiel ();


int menu ();

#endif
