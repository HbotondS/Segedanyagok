#ifndef LABOR_1_FUNCTIONS_H
#define LABOR_1_FUNCTIONS_H

#include <iostream>
using namespace std;

int countBits(int number);
int setBit(int number, int order);
int setBit2(int& number, int oder);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
double * max2(double array[], int numElements);
string capitalizeWords(string text);
string code(string text);
string decode(string text);
int splitText(string text);

#endif //LABOR_1_FUNCTIONS_H
