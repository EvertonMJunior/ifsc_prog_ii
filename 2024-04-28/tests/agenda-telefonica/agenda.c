#include "agenda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct item_agenda
{
    Contato *contato;
    ItemAgenda *proximo;
};

struct agenda
{
    ItemAgenda *primeiro;
};

Agenda *cria_agenda()
{
    Agenda *agenda = malloc(sizeof(Agenda));
    agenda->primeiro = NULL;
    return agenda;
}

void insere_contato(Agenda *agenda, Contato *contato)
{
    ItemAgenda *novo_item = malloc(sizeof(ItemAgenda));
    novo_item->contato = contato;
    novo_item->proximo = NULL;

    if (agenda->primeiro == NULL)
    {
        agenda->primeiro = novo_item;
    }
    else
    {
        ItemAgenda *atual = agenda->primeiro;
        ItemAgenda *anterior = NULL;

        while (atual != NULL && strcmp(atual->contato->nome, contato->nome) < 0)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL)
        {
            novo_item->proximo = agenda->primeiro;
            agenda->primeiro = novo_item;
        }
        else
        {
            anterior->proximo = novo_item;
            novo_item->proximo = atual;
        }
    }
}

void lista_contatos(Agenda *agenda)
{
    ItemAgenda *atual = agenda->primeiro;

    while (atual != NULL)
    {
        printf("Nome: %s\n", atual->contato->nome);
        printf("Telefone: %s\n", atual->contato->telefone);
        printf("Celular: %s\n", atual->contato->celular);
        printf("Email: %s\n", atual->contato->email);
        printf("Data de Aniversário: %d/%d\n", atual->contato->data_aniversario->dia, atual->contato->data_aniversario->mes);
        printf("\n");

        atual = atual->proximo;
    }
}

Contato *busca_contato(Agenda *agenda, char *nome)
{
    ItemAgenda *atual = agenda->primeiro;

    while (atual != NULL)
    {
        if (strcmp(atual->contato->nome, nome) == 0)
        {
            return atual->contato;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void remove_contato(Agenda *agenda, char *nome)
{
    Contato *contato = busca_contato(agenda, nome);

    if (contato == NULL)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    ItemAgenda *atual = agenda->primeiro;
    ItemAgenda *anterior = NULL;

    while (atual != NULL && atual->contato != contato)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL)
    {
        agenda->primeiro = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }
}

void atualiza_contato(Agenda *agenda, char *nome, Contato *contato_atualizado)
{
    Contato *contato = busca_contato(agenda, nome);

    if (contato == NULL)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    contato->nome = contato_atualizado->nome;
    contato->telefone = contato_atualizado->telefone;
    contato->celular = contato_atualizado->celular;
}

void remove_duplicados(Agenda *agenda)
{
    ItemAgenda *atual = agenda->primeiro;
    ItemAgenda *anterior = NULL;

    while (atual != NULL)
    {
        ItemAgenda *verificador = atual->proximo;
        ItemAgenda *anterior_verificador = atual;

        while (verificador != NULL)
        {
            if (strcmp(atual->contato->nome, verificador->contato->nome) == 0)
            {
                anterior_verificador->proximo = verificador->proximo;

                free(verificador->contato->nome);
                free(verificador->contato->telefone);
                free(verificador->contato->celular);
                free(verificador->contato->email);
                free(verificador->contato->data_aniversario);
                free(verificador->contato);
                free(verificador);
                verificador = anterior_verificador;
            }

            anterior_verificador = verificador;
            verificador = verificador->proximo;
        }

        atual = atual->proximo;
    }
}

void libera_agenda(Agenda *agenda)
{
    ItemAgenda *atual = agenda->primeiro;

    while (atual != NULL)
    {
        ItemAgenda *proximo = atual->proximo;

        free(atual->contato->nome);
        free(atual->contato->telefone);
        free(atual->contato->celular);
        free(atual->contato->email);
        free(atual->contato->data_aniversario);
        free(atual->contato);
        free(atual);

        atual = proximo;
    }

    free(agenda);
}