//
//  main.cpp
//  Fibonacci Numbers
//
//  Created by Matthew Allen Lin on 9/2/15.
//  Copyright (c) 2015 Matthew Allen Lin. All rights reserved.
//

#include <iostream>
int fibCount = 0, memoizedFibCount = 0;

int fib(int n);
int helpFib(int n, int k, int fibk, int fibk1);
int memoizedFib(int n);

int main(int argc, const char * argv[]) {
    int inputNumber;
    std::cout << "Enter the fibonacci number you want to calculate\n";
    std::cin >> inputNumber;
    
    int fibonacciNumber = fib(inputNumber);
    std::cout << "The fibonacci number at " << inputNumber << " is " << fibonacciNumber << std::endl;
    std::cout << "This took " << fibCount << " steps to calculate using simple recursion\n";
    
    int memoizedFibonacciNumber = memoizedFib(inputNumber);
    std::cout << "The fibonacci number at " << inputNumber << " is " << memoizedFibonacciNumber << std::endl;
    std::cout << "This took " << memoizedFibCount << " steps to calculate using recursion and memoization\n";
    
    return 0;
}

//O(2^n)
int fib(int n) {
    fibCount++;
    
    if (n <= 1)
        return n;
    else
        return (fib(n-1) + fib(n-2));
}

int helpFib(int n, int k, int fibk, int fibk1) {
    memoizedFibCount++;
    
    if (n == k)
        return fibk;
    else
        return helpFib(n, k+1, fibk+fibk1, fibk);
}

//O(n)
int memoizedFib(int n) {
    return helpFib(n, 1, 1, 0);
}