//
//  ExceptionExamples.cpp
//  CS-2370
//
//  Created by Braeden's UVU account on 5/30/24.
//

#include "ExceptionExamples.hpp"
#include <string>
#include <iostream>

using namespace std;

int main() {
    string inputName;
    int age;
    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);
    
    try{
        cin >> inputName;
        while(inputName != "-1") {
            try{
                // FIXME: The following line will throw an ios_base::failure.
                //        Insert a try/catch statement to catch the exception.
                //        Clear cin's failbit to put cin in a useable state.
                
                cin >> age;
                cout << inputName << " " << (age + 1) << endl;
                
                cin >> inputName;
                
            } catch (ios_base::failure& error) {
                // Clear failbit to be able to use cin again
                cin.clear();
                // Throw away the rest of the failed input line from cin buffer
                string garbage;
                getline(cin, garbage);
            }
        }
    } catch(ios_base::failure& error){
        cin.clear();
        string garbage;
        getline(cin, garbage);
    }
    return 0;
    
}

