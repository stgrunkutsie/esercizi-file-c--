#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main()    //STA PER INIZIARE + sgara sa solo fare questo (non e vero) [neanche questo] {tipico codice quasi funzionante in HolyC}
{
    FILE *pFileInput, *pFileOutput;         //puntatori ai file input.txt e output.txt per leggere l'indirizzo
    int errInputOpen, errOutputOpen;        //errori di apertura dei file
    char buffer[69 + 1];                    //carattere buffer dove salvare il testo del file

    errInputOpen = fopen_s(&pFileInput, "input.txt", "r");          //apertura file input.txt
    errOutputOpen = fopen_s(&pFileOutput, "output.txt", "w");       //apertura file output.txt

    if(errInputOpen != 0)   //file non trovato
    {
        cout << "File input.txt non trovato";
        system("pause");

        return 404;
    }
    //ok gg l'hai trovato

    while (fgets(buffer, 69, pFileInput) != NULL)   //legge il file e lo salva in buffer + smette di ciclare quando finisce il testo
    {
        fputs(buffer, pFileOutput);         //scrive il testo di input.txt su output.txt tramite il buffer
        cout << buffer;                     //lo stampa pure, perchè mi piace stampare
    }

    fclose(pFileInput);         //e la fine
    fclose(pFileOutput);        //anche qua e la fine

    return 0;
}