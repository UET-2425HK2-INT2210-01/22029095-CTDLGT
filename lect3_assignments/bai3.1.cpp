#include <iostream>
using namespace std;

void printComplexityOrder() {
    cout << "Ascending order of functions based on Big-O complexity:\n";
    cout << "1. O(1)         -> 2^10 (constant)\n";
    cout << "2. O(log n)     -> 2^log n\n";
    cout << "3. O(n)         -> 3n + 100log n, 4n\n";
    cout << "4. O(n log n)   -> n log n\n";
    cout << "5. O(n^2)       -> n^2 + 10n\n";
    cout << "6. O(n^3)       -> n^3\n";
    cout << "7. O(2^n)       -> 2^n\n";
}

int main() {
    printComplexityOrder();
    return 0;
}

