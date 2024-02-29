#include <time.h>
#include <stdio.h>

void clearConsole()
{
    printf("\033[H\033[J");
}

int *getOddNumbersWithRealloc(int *numbers, int size, int *oddNumbersSize)
{
    int *oddNumbers = (int *)malloc(0 * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] % 2 != 0)
        {
            oddNumbers = (int *)realloc(oddNumbers, (*oddNumbersSize + 1) * sizeof(int));
            oddNumbers[*oddNumbersSize] = numbers[i];
            *oddNumbersSize += 1;
        }
    }

    return oddNumbers;
}

int *getOddNumbersWithMalloc(int *numbers, int size, int *oddNumbersSize)
{
    int *oddNumbers;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] % 2 != 0)
        {
            *oddNumbersSize += 1;
        }
    }

    oddNumbers = (int *)malloc(*oddNumbersSize * sizeof(int));

    if (oddNumbers == NULL)
    {
        perror("Erro ao alocar memória\n");
        exit(-1);
    }

    for (int i = 0, j = 0; i < size; i++)
    {
        if (numbers[i] % 2 != 0)
        {
            oddNumbers[j] = numbers[i];
            j++;
        }
    }

    return oddNumbers;
}

int main()
{
    int size = 100000000;

    int *numbers = (int *)malloc(size * sizeof(int));

    if (numbers == NULL)
    {
        perror("Erro ao alocar memória\n");
        exit(-1);
    }

    for (int i = 0; i < size; i++)
    {
        numbers[i] = i;
    }

    int runs = 100;
    double averageTime = 0;

    printf("Executando função com malloc %d vezes...\n", runs);

    for (int i = 0; i < runs; i++)
    {
        clock_t begin = clock();

        int oddNumbersSize = 0;
        int *oddNumbers = getOddNumbersWithMalloc(numbers, size, &oddNumbersSize);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        averageTime += time_spent;

        free(oddNumbers);
    }

    averageTime /= runs;

    printf("Tempo médio de execução: %f segundos\n\n", averageTime);

    averageTime = 0;

    printf("Executando função com realloc %d vezes...\n", runs);

    for (int i = 0; i < runs; i++)
    {
        clock_t begin = clock();

        int oddNumbersSize = 0;
        int *oddNumbers = getOddNumbersWithRealloc(numbers, size, &oddNumbersSize);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        averageTime += time_spent;

        free(oddNumbers);
    }

    averageTime /= runs;

    printf("Tempo médio de execução: %f segundos\n\n", averageTime);


    free(numbers);

    return 0;
}