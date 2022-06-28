/*
 * threashold.c
 *
 *  Created on: 24-Jun-2022
 *      Author: DSI-LPT-053
 */

#include"threashold.h"

uint32_t headerCopy(FILE *fold,FILE *fnew)
{
	uint32_t headerSize;

	// In BYTE number 10 of bmp image
	// it consist of headerSize of image
	// which is of type unsigned long
	// Set file pointer to byte number 10
	fseek(fold,10,SEEK_SET);
	// read headerSize
	fread(&headerSize,sizeof(headerSize),1,fold);

	// This array will store all header data of old image
	uint8_t header[headerSize];
	rewind(fold);
	// read all header data
	fread(header,sizeof(header),1,fold);

	// Writing all header to new file
	rewind(fnew);
	fwrite(header,sizeof(header),1,fnew);


	return headerSize;
}

void get_Height_Width(FILE *fold, int32_t *Height, int32_t *Width)
{

	// height of a bmp image is store in byte number 18
	// type is long
	// width of image is stored in byte number 22
	// type is long
	// set file pointer to read height and width
	fseek(fold,18,SEEK_SET);
	fread(Height,4,1,fold);
	fread(Width,4,1,fold);

}

void threashold(char *old_image, char *new_image)
{
	FILE *fold = fopen(old_image,"rb");
	FILE *fnew = fopen(new_image,"wb");

	uint32_t headerSize = headerCopy(fold,fnew);

	int32_t Height,Width;
	get_Height_Width(fold,&Height,&Width);

	uint16_t bytesPerPixel;
	fseek(fold,28,SEEK_SET);
	fread(&bytesPerPixel,sizeof(bytesPerPixel),1,fold);
	bytesPerPixel /= 8;

	uint8_t old_pixal_data[Height][Width][bytesPerPixel];
	uint8_t new_pixal_data[Height][Width][bytesPerPixel];

	fseek(fold,headerSize,SEEK_SET);



	fread(&old_pixal_data[0][0][0], Height * Width * bytesPerPixel ,1,fold);


	const uint8_t Threashold = 149;

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if(bytesPerPixel == 1)
			{
				new_pixal_data[i][j][0] = (old_pixal_data[i][j][0] > Threashold)?255:0;
//				printf("\nold_pixal_data[%d][%d] %d",i,j,old_pixal_data[i][j][0]);
//				printf("\nnew_pixal_data[%d][%d] %d",i,j,new_pixal_data[i][j][0]);
			}
			else if(bytesPerPixel == 3)
			{
				new_pixal_data[i][j][0] = (old_pixal_data[i][j][0] > Threashold)?255:0;
				new_pixal_data[i][j][1] = (old_pixal_data[i][j][1] > Threashold)?255:0;
				new_pixal_data[i][j][2] = (old_pixal_data[i][j][2] > Threashold)?255:0;
			}
		}
	}

	fseek(fnew, headerSize, SEEK_SET);
	fwrite(&new_pixal_data[0][0][0], sizeof(new_pixal_data), 1, fnew);

	fclose(fold);
	fclose(fnew);

}

void threashold_neon(char *old_image, char *new_image)
{
	FILE *fold = fopen(old_image,"rb");
	FILE *fnew = fopen(new_image,"wb");

	uint32_t headerSize = headerCopy(fold,fnew);

	int32_t Height,Width;
	get_Height_Width(fold,&Height,&Width);

	uint16_t bytesPerPixel;
	fseek(fold,28,SEEK_SET);
	fread(&bytesPerPixel,sizeof(bytesPerPixel),1,fold);
	bytesPerPixel /= 8;

	uint8_t old_pixal_data[Height][Width][bytesPerPixel];
	uint8_t new_pixal_data[Height][Width][bytesPerPixel];

	fseek(fold,headerSize,SEEK_SET);



	fread(&old_pixal_data[0][0][0], Height * Width * bytesPerPixel ,1,fold);


	const uint8_t Threashold = 150;


	if(Width < 16)
	{
		/* Image is too thin to fit width in neon register */
		fclose(fold);
		fclose(fnew);
		threashold(old_image,new_image);
		return;
	}


	for (int i = 0; i < Height; i++)
	{

			int j;
			for (j = 0; j < (Width&(~15)); j+=16)
			{
				if(bytesPerPixel == 1)
				{
					uint8x16_t pixal = vld1q_u8(&old_pixal_data[i][j][0]);
					uint8x16_t threashold = vld1q_dup_u8(&Threashold);
					uint8x16_t out_pixal = vcgtq_u8(pixal,threashold);
					vst1q_u8(&new_pixal_data[i][j][0],out_pixal);
				}
				else if(bytesPerPixel == 3)
				{
					uint8x16x3_t pixal = vld3q_u8(&old_pixal_data[i][j][0]);
					uint8x16_t threashold = vld1q_dup_u8(&Threashold);
					uint8x16x3_t out_pixal;
					out_pixal.val[0] = vcgtq_u8(pixal.val[0],threashold);
					out_pixal.val[1] = vcgtq_u8(pixal.val[1],threashold);
					out_pixal.val[2] = vcgtq_u8(pixal.val[2],threashold);
					vst3q_u8(&new_pixal_data[i][j][0],out_pixal);
				}
			}
			j = Width - 16;
			if(bytesPerPixel == 1)
			{
				uint8x16_t pixal = vld1q_u8(&old_pixal_data[i][j][0]);
				uint8x16_t threashold = vld1q_dup_u8(&Threashold);
				uint8x16_t out_pixal = vcgtq_u8(pixal,threashold);
				vst1q_u8(&new_pixal_data[i][j][0],out_pixal);
			}
			else if(bytesPerPixel == 3)
			{
				uint8x16x3_t pixal = vld3q_u8(&old_pixal_data[i][j][0]);
				uint8x16_t threashold = vld1q_dup_u8(&Threashold);
				uint8x16x3_t out_pixal;
				out_pixal.val[0] = vcgtq_u8(pixal.val[0],threashold);
				out_pixal.val[1] = vcgtq_u8(pixal.val[1],threashold);
				out_pixal.val[2] = vcgtq_u8(pixal.val[2],threashold);
				vst3q_u8(&new_pixal_data[i][j][0],out_pixal);
			}

	}

	fseek(fnew, headerSize, SEEK_SET);
	fwrite(&new_pixal_data[0][0][0], sizeof(new_pixal_data), 1, fnew);

	fclose(fold);
	fclose(fnew);
}


