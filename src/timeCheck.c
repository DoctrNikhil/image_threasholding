/*
 * timeCheck.c
 *
 *  Created on: 17-Jun-2022
 *      Author: DSI-LPT-053
 */

#include"timeCheck.h"

double time_spent(void (f)(char *old_image, char *new_image),char *old_image, char *new_image)
{
	clock_t begin = clock();
	f(old_image, new_image);
	clock_t end = clock();

	return (double)(end-begin)/CLOCKS_PER_SEC;
}

