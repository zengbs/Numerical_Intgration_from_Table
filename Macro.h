#define COMMENT_SYM     '#'      // comment symbol
#define DELIMITER       " \t"    // delimiter characters used by strtok()
#define MAX_STRING 100

#define FLOAT8

#ifdef FLOAT8
#define NULL_REAL        __DBL_MAX__ 
#else
#define NULL_REAL        __FLT_MAX__
#endif
