/* int_overflow - tests what system does with integer overflow */
#include <stdio.h>
#include <locale.h>  /* needed for 1000s separator */

int main(void)
{
    setlocale(LC_NUMERIC, ""); /* needed for 1000s separator */

    int test_int;
    unsigned int test_unsigned_int;
    long int test_long;
    unsigned long int test_unsigned_long;
    long long int test_longlong;
    float test_float;
    double test_double;
    long double test_long_double;

    printf("\n\n"); // Add blank lines to make program output stand out

    test_int = 2147483647;
    printf ("Int . . .\n");   
    printf ("Int Max (dec) = %'d\n", test_int);
    printf ("Int Max (hex) = %#x (hex is unsigned)\n", test_int * 2 + 1);
    printf ("Int Max + 1 = %'d\n\n", test_int + 1);

    test_unsigned_int = 4294967295U;
    printf ("Unsigned Int . . .\n");
    printf ("Unsigned Int Max (dec) = %'u\n", test_unsigned_int);
    printf ("Unsigned Int Max (hex) = %#x\n", test_unsigned_int);
    printf ("Unsigned Int Max + 1 (dec) = %'u\n", test_unsigned_int + 1);
    printf ("Unsigned Int Max + 1 (hex) = %#x\n\n", test_unsigned_int + 1);

    test_long = 9223372036854775807L;
    printf ("Long Int . . .\n");
    printf ("Long Int Max (dec) = %'ld\n", test_long);
    printf ("Long Int Max (hex) = %#lx (hex is unsigned)\n", test_long * 2 + 1);
    printf ("Long Int Max + 1 (dec) = %'ld\n\n", test_long + 1);

    test_unsigned_long = 18446744073709551615UL;
    printf ("Unsigned Long Int . . .\n");
    printf ("Unsigned Long Int Max (dec) = %'lu\n", test_unsigned_long);
    printf ("Unsigned Long Int Max (hex) = %#lx\n", test_unsigned_long);
    printf ("Unsigned Long Int Max + 1 (dec) = %'lu\n\n", test_unsigned_long + 1);

    test_longlong =  9223372036854775807LL;
    printf ("Long Long Int . . .\n");
    printf ("Long Long Int Max (dec) = %'lld\n", test_longlong);
    printf ("Long Long Int Max (hex) = %#llx (hex is unsigned)\n", test_longlong * 2 + 1);
    printf ("Long Long Int Max + 1 (dec) = %'lld\n\n", test_longlong + 1);

    test_float = 3.40282346638528859812e+38F; 
    printf ("Float . . .\n");
    printf ("Float Max (dec) = %.20e\n", test_float);
    printf ("Float Max (dec) * 2 = %.20e\n", test_float * 2 );
    test_float = 1.17549435082228750797e-38F; 

    /* Min value #define as __FLT_DENORM_MIN__
    test_float = 1.40129846432481707092e-45F;
    
    /* Min float value # define as __FLT_MIN__ */
    printf ("Float Min (dec)       = %.20e\n", test_float);

    /* I don't know why this doesn't work per C Primer Plus pg 83 . . . */
    printf ("Float Min (dec) / 10 = %.20e\n", test_float / 10 );
    /*  . . . it returns all 0's vs eating into the mantissa  ? ? */



    test_double = 1.79769313486231570815e+308L;


    test_double = 2.22507385850720138309e-308L;



    test_long_double = 1.18973149535723176502e+4932L; 


    test_long_double = 3.36210314311209350626e-4932L;


    return 0;

}
 
