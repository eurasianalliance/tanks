/*
 * draw_bomb.c
 *
 *  Created on: 2014-01-30
 *      Author: Kris_Mazurek
 */
#include "tanks.h"

int draw_bombs(alt_up_pixel_buffer_dma_dev* pixbuf)
{
	alt_up_pixel_buffer_dma_dev* pixel_buffer = pixbuf;

	//int i = 1;
	int j = 1;

//	if(i>=60){
//	  i=1;
//	}
//
//	i=i+1;
//
//	if(j>=120){
//	  j=1;
//	}
//
//	j=j+1;

	for(j=1;j<120;j++){
	//alt_up_char_buffer_clear(char_buffer);
	//alt_up_char_buffer_string(char_buffer, "IT'S A BOOOOOOOOOAAAAMMMBBB!!!", 40, i);

	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 29, j*2, 29, j*2+5, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 29, j*2+12, 29, j*2+18, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 30, j*2+1, 30, j*2+7, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 30, j*2+11, 30, j*2+19, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 31, j*2+2, 31, j*2+7, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 31, j*2+9, 31, j*2+19, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 32, j*2+1, 32, j*2+20, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 33, j*2+1, 33, j*2+20, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 34, j*2+2, 34, j*2+7, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 34, j*2+9, 34, j*2+19, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 35, j*2+1, 35, j*2+7, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 35, j*2+11, 35, j*2+19, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 36, j*2, 36, j*2+5, 0xFF00, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 36, j*2+12, 36, j*2+18, 0xFF00, 1);

	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 129, j, 129, j+5, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 129, j+12, 129, j+18, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 130, j+1, 130, j+7, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 130, j+11, 130, j+19, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 131, j+2, 131, j+7, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 131, j+9, 131, j+19, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 132, j+1, 132, j+20, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 133, j+1, 133, j+20, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 134, j+2, 134, j+7, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 134, j+9, 134, j+19, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 135, j+1, 135, j+7, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 135, j+11, 135, j+19, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 136, j, 136, j+5, 0xFF00, 1);
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 136, j+12, 136, j+18, 0xFF00, 1);
	//Swap buffers and clear
	      alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	      while(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));
	}
	return 0;
}
