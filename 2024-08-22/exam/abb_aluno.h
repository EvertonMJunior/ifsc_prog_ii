#ifndef ABB_ALUNO_H
#define ABB_ALUNO_H

typedef struct aluno
{
    int matricula;
    char *nome;
    float media;
} Aluno;

typedef struct noABB
{
    Aluno *info;
    struct noABB *esq;
    struct noABB *dir;
} NoABB;

NoABB *abb_cria();
NoABB *abb_insere(NoABB *a, int mat, char *nome, float media);
void abb_imprime(NoABB *a);
void abb_libera(NoABB *a);
void abb_alunoComMaiorMedia(NoABB *a);
int abb_contaAprovados(NoABB *a);
void abb_imprimeAprovados(NoABB *a);
int abb_contaIntervalo(NoABB *a, float min, float max);

#endif
