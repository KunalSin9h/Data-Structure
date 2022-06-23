/**
 * Absolute of complex number is it's distance from origin
 * Syntax: abs(c)
 **/

#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

int main(){

    int N;std::cin >> N;
    std::vector<std::complex<double>> A;

    /**
     * Q: given the points in 2D plain sort them in closset to farthest from origin
     **/

    for(int i = 0; i < N; ++i){
        double x, y;
        std::cin >> x >> y;
        A.emplace_back(x, y);
    }

    std::sort(A.begin(), A.end(), [&](auto &c1, auto &c2)->bool{
        return abs(c1) < abs(c2);
    });

    for(auto &cmpx : A){
        std::cout << cmpx << ' ';
    }
    std::cout << '\n';
    return 0;
}