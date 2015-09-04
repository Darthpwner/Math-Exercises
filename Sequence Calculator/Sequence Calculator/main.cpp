//
//  main.cpp
//  Sequence Calculator
//
//  Created by Matthew Allen Lin on 9/3/15.
//  Copyright (c) 2015 Matthew Allen Lin. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <string>

//Functions
int calculateSequence(int n);

//Sequence variables
int coefficient = 0, difference = 0, arithmeticTerm = 0, baseCase = 0;
char operation, confirmation;

int main(int argc, const char * argv[]) {
    int nthTerm;
    
    do {
        std::cout << "I am about to prompt you to enter some terms for the sequence\n";
        std::cout << "Base Case: ";
        std::cin >> baseCase;
        std::cout << "Coefficient: ";
        std::cin >> coefficient;
        std::cout << "Difference: ";
        std::cin >> difference;
        while(operation != '+' && operation != '-') {
            std::cout << "Operation (Enter '+' or '-'): ";
            std:: cin >> operation;
        }
        std::cout << "Arithmetic Term: ";
        std::cin >> arithmeticTerm;
        std::cout << "Your sequence is '" << coefficient << " * a_(n - " << difference << ") " << operation << " " << arithmeticTerm << "' where a_0 = '" << baseCase << "'" << std::endl;
        std::cout << "Do you want to proceed? (Y/N): ";
        std::cin >> confirmation;
        std::cout << "\n";
    } while(tolower(confirmation) != 'y');
    
    std::cout << "Enter the nth term you want to find\n";
    std::cin >> nthTerm;
    
    //Error checking
    if(nthTerm < difference) {
        std::cout << "Error: n cannot be less than difference\n";
        exit(0);
    } else if(nthTerm % difference != 0) {
        std::cout << "Error: difference will never reach base case\n";
        exit(0);
    }
    
    int sequenceResult = calculateSequence(nthTerm);
    std::cout << "The nth term is " << sequenceResult << std::endl;
    
    return 0;
}

int calculateSequence(int n) {
    if (n == 0)
        return baseCase;
    
    if(operation == '+') {
        return coefficient * calculateSequence(n - difference) + arithmeticTerm;
    }
    
    return coefficient * calculateSequence(n - difference) - arithmeticTerm;
}

// "2 * a_(n - 1) + 2"
