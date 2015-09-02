//
//  main.cpp
//  GCF
//
//  Created by Matthew Allen Lin on 9/2/15.
//  Copyright (c) 2015 Matthew Allen Lin. All rights reserved.
//

#include <iostream>
int getGcfDjikstraCount = 0, getGcfEuclidCount = 0, getGcfBruteForceCount = 0;

int getGcfDjikstra(int x, int y);
int getGcfEuclid(int x, int y);
int getGcfBruteForce(int x, int y);
int tryDivisor(int x, int y, int z);

int main(int argc, const char * argv[]) {
    int x, y;
    
    std::cout << "Enter first number\n";
    std::cin >> x;
    
    std::cout << "Enter second number\n";
    std::cin >> y;
    
    int gcfDjikstra = getGcfDjikstra(x, y);
    std::cout << "GCF is " << gcfDjikstra << ". It takes " << getGcfDjikstraCount << " steps using Djikstra's Algorithm.\n";
    
    int gcfEuclid = getGcfEuclid(x, y);
    std::cout << "GCF is " << gcfEuclid << ". It takes " << getGcfEuclidCount << " steps using Euclid's Algorithm.\n";
    
    int gcfBruteForce = getGcfBruteForce(x, y);
    std::cout << "GCF is " << gcfBruteForce << ". It takes " << getGcfBruteForceCount << " steps using Brute Force.\n";
    
    return 0;
}

int getGcfDjikstra(int x, int y) {
    getGcfDjikstraCount++;
    
    if (x == y) {
        return x;
    } else if (x > y) {
        return getGcfDjikstra(x - y, y);
    } else {
        return getGcfDjikstra(x, y - x);
    }
}

int getGcfEuclid(int x, int y) {
    getGcfEuclidCount++;
    
    if ((x % y) == 0)
        return y;
    else
        return getGcfEuclid(y, x % y);
}

int getGcfBruteForce(int x, int y) {
    return tryDivisor(x, y, y);   // use y as our first guess
}

int tryDivisor(int x, int y, int z) {
    getGcfBruteForceCount++;
    
    if (((x % z) == 0) && ((y % z) == 0))
        return z;
    else
        return tryDivisor(x, y, z - 1);
}