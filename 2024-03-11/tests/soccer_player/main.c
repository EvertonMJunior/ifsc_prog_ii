#include "soccer_player.h"
#include <stdio.h>

int main()
{
    SoccerPlayer *player = attribute_player("Neymar", 100, 50, 20);
    SoccerPlayer *player2 = attribute_player("Ruim", 50, 2, 1);

    print_player(player);
    printf("\n");
    print_player(player2);

    return 0;
}