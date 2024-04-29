#include "agenda.h"
#include <stdio.h>

void limpa_console()
{
    printf("\033[H\033[J");
}

void aguarda_input()
{
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

Contato *le_contato()
{
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    int dia, mes;

    printf("Digite o nome do contato: ");
    scanf("%s", nome);
    printf("Digite o telefone do contato: ");
    scanf("%s", telefone);
    printf("Digite o celular do contato: ");
    scanf("%s", celular);
    printf("Digite o email do contato: ");
    scanf("%s", email);
    printf("Digite o dia do aniversário do contato: ");
    scanf("%d", &dia);
    printf("Digite o mês do aniversário do contato: ");
    scanf("%d", &mes);

    Data *data = cria_data(dia, mes);
    Contato *contato = cria_contato(nome, telefone, celular, email, data);

    return contato;
}

void mostra_menu()
{
    limpa_console();
    printf("1 - Inserir Contato\n");
    printf("2 - Listar Contatos\n");
    printf("3 - Buscar Contato\n");
    printf("4 - Editar Contato\n");
    printf("5 - Remover Contato\n");
    printf("6 - Remover Contatos Duplicados\n");
    printf("7 - Sair\n");
    printf("Digite a opção desejada: ");
}

int main()
{
    Agenda *agenda = cria_agenda();
    int opcao = 0;

    while (opcao != 7)
    {
        mostra_menu();
        scanf("%d", &opcao);
        limpa_console();

        if (opcao == 1)
        {
            Contato *contato = le_contato();
            insere_contato(agenda, contato);
        }
        else if (opcao == 2)
        {
            lista_contatos(agenda);
        }
        else if (opcao == 3)
        {
            char nome[100];
            printf("Digite o nome do contato: ");
            scanf("%s", nome);
            Contato *contato = busca_contato(agenda, nome);
            if (contato != NULL)
            {
                printf("Nome: %s\n", contato->nome);
                printf("Telefone: %s\n", contato->telefone);
                printf("Celular: %s\n", contato->celular);
                printf("Email: %s\n", contato->email);
                printf("Data de Aniversário: %d/%d\n", contato->data_aniversario->dia, contato->data_aniversario->mes);
            }
            else
            {
                printf("Contato não encontrado\n");
            }
        }
        else if (opcao == 4)
        {
            char nome[100];
            printf("Digite o nome do contato: ");
            scanf("%s", nome);
            Contato *contato = busca_contato(agenda, nome);
            if (contato != NULL)
            {
                printf("Digite os novos dados do contato:\n");
                Contato *novo_contato = le_contato();
                atualiza_contato(agenda, nome, novo_contato);
            }
            else
            {
                printf("Contato não encontrado\n");
            }
        }
        else if (opcao == 5)
        {
            char nome[100];
            printf("Digite o nome do contato: ");
            scanf("%s", nome);
            remove_contato(agenda, nome);
        }
        else if (opcao == 6)
        {
            remove_duplicados(agenda);
        }
        else if (opcao == 7)
        {
            break;
        }
        else
        {
            printf("Opção inválida\n");
            opcao = 0;
        }
        aguarda_input();
    }
    libera_agenda(agenda);

    return 0;
}