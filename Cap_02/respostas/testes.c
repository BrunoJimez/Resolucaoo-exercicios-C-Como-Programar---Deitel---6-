#include <stdio.h>

int main ( void ) {
int num1 , num2 ;
printf (" Digite dois inteiros :");
scanf ("%d%d", &num1 , & num2 );

if ( num1 > num2 ) {
        printf ("%d e maior \n", num1 );
 }
if ( num2 > num1 ) {
    printf ("%d e maior \n", num2 );
}
if ( num1 == num2 ) {
        printf (" Esses  numeros sao  iguais \n");
}

return 0;
}
