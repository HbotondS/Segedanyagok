#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int countBits(int number) {
    int n = 0;
    do {
        n += (number & 1);
    } while (number >>= 1);
    return n;
}

int setBit(int number, int order) {
    if (0 <= order || order <= 31) {
        number ^= (-1 ^ number) & (1 << order);
        return number;
    } else {
        return 0;
    }
}

int setBit2(int& number, int order) {
    if (0 <= number && number <= 31) {
        int t[32] = {0};
        for (int i = 0; number > 0; ++i) {
            t[31-i] = number % 2;
            number /= 2;
        }
        t[31-order] = 1;
        int szam = 0;
        for (int i = 31; i >= 0; --i) {
            szam += t[i]*pow(2, 31-i);
        }
        return szam;
    } else {
        return 0;
    }
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    } else {
        double sum = 0.0;
        for (int i = 0; i < numElements; ++i) {
            sum += array[i];
        }
        return sum / numElements;
    }
}

double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    } else {
        double sum = 0.0, mean, standardDeviation = 0.0;
        for (int i = 0; i < numElements; ++i) {
            sum += array[i];
        }

        mean = sum / numElements;

        for (int j = 0; j < numElements; ++j) {
            standardDeviation += pow(array[j] - mean, 2);
        }

        return sqrt(standardDeviation / numElements);
    }
}

double * max2(double array[], int numElements) {
    double * a;
    if ( !(a = (double *)malloc((numElements + 1) * sizeof(double))) ) {
        cout << "Allocation failed" << endl;
        return NULL;
    }
    if (numElements == 0) {
        a[0] = NAN;
        a[1] = NAN;
        return a;
    } else {
        if (numElements == 1) {
            a[0] = array[0];
            a[1] = array[0];
            return a;
        } else {
            sort(array, array + numElements);
            a[0] = array[numElements - 2];
            a[1] = array[numElements - 1];
            return a;
        }
    }
}

string capitalizeWords(string text) {
    text[0] = toupper(text[0]);
    for (int i = 1; i < text.length(); ++i) {
        if (text[i-1] == ' ') {
            text[i] = toupper(text[i]);
        } else {
            text[i] = tolower(text[i]);
        }
    }
    return text;
}

string code(string text) {
    for (char &currentChar : text) {
        if ('a' <= currentChar && currentChar <= 'z') {
            if (currentChar == 'z') {
                currentChar = 'a';
            } else {
                currentChar += 1;
            }
        } else {
            if ('A' <= currentChar && currentChar <= 'Z') {
                if (currentChar == 'Z') {
                    currentChar = 'A';
                } else {
                    currentChar += 1;
                }
            }
        }
    }
    return text;
}

string decode(string text) {
    for (char &currentChar : text) {
        if ('a' <= currentChar && currentChar <= 'z') {
            if (currentChar == 'a') {
                currentChar = 'z';
            } else {
                currentChar -= 1;
            }
        } else {
            if ('A' <= currentChar && currentChar <= 'Z') {
                if (currentChar == 'A') {
                    currentChar = 'Z';
                } else {
                    currentChar -= 1;
                }
            }
        }
    }
    return text;
}

int splitText(string text) {
    string delimeters = " \t,.?!";
    bool inWord = false;
    int wordCount = 0;

    for (char currentChar : text) {
        if ( delimeters.find(currentChar) == string::npos ) {
            if (!inWord) {
                inWord = true;
                ++wordCount;
            }
        } else {
            if (inWord) {
                inWord = false;
            }
        }
    }

    return wordCount;
}