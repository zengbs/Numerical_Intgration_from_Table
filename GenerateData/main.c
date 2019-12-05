#include <stdio.h>
#include <math.h>


int main()
{
int NumCells = 100000;
double LeftLimit, RightLimit;

LeftLimit  = 0.0;
RightLimit = M_PI*1.1;

int i;
double x;

for ( i =0;i<NumCells;i++ )
{
  x=LeftLimit + ( (double)i / (double)NumCells ) * ( RightLimit - LeftLimit );
  printf("%20.16e     %20.16e\n", x, sin(x));
}


return 0;
}
