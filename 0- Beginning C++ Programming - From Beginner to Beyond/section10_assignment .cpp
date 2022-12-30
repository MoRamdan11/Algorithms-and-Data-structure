// Section 10: Characters and Strings
// Assignment
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s {};
  size_t tabs{s.length() - 1};
  cout << "Enter your letters: ";
  getline(cin, s);
  for(int i{0}; i < s.length(); i++) {
    for(size_t tab{0}; tab < tabs; tab++)
      cout << " ";
    for(int j{0}; j < i; j++) {
      cout << s.at(j);
    }
    cout << s.at(i);
    for(int j{i - 1}; j >= 0; j--) {
      cout << s.at(j);
    }
    cout << endl;
    tabs--;
  }
}