#include "abb_aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    NoABB *raiz = abb_cria();
    int opcao, matricula;
    char nome[MAX_NOME];
    float media, min, max;

    do
    {
        printf("\nMenu de Opções:\n");
        printf("1. Inserir aluno\n");
        printf("2. Imprimir todos os alunos\n");
        printf("3. Imprimir aluno com maior média\n");
        printf("4. Contar alunos aprovados\n");
        printf("5. Imprimir alunos aprovados\n");
        printf("6. Contar alunos no intervalo de médias\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            printf("Matrícula: ");
            scanf("%d", &matricula);
            limparBuffer();
            printf("Nome: ");
            fgets(nome, MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = 0;
            printf("Média: ");
            scanf("%f", &media);
            limparBuffer();
            raiz = abb_insere(raiz, matricula, nome, media);
            break;
        case 2:
            abb_imprime(raiz);
            break;
        case 3:
            abb_alunoComMaiorMedia(raiz);
            break;
        case 4:
            printf("Número de alunos aprovados: %d\n", abb_contaAprovados(raiz));
            break;
        case 5:
            abb_imprimeAprovados(raiz);
            break;
        case 6:
            printf("Média mínima: ");
            scanf("%f", &min);
            printf("Média máxima: ");
            scanf("%f", &max);
            printf("Número de alunos no intervalo: %d\n", abb_contaIntervalo(raiz, min, max));
            break;
        case 7:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    abb_libera(raiz);
    return 0;
}
