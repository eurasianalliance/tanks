/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
#include "tanks.h"

int main()
{
  printf("Before use, please consult the user manual, or untie your shoes.\n");
  printf("Also you should probably avoid this game if you have seizures.\n");

  //define pixel_buffer
  alt_up_pixel_buffer_dma_dev* pixel_buffer;


  // Use the name of your pixel buffer DMA core
  pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/pixel_buffer_dma");

  //Define buffer addresses
  unsigned int pixel_buffer_addr1 = PIXEL_BUFFER_BASE;
  unsigned int pixel_buffer_addr2 = PIXEL_BUFFER_BASE + (320 * 240 * 2);

  //Set the first buffer address
 alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer,pixel_buffer_addr1);

  // Swap background and foreground buffers
  alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
 // Wait for the swap to complete
  while(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));

  //Set the 2nd buffer address
 alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer,pixel_buffer_addr2);

// Clear the screen
  alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
  alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);

  alt_up_char_buffer_dev *char_buffer;
  char_buffer = alt_up_char_buffer_open_dev("/dev/char_drawer");
  alt_up_char_buffer_init(char_buffer);

  while(1){
      draw_bombs(pixel_buffer);
      alt_up_char_buffer_clear(char_buffer);
      alt_up_char_buffer_string(char_buffer, "IT'S A BOOOOOOOOOAAAAMMMBBB!!!", 40, 30);

  }

  return 0;
}
