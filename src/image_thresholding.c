/*
 ============================================================================
 Name        : image_thresholding.c
 Author      : Nikhil Kumar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"threashold.h"
int main(void) {

	threashold("/home/pi/nikhil/input/lena.bmp","/home/pi/nikhil/output/lena_threshold.bmp");
	threashold("/home/pi/nikhil/input/lena_color.bmp","/home/pi/nikhil/output/lena_color_threshold.bmp");
	threashold_neon("/home/pi/nikhil/input/lena.bmp", "/home/pi/nikhil/output/lena_threshold_neon.bmp");
	threashold_neon("/home/pi/nikhil/input/lena_color.bmp", "/home/pi/nikhil/output/lena_color_threshold_neon.bmp");
	printf("done");
	return 0;
}
