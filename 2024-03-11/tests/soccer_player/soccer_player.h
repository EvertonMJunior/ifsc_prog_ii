// Implemente um TAD Jogador de Futebol.

// - Cada jogador possui os campos nome, jogos, gols e assistências.

// - Implemente as operações:

// (a) Atribui: atribui valores para os campos;

// (b) Imprime: imprime os dados / estatísticas do jogador;

// (c) EhBom: testa se o jogador é bom (defina seu próprio critério de bom jogador).

// - Crie o main para testar seu TAD;

// - Utilize alocação dinâmica de memória e modularização.

typedef struct soccer_player SoccerPlayer;

SoccerPlayer *attribute_player(char *name, int games, int goals, int assists);
void print_player(SoccerPlayer *player);
int is_player_good(SoccerPlayer *player);