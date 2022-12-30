// Section 20: The Standard Template Library (STL)
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    std::string word{};
    std::stack<char> stack_of_string;
    std::queue<char> queue_of_string;
    for(auto c : s) {
        if(isalpha(c)) {
            c = tolower(c);
            stack_of_string.push(c);
            queue_of_string.push(c);
        }
    }
    char stack_top{}, queue_front{};
    bool check_palindrome{true};
    while(!stack_of_string.empty()) {
        stack_top = stack_of_string.top();
        stack_of_string.pop();
        queue_front = queue_of_string.front();
        queue_of_string.pop();
        if(stack_top != queue_front) {
            check_palindrome = false;
            break;
        }
    }
    return check_palindrome;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}