#include <stdio.h>

typedef struct
{
    int hora;
    int minuto;
    float tcelsius;
    float pammhg;
    char local[30];
} Meteor;

// shows the user the meteor with the lowest temperature
void mostra_min(Meteor met[], int numdados)
{
    int i;
    int min = 0;
    for (i = 1; i < numdados; i++)
    {
        if (met[i].pammhg < met[min].pammhg)
        {
            min = i;
        }
    }
    printf("A pressão mínima de %.2f mmHg occoreu às %02d:%02d, em %s.\n", met[min].pammhg, met[min].hora, met[min].minuto, met[min].local);
}

int main()
{
    printf("Digite o arquivo de entrada: ");
    char fileName[30];
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int result;
    int i = 0;
    Meteor meteors[100];

    // skips first line of headers
    fscanf(file, "%*[^\n]\n");
    do
    {
        // format: 00,00,20.0,760.0,Aracaju
        result = fscanf(file, "%d,%d,%f,%f,%30s\n", &meteors[i].hora, &meteors[i].minuto, &meteors[i].tcelsius, &meteors[i].pammhg, meteors[i].local);
        if (result == 5)
        {
            i++;
        }
        else
        {
            printf("Erro ao ler o arquivo\n");
        }
    } while (!feof(file));
    fclose(file);

    printf("Foram lidos %d dados\n", i);
    mostra_min(meteors, i);

    return 0;
}