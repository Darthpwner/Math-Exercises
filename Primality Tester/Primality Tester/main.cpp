//
//  main.cpp
//  Primality Tester
//
//  Created by Matthew Allen Lin on 9/2/15.
//  Copyright (c) 2015 Matthew Allen Lin. All rights reserved.
//

#include <iostream>

int steps = 0;

bool factorInRange(int k, int n);
bool isPrime(int n);

int main(int argc, const char * argv[]) {
    int number;
    std::cout << "Enter the number you want to check to see if it is prime\n";
    std::cin >> number;
    
    bool truthValue;
    truthValue = isPrime(number);
    
    if(truthValue) {
        std::cout << number << " is prime. It took " << steps << " steps to calculate\n";
    } else {
        std::cout << number << " is NOT prime. It took " << steps << " steps to calculate\n";
    }
    
    return 0;
}

bool factorInRange(int k, int n) {
    steps++;
    
    if (k >= n)                         // is the range empty?
        return false;                    // the range is empty so there are
    // no factors in the range
    else if ((n % k) == 0)              // is n divisible by k?
        return true;                     // yes, we found a factor, namely k
    else                                // k is not a factor
        return factorInRange(k+1, n);    // so let's see if there's a factor
    // among the values in the rest
    // of the range
}

bool isPrime(int n) {
    return ((n > 1) && !factorInRange(2, n));
}