#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

/**
Course:  CS213 - Programming II  - 2018
Title:   Assignment 2 - Task 2 - Problem 0
Program: CS213-2018-A2-T2
Purpose: Mathematics operations on bigIntegers
Authors: 1- Name :- Nada Nasser Al-Said El-Azab .................. ID :- 20170369
         2- Name :- Hanan Mohamed Abd-El-Rahim  .................. ID :- 20170375
         3- Name :- Farah Mohamed Osama Mostafa .................. ID :- 20170351
Date:    31 November 2018
Version: 2.0
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
using namespace std;

class BigDecimalInt
{
    //to take the bigNumber from the user directly
    friend ostream& operator << (ostream& , BigDecimalInt);

    public:
        BigDecimalInt(); // default constructor that make the number = 0

        BigDecimalInt (string decStr); // Initialize from string and store it in a string
        BigDecimalInt (int decInt);    // Initialize from integer and store it in a string

        BigDecimalInt operator + (BigDecimalInt anotherDec);
        // take 2 objects , check the sign of the output and return the sum

        BigDecimalInt operator - (BigDecimalInt anotherDec);
        // take 2 objects , check the sign of the output and return the sub

    protected:

    private:
        string BigNumber; // to store the number without the sign
        string sign; // to store the sign

        int NumberSize; // store the size with no signs and additional zeros


};
void AddZeroes(int n , string& s); // it add zeros at the end of the matrix to make the operations easier

string RemoveZeros(string strNum); //  it add zeros at the end of the matrix to make the operations easier

void FindSmallerAndBigger(string &bigger , string &smaller , bool &isAssumptionTrue); // To determine which number is bigger
                                    // so that we can determine the output sign of the operators correctly

#endif // BIGDECIMALINT_H


