#include <iostream>
#include "tabtenn0.h"

int main(void)
{
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizarrd", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    cout << "\n";
}