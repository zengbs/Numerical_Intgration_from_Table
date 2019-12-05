template <typename T>
int Aux_LoadTable( T *&Data, const char *FileName, const int NCol_Target, const int TCol[], 
				   const bool RowMajor, const bool AllocMem );

template <typename T>
T Mis_InterpolateFromTable( const int N, const T Table_x[], const T Table_y[], const T x );

template <typename T>
int Mis_BinarySearch_Real( const T Array[], int Min, int Max, const T Key );



double Integration( const int N, const double *DataX, const double *DataF, const double *Range,
			     const int NumCells );
