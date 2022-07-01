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
#include"timeCheck.h"
int main(void) {

//	threashold("/home/pi/nikhil/input/lena.bmp","/home/pi/nikhil/output/lena_threshold.bmp");
	double threashold_time = time_spent(threashold,"/home/pi/nikhil/input/lena.bmp","/home/pi/nikhil/output/lena_threshold.bmp");
	printf("\nTime spent threashold\t%0.10lf",threashold_time);
//	threashold("/home/pi/nikhil/input/lena_color.bmp","/home/pi/nikhil/output/lena_color_threshold.bmp");
	threashold_time = time_spent(threashold,"/home/pi/nikhil/input/lena_color.bmp","/home/pi/nikhil/output/lena_color_threshold.bmp");
	printf("\nTime spent threashold color\t%0.10lf",threashold_time);
//	threashold_neon("/home/pi/nikhil/input/lena.bmp", "/home/pi/nikhil/output/lena_threshold_neon.bmp");
	threashold_time = time_spent(threashold_neon,"/home/pi/nikhil/input/lena.bmp", "/home/pi/nikhil/output/lena_threshold_neon.bmp");
	printf("\nTime spent threashold neon\t%0.10lf",threashold_time);
//	threashold_neon("/home/pi/nikhil/input/lena_color.bmp", "/home/pi/nikhil/output/lena_color_threshold_neon.bmp");
	threashold_time = time_spent(threashold_neon,"/home/pi/nikhil/input/lena_color.bmp", "/home/pi/nikhil/output/lena_color_threshold_neon.bmp");
	printf("\nTime spent threashold color neon\t%0.10lf",threashold_time);
	printf("\ndone");
	return 0;
}
