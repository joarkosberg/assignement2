#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "wordSorter.h"

int main(){

	//Take input (folder with files)
	printf("Welcome to art merger.\n");
	printf("Please provide a folder:\n");

	char *folderName = malloc(30*sizeof(char));
	char *folderTxt = malloc(30*sizeof(char));

	scanf("%s", folderName);
	strcpy(folderTxt, folderName);
	strcat(folderTxt, ".txt"); 

	printf("\nFolder to merge: %s\n", folderName);

	//Find files
	char **files;
	int filesSize = 0;
	int filesCapacity = 30;
	int fileNameSize = 30;
	files = malloc(filesCapacity*sizeof(char*));
	for (int i = 0; i < filesCapacity; i++)
	    files[i] = malloc(fileNameSize*sizeof(char));

	DIR *d;
	struct dirent *dir;
  	d = opendir(folderName);
  	if (d){
    	while ((dir = readdir(d)) != NULL){
    		char *dot = strrchr(dir->d_name, '.');
			if (dot && !strcmp(dot, ".txt")){
				strcpy(files[filesSize], dir->d_name);
				filesSize++;
			}
    	}
    	closedir(d);
    }
    if(filesSize == 0){
    	printf("Invalid folder!\n");
		exit(EXIT_FAILURE);
    }
    printf("Number of files in folder: %d\n", filesSize);

	//Sort words
	sortWords(files, filesSize, fileNameSize); 
	printf("Files to merge:\n");
	for(int k = 0; k < filesSize; k++){
		printf("%s\n", files[k]);
	}
	printf("\n");

	//Determine width and height
	int width = 0;
	int height = 0;
	sscanf (files[filesSize - 1], "part_%d_%d_", &width, &height);
	width++;
	height++;

	printf("Image Height: %d\n", height);
	printf("Image Width: %d\n", width);

	//Open files
	FILE *outputFile = fopen(folderTxt, "w");
	FILE **inputFiles = malloc(filesSize*sizeof(FILE*));

	char *theFile = malloc(fileNameSize*sizeof(char));
	for (int i = 0; i < filesSize; i++){
   		sprintf(theFile, "%s%c%s", folderName, '/', files[i]);
   		inputFiles[i] = fopen(theFile, "r");
   	}
   	free(theFile);
   	for(int i = 0; i < filesCapacity; i++)
		free(files[i]);
   	free(files);

   	//Read art files
	char *line = malloc(31*sizeof(char));
	for(int i = 0; i < height; i++){ //Total height
		for(int j = 0; j < 30; j++){ //Line height
			for(int k = 0; k < width; k++){ //Total Width
				fgets(line, 31*sizeof(char), inputFiles[i + (k*height)]);
				line[30] = 0; //Remove new line at ending
				fprintf(outputFile, "%s", line);
			}
			fprintf(outputFile, "\n");
		}
	}
	free(line);
	printf("Output sent to: %s\n", folderTxt);

	free(folderName);
	free(folderTxt);
	free(inputFiles);
	fclose(outputFile);
	return 0;
}