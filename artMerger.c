#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void swap(char **array, char *temp, int i);

int main(){

	//Take input (folder with files)
	printf("Welcome to art merger.\n");
	printf("Please provide a folder:\n");

	char *folderName = malloc(30*sizeof(char));
	char *folderPreFix = malloc(30*sizeof(char));
	char *folderTxt = malloc(30*sizeof(char));
	scanf("%s", folderName);
	strcpy(folderPreFix, folderName);
	folderPreFix[strlen(folderName)] = '/';
	strcpy(folderTxt, folderName);
	strcat(folderTxt, ".txt"); 

	printf("\nFolder to merge: %s\n", folderName);

	//Find files
	char **files;
	int filesSize = 0;
	int filesCapacity = 30;
	files = malloc(filesCapacity*sizeof(char*));
	for (int i = 0; i < filesCapacity; i++)
	    files[i] = malloc(30*sizeof(char));

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
    	printf("Empty folder!\n");
		exit(EXIT_FAILURE);
    }
    printf("Number of files in folder: %d\n", filesSize);

	//Sort words
	int done;
	char *temp = malloc(30*sizeof(char)); 
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

	printf("Files sorted:\n");
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

	printf("Height: %d\n", height);
	printf("Width: %d\n", width);

	//Open files
	FILE *outputFile = fopen(folderTxt, "w");
	FILE **inputFiles = malloc(filesSize * sizeof(FILE*));

	char *theFile = malloc(30*sizeof(char));
	for (int i = 0; i < filesSize; i++){
   		sprintf(theFile, "%s%s", folderPreFix, files[i]);
   		inputFiles[i] = fopen(theFile, "r");
   	}
   	free(theFile);
   	for(int i = 0; i < filesCapacity; i++)
		free(files[i]);
   	free(files);

   	//Read art files
	char *line = malloc(35*sizeof(char));
	for(int i = 0; i < height; i++){ //Total height
		for(int j = 0; j < 30; j++){ //Line height
			for(int k = 0; k < width; k++){ //Total Width
				fgets(line, 31*sizeof(char), inputFiles[i + (k*height)]);
				line[strlen(line)-1] = 0; //Remove new line at ending
				fprintf(outputFile, "%s", line);
				printf("%s", line);
			}
			fprintf(outputFile, "\n");
			printf("\n");
		}
	}
	free(line);


	free(folderName);
	free(folderPreFix);
	free(folderTxt);


	free(inputFiles);
	fclose(outputFile);
	return 0;
}

void swap(char **array, char *temp, int i){
	strcpy(temp, array[i + 1]);
	strcpy(array[i + 1], array[i]);
	strcpy(array[i], temp);
}