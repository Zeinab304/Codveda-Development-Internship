#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    float num1, num2;
    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &op);
    printf("Enter two operands:\n >> ");
    scanf("%f %f", &num1, &num2);
    switch(op)
    {
    case '+':
        printf ( "%g  + %g  = %g ",num1, num2, num1 + num2);
        break;
    case '-':
        printf ( "%g  - %g  = %g ",num1, num2, num1 - num2);
        break;
    case '*':
        printf ( "%g  * %g  = %g ",num1, num2, num1 * num2);
        break;
    case '/':
        if(num2==0)
        {
            printf ( "Error! Division by zero.");
            break;
        }
        printf ( "%g / %g  = %g ",num1, num2, num1 / num2);
        break;
    default:
        printf ( "Error! operator is not correct");
        break;
    }
    return 0;
}
