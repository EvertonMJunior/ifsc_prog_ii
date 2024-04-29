#include "data.h"

struct contato
{
    char *nome;
    char *telefone;
    char *celular;
    char *email;
    Data *data_aniversario;
};

typedef struct contato Contato;

Contato *cria_contato(char *nome, char *telefone, char *celular, char *email, Data *data_aniversario);