/*
 * threashold.h
 *
 *  Created on: 24-Jun-2022
 *      Author: DSI-LPT-053
 */

#ifndef THREASHOLD_H_
#define THREASHOLD_H_

#include<arm_neon.h>
#include<stdio.h>

void threashold(char *old_image, char *new_image);
void threashold_neon(char *old_image, char *new_image);
#endif /* THREASHOLD_H_ */
