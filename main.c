#include <stdio.h>
#define PI_2 1.57079632679489661923

unsigned int factorial(unsigned int n)
{
    int result = 1, i;
 
    for(i = 2; i <= n; i++) {
        result *= i;
    }
 
    return result;
}

unsigned int power(unsigned int power, unsigned int base) {
    int result = base;

    for (int i = 2; i <= power; i++) {
        result *= base;
    }

    return result;
}

unsigned int trig_series(unsigned int x, unsigned int y) {
    return ((power(x, y))/factorial(x));
}

double dmod(double a, double b) {
    double result = (b * (a/b)) - b;
    //despite what the internet says, result = a - (b * (a/b)) is not the remainder of the function

    if(a < b && a > -b) {
        return a;
    }

    if(result == b) {
        return 1;
    }

    return result;
}

double sin(double y) {
    //double y = dmod(x, PI_2) is not necessary as it does nothing and screws up the calculation
    long double result = (y - ((y*y*y)/factorial(3)) + trig_series(5, y) - trig_series(7, y) + trig_series(9, y) - trig_series(11, y) + trig_series(13, y)) * -1;

    return result;
    //max value before inaccuracy is about 5.014
}

double cos(double y) {
    //double y = dmod(x, PI_2) is not necessary as it does nothing and screws up the calculation
    long double result = (y - ((y*y)/factorial(2)) + trig_series(4, y) - trig_series(6, y) + trig_series(8, y) - trig_series(10, y) + trig_series(12, y));

    return result;
    //max value before inaccuracy is about 1.15
}

//double cos(int x) {

//}

double tan(double x) {
    return sin(x)/cos(x);
    //i dont even know when it leaves the approximation of tan
}

//truly messed up testing
/*int main() {
    //double x = dmod(21, 6);
    double x = sin(5.014);
    double y = cos(1.15);
    double z = tan(5.05);
    printf("sin is %lf\n", x);
    printf("cos is %lf\n", y);
    printf("tan is %lf", z);
}*/