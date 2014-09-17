#include <stdio.h>


void makeFile(const char *FILE_NAME){

  FILE * pfile;

  pfile = fopen(FILE_NAME,"w");

  //NOTE I would like to include the check of the last two char to include ps extension if not already there
}

void makeHeader(){


}
int main()

{

  const char * FILE_PATH;

  FILE_PATH = "filename";

  makeFile(FILE_PATH);


}


