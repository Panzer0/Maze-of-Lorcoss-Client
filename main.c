#include <stdio.h>
#include <ncurses.h>


        ///ZREWORKOWAĆ REVEAL, przeniosłem większość roboty na stronę serwera
/*
int revealSurroundings(int x, int y)       //x i y to koordynaty gracza
{
    //Obsługa błędów
    if (x < 0 || x >= MAP_WIDTH || y < 0 || Y >= MAP_HEIGHT)    //Gracz nie może być poza mapą
    {
        return -1;
    }
    if(zoneType(x, y) == ŚCIANA)        //Graczu, co robisz w ścianie
    {
        return -1;
    }

    //Ujawnianie otoczenia
    for(int i = SIGHT_RANGE * -1; i <= SIGHT_RANGE; i++)    //Kolejne kolumny
    {
        if(x+i < 0) i++;                    ///TEORETYCZNIE ZAJMUJE SIĘ TYM FUNKCJA. CZY TAK NA PEWNO BĘDZIE WYDAJNIEJ?
        if(x+i >= MAP_WIDTH) break;

        for(int j = SIGHT_RANGE * -1; j <= SIGHT_RANGE; j++)    //Kolejne wiersze
        {
            if(y+j < 0) j++;
            if(y+j >= MAP_HEIGHT) break;

            obtainFieldData(x + i, y + j);      ////JEŚLI WYKRACZA POZA MAPĘ, NIC NIE ROBI
        }
    }
}
*/

void* controlMovement(void* data)
{
    while(1)        //Jedyne wyjście to break, gdy gracz poinformuje o chęci zakończenia gry
    {
        ///W tym momencie mam już chyba włączony raw(), noEcho() i w ogóle, nie?
        char action;
        timeout(1000 * SECOND_PER_TURN);        ///CZY GETCH ZWRACA NULL PRZY TIMEOUCIE?
        action = getch();

        switch(action)      ///Złączyć z komendami wyżej? Może po prostu switch(getch())?
        {
            case NULL:      ///Na pewno wysyłać w ogóle sygnał w tej sytuacji?
            case 'UP_ARROW':      ///OGARNĄĆ POPRAWNĄ NAZWĘ STRZAŁEK W ASCII
            case 'LEFT_ARROW':      ///OGARNĄĆ POPRAWNĄ NAZWĘ STRZAŁEK W ASCII
            case 'DOWN_ARROW':      ///OGARNĄĆ POPRAWNĄ NAZWĘ STRZAŁEK W ASCII
            case 'RIGHT_ARROW':      ///OGARNĄĆ POPRAWNĄ NAZWĘ STRZAŁEK W ASCII
                moveUser(action);    //Serwer zinterpretuje kierunek ruchu
                break;
            case 'Q':
            case 'q':
                exitGame();     //Informuje serwer o chęci opuszczenia gry przez gracza.
                timeout(-1);
                return NULL;    //Na pewno NULL?
            case 'B':
            case 'b':
                addEntity(BEAST);
                break;
            case 'c':
                addEntity(COIN);
                break;
            case 't'
                addEntity(TREASURE);
                break;
            case 'T':
                addEntity(LARGE_TREASURE);
                break;
        }
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
