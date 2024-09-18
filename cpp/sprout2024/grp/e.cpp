#include <iostream>
#include <vector>
#include <cmath>

const int MIN = 100000;  // 10^5
const int MAX = 999999; // 10^6
const int SIZE = MAX - MIN + 1;

std::vector<bool> generatePrimeTable() {
    std::vector<bool> isPrime(SIZE, true);
    
    // 0 and 1 are not prime
    if (MIN <= 1) {
        isPrime[0] = false;
        if (MIN == 0) isPrime[1] = false;
    }

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= MAX; ++i) {
        if (i * i >= MIN) {
            for (int j = i * i - MIN; j < SIZE; j += i) {
                isPrime[j] = false;
            }
        } else {
            int start = (MIN + i - 1) / i * i - MIN;
            for (int j = start; j < SIZE; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

int main() {
    std::vector<bool> primeTable = generatePrimeTable();

    std::cout << "bool primeTable[" << SIZE << "] = {";
    for (int i = 0; i < SIZE; ++i) {
        if (i % 20 == 0) std::cout << "\n    ";
        std::cout << (primeTable[i] ? "1" : "0") << ",";
    }
    std::cout << "\n};\n";

    return 0;
}