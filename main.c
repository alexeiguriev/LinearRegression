#include <stdio.h>
#include <stdlib.h>
#include "linear_regression.h"

int main(int argc, char *argv[])
{
    if (argc != 21)
    {
        printf("Usage: %s x1 y1 x2 y2 ... x10 y10\n", argv[0]);
        return 1;
    }

    double *dataX = malloc(10 * sizeof(double));
    double *dataY = malloc(10 * sizeof(double));

    if (dataX == NULL || dataY == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        dataX[i] = atof(argv[i * 2 + 1]);
        dataY[i] = atof(argv[i * 2 + 2]);
    }

    LinearRegressionResult* result = LinearRegression(dataX, dataY, 10);

    if (result != NULL) {
        printf("Linear Regression:\n");
        printf("Slope: %.2f\n", result->slope);
        printf("Intercept: %.2f\n", result->intercept);
        free(result);
    }

    free(dataX);
    free(dataY);

    return 0;
}

