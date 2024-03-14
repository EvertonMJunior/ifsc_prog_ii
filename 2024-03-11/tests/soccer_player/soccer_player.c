#include "soccer_player.h"

#include <stdlib.h>
#include <stdio.h>

struct soccer_player
{
    char *name;
    int games;
    int goals;
    int assists;
};

SoccerPlayer *attribute_player(char *name, int games, int goals, int assists)
{
    SoccerPlayer *player = malloc(sizeof(SoccerPlayer));
    player->name = name;
    player->games = games;
    player->goals = goals;
    player->assists = assists;
    return player;
}

void print_player(SoccerPlayer *player)
{
    printf("Jogador de Futebol: %s\n", player->name);
    printf("Jogos: %d\n", player->games);
    printf("Gols: %d\n", player->goals);
    printf("Assistências: %d\n", player->assists);
    printf("É bom? %s\n", is_player_good(player) ? "Sim" : "Não");
}

/*
    Essa função usa como critério para um bom jogador a quantidade de gols e assistências feitas por jogo. Um jogador é considerado bom se sua média de gols por jogo for >= 0,4 e sua média de assistências por jogo for >= 0,1.
*/
int is_player_good(SoccerPlayer *player)
{
    double goals_by_game = (double)player->goals / (double)player->games;
    double assists_by_game = (double)player->assists / (double)player->games;

    if (goals_by_game >= 0.4 && assists_by_game >= 0.1)
    {
        return 1;
    }
    return 0;
}