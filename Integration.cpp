#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

double Integration( const int N, const double *DataX, const double *DataF, const double *Range,
			     const int NumCells )
{
// find maximum and minimum value if DataX
// --> assuming DataX have been sorted
  double DataMax, DataMin;

  double DataLeft  = *(DataX + 0 );
  double DataRight = *(DataX + N - 1 );

  if ( DataLeft > DataRight )
  {
    DataMax = DataLeft;
    DataMin = DataRight;	
  }
  else
  {
    DataMax = DataRight;
    DataMin = DataLeft;	
  }

  const double LeftLimit  = Range[0];
  const double RightLimit = Range[1];

// check 
  if ( LeftLimit >= RightLimit )
  {
    printf("'LeftLimit' should be smaller than 'RightLimit'\n");
    exit(1);
  }


// check 
  if ( LeftLimit < DataMin || RightLimit > DataMax )
  {
    printf("integration range is not inside DataX !!\n");
	printf("LeftLimit=%20.16e, DataMin=%20.16e, RightLimit=%20.16e, DataMax=%20.16e\n",LeftLimit, DataMin, RightLimit, DataMax );
	exit(1);
  }

//

// cell size
  double CellSize = ( RightLimit - LeftLimit ) / (double) NumCells;
  double Xi, Fi;
  double Sum = 0.0;

// trapezoidal rule is emplyed to approximate definite integral
// Ref: https://en.wikipedia.org/wiki/Trapezoidal_rule#Uniform_grid
// To reduce rounding error, we can split integral range ?
  int i;

  for ( i = 1; i < NumCells; i++ )
  {
    Xi = LeftLimit + ( (double)i / (double) NumCells ) * ( RightLimit - LeftLimit );

    Fi = Mis_InterpolateFromTable( N, DataX, DataF, Xi );

    Sum += Fi;
  }

  Sum += 0.5 * Mis_InterpolateFromTable( N, DataX, DataF, RightLimit );
  Sum += 0.5 * Mis_InterpolateFromTable( N, DataX, DataF, LeftLimit  );

  Sum *= CellSize;

  return Sum;
}
