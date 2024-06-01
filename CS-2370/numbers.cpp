//
//  numbers.cpp
//  CS-2370
//
//  Created by Braeden's UVU account on 5/23/24.
//

#include <iostream>

using namespace std;
bool flip = false;
// TODO: Write recursive PrintNumPattern() function

int PrintNumPattern(int num1, int num2) {
    if (num1 > 0 && flip = false) {
        cout << num1 << " ";
        PrintNumPattern(num1 - num2, num2);
    } else if (num1 < 0) {
        cout << num1 << " ";
        PrintNumPattern(num1 + num2, num2);
        cout << " ";
        PrintNumPattern(num1 - num2, num2);
    }

    return 0;
}

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   PrintNumPattern(num1, num2);
   
   return 0;
}
