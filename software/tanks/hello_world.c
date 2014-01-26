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

#include <stdio.h>
#include <altera_up_sd_card_avalon_interface.h>
#include "sys/alt_timestamp.h"
#include "sys/alt_alarm.h"

void timer_test(void);
void sd_card (void);


int main(void) {
	timer_test();
	sd_card();
	return 0;
}

//from exercise 1.2 creates two 100 by 100 array and multiply them and time it
void timer_test(void) {
	int a[100][100];
	int b[100][100];
	int c[100][100];
	int i,k,j;
	int sum;
	unsigned int start_time;
	unsigned int end_time;

	start_time=(unsigned int)alt_timestamp_start();
	for(i=0;i<100;i++)
	{
		for(j=0; j<100;j++)
		{
			a[i][j]=i;
			b[i][j]=j;
		}
	}


	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			sum=0;
			for(k=0;k<100;k++){
				sum=sum + a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
	end_time=(unsigned int)alt_timestamp();
	printf("start time: %u clock ticks\n",start_time);
	printf("end time: %u clock ticks\n",end_time);
	printf("time taken: %u clock ticks\n",end_time-start_time);
	printf (" %f seconds\n",(float)(end_time-start_time)/(float)alt_timestamp_freq());
}

//exercise 3 reads sd_card and list its file
void sd_card(void){
	char file_name[10];
		alt_up_sd_card_dev *device_reference = NULL;
		int connected = 0;

		device_reference = alt_up_sd_card_open_dev(ALTERA_UP_SD_CARD_AVALON_INTERFACE_0_NAME);
		if (device_reference != NULL) {
			while(1) {
				if ((connected == 0) && (alt_up_sd_card_is_Present())) {
					printf("Card connected.\n");
					if (alt_up_sd_card_is_FAT16()) {
						printf("FAT16 file system detected.\n");
						if(alt_up_sd_card_find_first(".", (char*) file_name)==0){
							//printf("%s\n",file_name);
							while(alt_up_sd_card_find_next((char*)file_name)==0)
							{
								printf("%s\n", file_name);
							}
						}
					} else {
						printf("Unknown file system.\n");
					}
					connected = 1;
				} else if ((connected == 1) && (alt_up_sd_card_is_Present() == false)) {
					printf("Card disconnected.\n");
					connected = 0;
				}
				break;
			}
		} else {
			printf("Card could not be opened\n");
		}
		printf("sd_card function finished");
}
