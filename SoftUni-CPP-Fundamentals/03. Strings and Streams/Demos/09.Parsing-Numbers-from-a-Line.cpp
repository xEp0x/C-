#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main () {
    string line;
    getline(cin, line);

    istringstream lineStream(line);
    vector<int> numbers;
    int currentNumber;
    while (lineStream >> currentNumber) {
        numbers.push_back(currentNumber);
    }

    for (int number : numbers) {
        cout << number << endl;
    }

    return 0;
}
