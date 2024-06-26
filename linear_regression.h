/*
 * linear_regression.h
 *
 *  Created on: Apr 20, 2024
 *      Author: alexei.guriev
 */

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*
 *
 * LinearRegressionResult
 *
 */
typedef struct
{
    double slope;
    double intercept;
} LinearRegressionResult;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
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
LinearRegressionResult* LinearRegression(double *dataX, double *dataY, int n);


#endif /* LINEAR_REGRESSION_H */