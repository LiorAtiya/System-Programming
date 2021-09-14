#include "myMath.h"
#include <stdio.h>

int main(){
    double x;
    printf("Please inset a real number: ");
    scanf("%lf", &x);

    //f(x) = e^x + x^3 − 2
    double y = sub(add(Exponent(x), Power(x,3)),2);
    printf("\nThe value of f(𝑥) = 𝑒^𝑥 + 𝑥^3 − 2 at the point %lf is: %.4lf", x, y);

    //f(x) = 3x + 2x^2
    double y2 = add(mul(x,3),mul(Power(x,2),2));
    printf("\nThe value of f(𝑥) = 3𝑥 + 2𝑥^2 at the point %lf is: %.4lf", x, y2);

    //f(x) = (4x^3)/5 - 2x
    double y3 = sub(div(mul(Power(x,3),4),5),mul(x,2));
    printf("\nThe value of f(𝑥) = (4𝑥^3)/5 - 2𝑥 at the point %lf is: %.4lf\n", x, y3);

    return 0;
}


