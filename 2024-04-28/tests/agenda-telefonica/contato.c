#include "contato.h"
#include <stdlib.h>
#include <string.h>

Contato *cria_contato(char *nome, char *telefone, char *celular, char *email, Data *data_aniversario)
{
    Contato *contato = malloc(sizeof(Contato));

    if (contato == NULL)
    {
        return NULL;
    }

    if (strlen(nome) > 40 || strlen(telefone) > 15 || strlen(celular) > 15 || strlen(email) > 40)
    {
        free(contato);
        return NULL;
    }

    contato->nome = strdup(nome);
    contato->telefone = strdup(telefone);
    contato->celular = strdup(celular);
    contato->email = strdup(email);
    contato->data_aniversario = malloc(sizeof(Data));
    if (contato->data_aniversario != NULL)
    {
        *contato->data_aniversario = *data_aniversario;
    }

    return contato;
}