#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE * makeFile(const char *FILE_NAME){

  FILE * pfile;

  pfile = fopen(FILE_NAME,"w");

  return pfile;

  //NOTE I would like to include the check of the last two char to include ps extension if not already there
}

void makeHeader(FILE * pFile, double x0, double y0){
  fprintf(pFile, "%%!\n2.835 dup dup scale \n1 exch div setlinewidth \nnewpath \n182 98 moveto \n");
}

void strokeStep(FILE * pFile, double x, double y){

	fprintf(pFile, "%f %f lineto\n", x, y);
}

void finishFile(FILE * pFile){
	fprintf(pFile, "gsave \n0.5 1 0 0 setrgbcolor \nstroke \nshowpage");
	fclose(pFile);
}

/*int main()

{

  const char * FILE_PATH;
  FILE * pFile;

  FILE_PATH = "filename.ps";
  pFile = makeFile(FILE_PATH);
  makeHeader(pFile);
  strokeStep(pFile, 2, 2);

  finishFile(pFile);

  }*/


