#include "fileFinder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeFiles (int filesSize, int fileNameSize, char *folderName, char **files){

  //Determine width and height of image
  int width = 0;
  int height = 0;
  sscanf (files[filesSize - 1], "part_%d_%d_", &width, &height);
  width++;
  height++;

  printf("Image Height: %d\n", height);
  printf("Image Width: %d\n", width);

	//Open files
  char *outputFileName = malloc(fileNameSize*sizeof(char));
  strcpy(outputFileName, folderName);
  strcat(outputFileName, ".txt"); 

  FILE *outputFile = fopen(outputFileName, "w");
  FILE **inputFiles = malloc(filesSize*sizeof(FILE*));

  char *theFile = malloc(fileNameSize*sizeof(char));
  for (int i = 0; i < filesSize; i++){
    sprintf(theFile, "%s%c%s", folderName, '/', files[i]);
    inputFiles[i] = fopen(theFile, "r");
  }
  free(theFile);

  //Read and merge files
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
  printf("Output sent to: %s\n", outputFileName);

  //Free memory
  free(line);
  free(outputFileName);
  for(int i = 0; i < filesSize; i++)
      fclose(inputFiles[i]);
  free(inputFiles);
  fclose(outputFile);
}