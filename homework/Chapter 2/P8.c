#include <stdio.h>

#ifdef M_PI
#undef M_PI
#endif

const double M_PI = 3.141592653589793;

/*
The unit of `density` is g/cm^3, and the unit of `mass` is cm.
*/
double from_density_to_mass(double density, double r) {
    return (double)density * r * r * r * M_PI * 4.0 / 3.0;
}

int main() {
    double golddensity = 19.3; // g/cm^3
    double goldr = 100.0 / 10; // mm -> cm
    printf("The mass of gold is %lfg\n", from_density_to_mass(golddensity, goldr));
    double irondensity = 7.86; // g/cm^3
    double ironr = 150.0 / 10; // mm -> cm
    printf("The mass of iron is %lfg\n", from_density_to_mass(irondensity, ironr));
}