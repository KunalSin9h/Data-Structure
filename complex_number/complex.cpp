#include <iostream>
#include <complex>
#include <iomanip>

int main(){

    std::complex<double> c1(-2.0, 3.0);
    // c1 = 3 + 4i


    /**
     * real and imagnery part
     **/

    std::cout << real(c1) << std::endl;
    std::cout << imag(c1) << std::endl;

    /**
     * -Absolute- of complex number
     * The absolute value of a complex number is the distance between that number and the origin (0) on the complex plane.
     **/
    std::cout << (double)abs(c1) << '\n';

    /**
     * -Argument- of complex number
     * Argument of complex number is the angle made by the line representation of the complex number, with the positive x-axis of the argand plane.
     **/
    std::complex<double> c2(-5.0, -5.0);
    std::cout << (arg(c2)*180)/M_PI << '\n'; // 225

    /**
     * -Polar- of complex number
     * ```It construct another Complex number with```
     * real = magnitude*cos(angle)
     * imag = magitude*sin(angle)
     **/
    std::complex<double> c3(2.0, 0.5);

    double magni = abs(c3);
    double angle = arg(c3);

    std::cout << std::polar(magni, angle) << '\n'; // 2.0, 0.5

    /**
     * -norm- of complex number
     * let z = a + bi
     * then
     * norm = a^2 + b^2
     **/

    std::complex<double> c4(3.0, 3.0);
    std::cout << norm(c4) << '\n';

    /**
     * -conjugate- of complex number
     * z = a + bi
     * then
     * z' = a - bi
     **/

    std::complex<double> c5(-1, -2);
    std::cout << conj(c5) << '\n';

    /**
     * square root of complex number
     * ,/(a + bi) = x + yi
     **/
    std::complex<double> c6(-4, 0);
    std::cout << sqrt(c6) << '\n';

    // we can use log, sin, cos, tan etc.
    // to complex number as its olso a number

    return 0;
}