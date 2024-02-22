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
        if (met[i].tcelsius < met[min].tcelsius)
        {
            min = i;
        }
    }
    printf("Hora: %d:%d\n", met[min].hora, met[min].minuto);
    printf("Temperatura: %.1f\n", met[min].tcelsius);
    printf("Pressão: %.1f\n", met[min].pammhg);
    printf("Local: %s\n", met[min].local);
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

    mostra_min(meteors, i);
    return 0;
}