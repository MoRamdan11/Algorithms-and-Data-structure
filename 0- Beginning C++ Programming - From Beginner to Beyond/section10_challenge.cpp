// Section 10: Characters and Strings
// Challenge
#include <iostream>
#include <string>
using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key      {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string original_message{}, encrypted_message{}, decrypted_message{};
    cout << "Enter your message: ";
    getline(cin, original_message);
    int char_index{};
    for(auto c : original_message) {
        if(alphabet.find(c) == std::string::npos) {
            encrypted_message.push_back(c);
            continue;
        }
        char_index = alphabet.find(c);
        encrypted_message.push_back(key.at(char_index));
    }
    cout << "Encrypted Message: " << encrypted_message << endl;
    for(auto c : encrypted_message) {
        if(key.find(c) == std::string::npos) {
            decrypted_message.push_back(c);
            continue;
        }
        char_index = key.find(c);
        decrypted_message.push_back(alphabet.at(char_index));
    }
     cout << "Decrypted Message: " << decrypted_message << endl;
    return 0;
}
