//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE * makeFile(const char *FILE_NAME){

  FILE * pfile;

  pfile = fopen(FILE_NAME,"w");

  return pfile;

  //NOTE I would like to include the check of the last two char to include ps extension if not already there
}

void makeHeader(FILE * pFile, double x, double y ){
	  fprintf(pFile, "%%!\n2.835 dup dup scale \n1 exch div setlinewidth \nnewpath \n%f %f moveto \n", x, y );
}

void strokeStep(FILE * pFile, double x, double y){
	fprintf(pFile, "%f %f lineto\n", x, y);
}

void finishFile(FILE * pFile){
	fprintf(pFile, "gsave \nstroke \nshowpage");
	fclose(pFile);
}

void strokeStepMulti(FILE * pFile, double x, double y, int count){

	int lengthCol = 30;
	int noCol = 3;
	int split = (lengthCol/noCol);    
	int colourVal = count % lengthCol;
	fprintf(pFile, "%f %f lineto\n", x, y);

	if (colourVal  < split )
			fprintf(pFile, "%f %f %f setrgbcolor\n", 1.0, 0.0, 0.0);
	if (colourVal  >= split && colourVal< (2 * split))
		   fprintf(pFile, "%f %f %f setrgbcolor\n", 1.0, 0.0, 1.0);
	if (colourVal  >= (2 * split) && colourVal< (3 * split) )
		   fprintf(pFile, "%f %f %f setrgbcolor\n", 0.0, 0.0, 1.0);

	fprintf(pFile, "stroke\n");
	fprintf(pFile, "newpath \n%f %f moveto \n", x, y);
}

void strokeStepGrad(FILE * pFile, double x, double y, int count, int total){

	double percent = (double)count/(double)total;
	fprintf(pFile, "%f %f lineto\n", x, y);
	fprintf(pFile, "%f %f %f setrgbcolor\n", 0.0, ( 1.0 * percent), 1.0);
	fprintf(pFile, "stroke\n");
	fprintf(pFile, "newpath \n%f %f moveto \n", x, y);
}
/*
int main()

{
  const char * FILE_PATH;
  FILE * pFile;
  int i = 0;

  FILE_PATH = "Test.ps";
  pFile = makeFile(FILE_PATH);
  makeHeader(pFile, 0, 0);

  for (i = 0; i < 200; i ++)
  {
	strokeStepMulti(pFile, i, i, i);
  }

  finishFile(pFile);

}

*/
