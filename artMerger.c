#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordSorter.h"
#include "fileFinder.h"
#include "fileMerger.h"

int main(){
	int fileNameSize = 30;

	//Take input (folder with files)
	printf("Welcome to art merger!.\n");
	printf("Please provide a folder:\n");

	char *folderName = malloc(fileNameSize*sizeof(char));
	scanf("%s", folderName);
	printf("\nFolder to merge: %s\n", folderName);

	//Find files
	char **files;
	int filesCapacity = 30; //Increase if more files needs to be merged
	files = malloc(filesCapacity*sizeof(char*));
	for (int i = 0; i < filesCapacity; i++)
	    files[i] = malloc(fileNameSize*sizeof(char));

	int filesSize = findTxtFiles(files, folderName);
    printf("Number of files in folder: %d\n", filesSize);

	//Sort words
	//To make sure files are read in correct order
	sortWords(files, filesSize, fileNameSize); 
	printf("Files to merge:\n");
	for(int k = 0; k < filesSize; k++){
		printf("%s\n", files[k]);
	}
	printf("\n");

	//Merge files
	mergeFiles(filesSize, fileNameSize, folderName, files);

	//Free memory
	free(folderName);
  	for(int i = 0; i < filesCapacity; i++)
    	free(files[i]);
  	free(files);

	return 0;
}