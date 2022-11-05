#include <iostream>
#include <stack>
#include <string>
using namespace std;
string  suffixWithUnit ( double number ) {
    int intNumber = number;
    int counter = 0;
    stack<int> stack1;
    while (intNumber != 0) {
        int temp = intNumber%1000;
        intNumber /= 1000;
        stack1.push(temp);
        counter++;
    }
    string result = to_string(stack1.top());
    stack1.pop();
    if (counter > 1) {
        result += ".";
    }
    counter--;
    while (!stack1.empty()) {
        result += to_string(stack1.top());
        stack1.pop();
    }
    if (counter == 1) result = result + " " + "Kilo";
    if (counter == 2) result = result + " " + "Mega";
    if (counter == 3) result = result + " " + "Giga";
    if (counter == 4) result = result + " " + "Tera";
    if (counter == 5) result = result + " " + "Peta";
    if (counter == 6) result = result + " " + "Exa";
    return result;
}
int main () {
    cout << suffixWithUnit(123) << endl;
    cout << suffixWithUnit(1234) << endl;
    cout << suffixWithUnit(12345) << endl;
    cout << suffixWithUnit(1234567) << endl;
    cout << suffixWithUnit(1234567890) << endl;
    return 0;
}