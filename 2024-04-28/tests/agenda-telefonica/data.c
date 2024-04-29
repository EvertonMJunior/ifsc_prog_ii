#include "data.h"
#include <stdlib.h>

Data *cria_data(int dia, int mes)
{
    Data *data = malloc(sizeof(Data));
    data->dia = dia;
    data->mes = mes;
    return data;
}