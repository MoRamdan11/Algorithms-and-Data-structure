// Section 19: IO and Streams
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "Enter the substring to search for: ";
    std::string input_word{};
    cin >> input_word;
    ifstream file {"./romeoandjuliet.txt"};
    if(!file) {
        cout << "File Not Found" << endl;
        return 1;
    }
    std::string word;
    int count{};
    while(file >> word) {
        if(word.find(input_word) != std::string::npos)
            count++;
    }
    cout << "The substring " << input_word << " was found in " 
        << count << " times";
    return 0;
}