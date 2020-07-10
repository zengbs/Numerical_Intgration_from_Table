#define COMMENT_SYM     '#'      // comment symbol
#define DELIMITER       " \t"    // delimiter characters used by strtok()
#define MAX_STRING 100
#define FLOAT8

#ifdef FLOAT8
#define NULL_REAL        __DBL_MAX__ 
#else
#define NULL_REAL        __FLT_MAX__
#endif


#define SQR( x ) ( ( x ) * ( x ) )
#define CONST_KPC  3.08567758149e21
#define MASS_SOLAR 1.9891e33
