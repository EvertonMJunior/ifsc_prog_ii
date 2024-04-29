#include "contato.h"

typedef struct item_agenda ItemAgenda;
typedef struct agenda Agenda;

Agenda *cria_agenda();
void insere_contato(Agenda *agenda, Contato *contato);
void lista_contatos(Agenda *agenda);
Contato *busca_contato(Agenda *agenda, char *nome);
void remove_contato(Agenda *agenda, char *nome);
void atualiza_contato(Agenda *agenda, char *nome, Contato *contato);
void remove_duplicados(Agenda *agenda);
void libera_agenda(Agenda *agenda);