#include <fstream>
#include <string>
#include <math.h>
#include "prototypes.h"


int
main ()
{
  // file name
  const char FileName[100]="Data";

  // total number of columns to load
  const int NColumns = 2;

  // target columns
  const int TargetColumns[NColumns] = { 0, 1};

  //array to store data
  double *Data = NULL;

  // load data into the column-major order
  const bool RowMajor_No  = false;       

  // allocate memory for Merger_Prof1/2
  const bool AllocMem_Yes = true;        

  int RowIdx;

  RowIdx = Aux_LoadTable ( Data, FileName, NColumns, TargetColumns, RowMajor_No, AllocMem_Yes );

  double *DataX, *DataF;

  DataX = Data + 0*RowIdx;
  DataF = Data + 1*RowIdx;

  const int NumCells = 100000;
  const double Range[2] = { 0.0, M_PI };
  double Sum;

  Sum = Integration( RowIdx, DataX, DataF, Range, NumCells );

  printf("Sum=%20.16e\n", Sum);

  return 0;
}
