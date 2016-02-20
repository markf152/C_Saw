#include <stdio.h>
#include <inttypes.h>
#include <float.h>

int main (int argc, const char * argv[]) {

    float myFloat;
    double myDouble;
    long double	myLongDouble;
	
    myFloat =      12345.67890123456789F;
    myDouble =     12345.67890123456789;
    myLongDouble = 12345.67890123456789L;

    printf("\n\n");  /* Blank lines for readability */     
	
    printf( "sizeof( long double ) = %d\n", (int)sizeof( long double ) );
    printf( "sizeof( double ) = %d\n", (int)sizeof( double ) );
    printf( "sizeof( float ) = %d\n", (int)sizeof( float ) );
    printf( "sizeof( unsigned long long int) = %d\n", (int)sizeof( unsigned long long int) );
    printf( "sizeof( long long int) = %d\n", (int)sizeof( long long int) );
    printf( "sizeof( unsigned long ) = %d\n", (int)sizeof( unsigned long ) );
    printf( "sizeof( long ) = %d\n", (int)sizeof( long ) );
    printf( "sizeof( unsigned int ) = %d\n", (int)sizeof( unsigned int ) );
    printf( "sizeof( int ) = %d\n\n", (int)sizeof( int ) );
    printf( "sizeof( short ) = %d\n", (int)sizeof( short ) );
    printf( "sizeof( char ) = %d\n", (int)sizeof( char ) );
    printf( "sizeof( size_t ) = %d\n\n", (int)sizeof( size_t ) );
    printf( "sizeof( int32_t ) = %d\n", (int)sizeof( int32_t ) );
    printf( "sizeof( int64_t ) = %d\n\n", (int)sizeof( int64_t ) );
	
    printf( "myFloat =      %f\n", myFloat );
    printf( "myDouble =     %f\n", myDouble );
    printf( "myLongDouble = %Lf\n\n", myLongDouble );
	
    printf( "myFloat =      %25.16f\n", myFloat );
    printf( "myDouble =     %25.16f\n", myDouble );
    printf( "myLongDouble = %25.16Lf\n\n", myLongDouble );
	
    printf( "myFloat = %10.1f\n", myFloat );
    printf( "myFloat = %.2f\n", myFloat );
    printf( "myFloat = %.12f\n", myFloat );
    printf( "myFloat = %.9f\n\n", myFloat );
	
    printf( "myFloat = %e\n\n", myFloat );
	
    myFloat = 100000;
    printf( "myFloat = %g\n", myFloat );
	
    myFloat = 1000000;
    printf( "myFloat = %g\n", myFloat );	
    
    printf("\n\n");  /* Blank lines for readability */    
 
    return 0;
}
