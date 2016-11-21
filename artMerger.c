#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(){

	//Take input (folder with files)
	printf("Welcome to art merger.\n");
	printf("Please provide a folder:\n");

	char *folderName = malloc(30*sizeof(char));
	scanf("%s", folderName);

	printf("Folder to merge: %s\n\n", folderName);

	//Find files
	char **files;
	int filesSize = 0;
	int filesCapacity = 20;
	files = malloc(filesCapacity*sizeof(char*));
	for (int i = 0; i < filesCapacity; i++)
	    files[i] = malloc(30*sizeof(char));

	DIR *d;
	struct dirent *dir;
  	d = opendir(folderName);
  	printf("Files:\n");
  	if (d){
    	while ((dir = readdir(d)) != NULL){
    		char *dot = strrchr(dir->d_name, '.');
			if (dot && !strcmp(dot, ".txt")){
				printf("%s\n", dir->d_name);
				files[filesSize++] = dir->d_name;
			}
    	}
    	closedir(d);
    }
    printf("Number of files in folder: %d\n", filesSize);

	//Determine Height and Width (Sort files.)
	int width = 0;
	int height = 0;

	char ***filesSorted;    




	//Read file after file into new file. 





	//


	return 0;
}