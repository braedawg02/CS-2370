//
//  AuthoringAssistant.cpp
//  CS-2370
//
//  Created by Braeden's UVU account on 5/23/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool quit = false;

void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
}

int GetNumOfNonWSCharacters(const string &userString)
{
    int count = 0;
    for (int i = 0; i < userString.size(); i++)
    {
        if (userString.at(i) != ' ')
        {
            count++;
        }
    }
    return count;
}
int GetNumOfWords(const string &userString)
{
    int count = 0;
    for (int i = 0; i < userString.size(); i++)
    {
        if (userString.at(i) == ' ' && userString.at(i - 1) != ' ')
        {
            count++;
        }
    }
    count++;
    return count;
}
int FindText(string userWord, string userString)
{
    int count = 0;
    for (int i = 0; i < userString.size(); i++)
    {
        if (userString.at(i) == userWord.at(0))
        {
            for (int j = 0; j < userWord.size(); j++)
            {
                if (userString.at(i + j) == userWord.at(j))
                {
                    count++;
                }
            }
        }
    }
    return (count / userWord.size());
}
void ReplaceExclamation(string& userText){
    for (int i = 0; i < userText.size(); i++)
    {
        if (userText.at(i) == '!')
        {
            userText.at(i) = '.';
        }
    }

}
void ShortenSpace(string& userText){
    for (int i = 0; i < userText.size(); i++)
    {
        if (userText.at(i) == ' ' && userText.at(i + 1) == ' ')
        {
            userText.erase(i, 1);
            i--;
        }
    }
}
void ExecuteMenu(char choice, string userText)
{
    string userWord;
    switch (choice)
    {
    case 'c':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userText) << endl << endl;
        PrintMenu();
        break;
    case 'w':
        cout << "Number of words: " << GetNumOfWords(userText) << endl << endl;
        PrintMenu();
        break;
    case 'f':
        cout << "Enter a word or phrase to be found:" << endl;
        cin.ignore();
        getline(cin, userWord);
        cout << "\"" << userWord << "\"" << " instances: " << FindText(userWord, userText) << endl << endl;
        PrintMenu();
        break;
    case 'r':
        ReplaceExclamation(userText);
        cout << "Edited text: " << userText << endl << endl;
        PrintMenu();
        break;

    case 's':
        ShortenSpace(userText);
        cout << "Edited text: " << userText << endl << endl;
        PrintMenu();
    case 'q':
        quit = true;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
        PrintMenu();
    }
}
int main()
{
    string userString;

    cout << "Enter a sample text:" << endl;
    getline(cin, userString);
    cout << endl;
    cout << "You entered: " << userString << endl;
    cout << endl;
    PrintMenu();
    while (quit == false)
    {

        char choice;
        cin >> choice;
        ExecuteMenu(choice, userString);
    }
    return 0;
}
