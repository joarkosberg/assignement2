#include "wordSorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **array, char *temp, int i);

void sortWords (char **files, int filesSize, int fileNameSize){
	int done;
	char *temp = malloc(fileNameSize*sizeof(char)); 
	do{
		done = 1;
		for(int i = 0; i < filesSize - 1; i++){
			if(strcmp(files[i], files[i+1]) > 0){
				swap(files, temp, i);
				done = 0;
			}
		}
	} while (!done);
	free(temp);
}

void swap(char **array, char *temp, int i){
	strcpy(temp, array[i + 1]);
	strcpy(array[i + 1], array[i]);
	strcpy(array[i], temp);
}