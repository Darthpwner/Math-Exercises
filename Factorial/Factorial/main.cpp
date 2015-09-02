//
//  main.cpp
//  Factorial
//
//  Created by Matthew Allen Lin on 9/2/15.
//  Copyright (c) 2015 Matthew Allen Lin. All rights reserved.
//

#include <iostream>
int findFactorialCount = 0;

int findFactorial(int n);

int main(int argc, const char * argv[]) {
    int factorial;
    std::cout << "Enter the number whose factorial you want to compute\n";
    std::cin >> factorial;
    
    int factorialResult;
    factorialResult = findFactorial(factorial);
    
    std::cout << "The factorial of " << factorial << " is " << factorialResult << std::endl;
    std::cout << "This took " << findFactorialCount << " steps to compute\n";
    
    return 0;
}

int findFactorial(int n) {
    findFactorialCount++;
    
    if (n == 0)
        return 1;
    else
        return (n * findFactorial(n-1));
}
