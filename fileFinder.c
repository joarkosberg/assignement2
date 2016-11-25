#include "fileFinder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int findTxtFiles (char **files, char *folderName){
	DIR *d;
	struct dirent *dir;
  	d = opendir(folderName);
  	int filesSize = 0;

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
    } else {
    	return filesSize;
    }
}