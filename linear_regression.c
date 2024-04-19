/*
 * linear_regression.c
 *
 *  Created on: Apr 20, 2024
 *      Author: alexei.guriev
 */


/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief LinearRegression calc
 *
 * @param[in] dataX X buffer data.
 * @param[in] dataY Y buffer data.
 * @param[in] n elements number
 *
 * @return Linear Regression result: NULL - wrong data; Not NULL - calc data
 */
LinearRegressionResult* LinearRegression(double *dataX, double *dataY, int n)
{
    if (dataX == NULL || dataY == NULL || n <= 0)
    {
        return NULL;
    }

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += dataX[i];
        sum_y += dataY[i];
        sum_xy += dataX[i] * dataY[i];
        sum_x_squared += dataX[i] * dataX[i];
    }

    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    double slope = (sum_xy - n * mean_x * mean_y) / (sum_x_squared - n * mean_x * mean_x);
    double intercept = mean_y - slope * mean_x;

    LinearRegressionResult* result = malloc(sizeof(LinearRegressionResult));
    if (result == NULL)
    {
        return NULL;
    }

    result->slope = slope;
    result->intercept = intercept;
    return result;
}



/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/