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

	threashold("C:\\Users\\DSI-LPT-053\\Documents\\Project\\input\\lena_gray.bmp","C:\\Users\\DSI-LPT-053\\Documents\\Project\\output\\lena_gray_threshold.bmp");
	threashold("C:\\Users\\DSI-LPT-053\\Documents\\Project\\input\\lena_color.bmp","C:\\Users\\DSI-LPT-053\\Documents\\Project\\output\\lena_color_threshold.bmp");
	threashold_neon("C:\\Users\\DSI-LPT-053\\Documents\\Project\\input\\lena_gray.bmp", "C:\\Users\\DSI-LPT-053\\Documents\\Project\\output\\lena_gray_threshold_neon.bmp");
	threashold_neon("C:\\Users\\DSI-LPT-053\\Documents\\Project\\input\\lena_color.bmp", "C:\\Users\\DSI-LPT-053\\Documents\\Project\\output\\lena_color_threshold_neon.bmp");
	printf("done");
	return 0;
}
