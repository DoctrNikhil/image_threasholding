/*
 * timeCheck.h
 *
 *  Created on: 17-Jun-2022
 *      Author: DSI-LPT-053
 */

#ifndef TIMECHECK_H_
#define TIMECHECK_H_

#include<time.h>

// this function return execution time of loops in seconds
double time_spent(void (f)(char *old_image, char *new_image),char *old_image, char *new_image);

#endif /* TIMECHECK_H_ */
