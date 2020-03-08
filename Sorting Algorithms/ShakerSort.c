/*
Author: Kürşat Ercan
Note: Activate the animation function to see the animation. 
Note2:Select small numbers to see the animation clearly!
*/
#include <stdio.h>
#include <time.h> 

int maxNum = 0;
void delay(int number_of_seconds) //from:https://www.geeksforgeeks.org/time-delay-c/
{
	int milli_seconds = 1000 * number_of_seconds; // Converting time into milli_seconds 
	clock_t start_time = clock();// Storing start time 
	while (clock() < start_time + milli_seconds);// looping till required time is not achieved 
}
void isMaxNum(int array[], int len_array) {
	maxNum = array[0];
	for (int i = 1; i < len_array; i++) {
		if (maxNum < array[i]) maxNum = array[i];
	}
}
void animation(int array[], int len_array) {
	int max = maxNum;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < len_array; j++) {
			if (i <= array[j]) printf("X ");
			else printf("  ");
		}
		printf("\n");
	}
	for (int i = 0; i < len_array; i++) printf("%d ", array[i]);
	printf("\n\n");
	delay(1);
}
void shakerSort(int array[],int len_array) {
	int temp = 0;
	int min = 0, max = len_array - 1;
	for (int i = max; i >= 0; i--) {
		if (array[i] < array[i - 1]) {
			temp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = temp;
			//animation(array, len_array);
			continue;
		}
		else if (i == min) {
			min += 1;
			for (i = min; i < max; i++) {
				if (array[i] > array[i + 1]) {
					temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
					//animation(array, len_array);
					continue;
				}
				else if (i == max) {
					max--;
					break;
				}
			}
		}
	}
}
void main() {
	int array[] = { 5,7,2,1,7,9,3,5,10 };
	int len_array = (sizeof(array) / sizeof(array[0]));
	isMaxNum(array,len_array);
	//int start_time = clock();
	shakerSort(array, len_array);
	//int finish_time = clock();
	for (int i = 0; i < len_array; i++) printf("%d ", array[i]);
	printf("\n");
	//printf("start: %d\nfinish: %d\ntime: %d", start_time, finish_time, finish_time - start_time);
	//printf("\n");
}
	
