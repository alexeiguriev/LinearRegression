// main.c

#include <stdio.h>
#include <stdlib.h>
#include "linear_regression.h"

int main(int argc, char *argv[])
{
    if (argc < 6)
    {
        printf("Wrong parameters: %s\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (((n % 2) != 0) || n <= 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    if (argc < (2 + (n * 2)))
    {
        printf("Wrong parameters: %s\n", argv[0]);
        return 1;
    }

    double *dataX = malloc(n * sizeof(double));
    double *dataY = malloc(n * sizeof(double));

    if (dataX == NULL || dataY == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        dataX[i] = atof(argv[i * 2 + 2]);
        dataY[i] = atof(argv[i * 2 + 3]);
    }

    printf("DataX = ");
    for (int index = 0; index < n; index++)
    {
        printf("%.2f ", dataX[index]);
    }
    
    printf("\nDataY = ");
    for (int index = 0; index < n; index++)
    {
        printf("%.2f ", dataY[index]);
    }

    LinearRegressionResult* result = LinearRegression(dataX, dataY, n);

    if (result != NULL)
    {
        printf("\nLinear Regression:\n");
        printf("Slope: %.2f\n", result->slope);
        printf("Intercept: %.2f\n", result->intercept);
        free(result);
    }

    free(dataX);
    free(dataY);

    return 0;
}
