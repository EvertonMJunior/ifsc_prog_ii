#include "abb_aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NoABB *abb_cria()
{
    return NULL;
}

NoABB *abb_insere(NoABB *a, int mat, char *nome, float media)
{
    if (a == NULL)
    {
        NoABB *novo = (NoABB *)malloc(sizeof(NoABB));
        novo->info = (Aluno *)malloc(sizeof(Aluno));
        novo->info->matricula = mat;
        novo->info->nome = strdup(nome);
        novo->info->media = media;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (media < a->info->media)
        a->esq = abb_insere(a->esq, mat, nome, media);
    else
        a->dir = abb_insere(a->dir, mat, nome, media);

    return a;
}

void abb_imprime(NoABB *a)
{
    if (a != NULL)
    {
        abb_imprime(a->esq);
        printf("Matricula: %d, Nome: %s, Media: %.2f\n", a->info->matricula, a->info->nome, a->info->media);
        abb_imprime(a->dir);
    }
}

void abb_libera(NoABB *a)
{
    if (a != NULL)
    {
        abb_libera(a->esq);
        abb_libera(a->dir);
        free(a->info->nome);
        free(a->info);
        free(a);
    }
}

void abb_alunoComMaiorMedia(NoABB *a)
{
    if (a == NULL)
    {
        printf("Árvore vazia.\n");
        return;
    }

    while (a->dir != NULL)
    {
        a = a->dir;
    }

    printf("Aluno com maior média:\n");
    printf("Matricula: %d, Nome: %s, Media: %.2f\n", a->info->matricula, a->info->nome, a->info->media);
}

int abb_contaAprovados(NoABB *a)
{
    if (a == NULL)
        return 0;

    if (a->info->media < 6.0)
        return abb_contaAprovados(a->dir);

    return 1 + abb_contaAprovados(a->esq) + abb_contaAprovados(a->dir);
}

void abb_imprimeAprovados_aux(NoABB *a)
{
    if (a != NULL)
    {
        abb_imprimeAprovados_aux(a->dir);
        if (a->info->media >= 6.0)
            printf("Matricula: %d, Nome: %s, Media: %.2f\n", a->info->matricula, a->info->nome, a->info->media);
        abb_imprimeAprovados_aux(a->esq);
    }
}

void abb_imprimeAprovados(NoABB *a)
{
    printf("Alunos aprovados (ordem decrescente de média):\n");
    abb_imprimeAprovados_aux(a);
}

int abb_contaIntervalo(NoABB *a, float min, float max)
{
    if (a == NULL)
        return 0;

    if (a->info->media < min)
        return abb_contaIntervalo(a->dir, min, max);

    if (a->info->media > max)
        return abb_contaIntervalo(a->esq, min, max);

    return 1 + abb_contaIntervalo(a->esq, min, max) + abb_contaIntervalo(a->dir, min, max);
}
