// Section 20: The Standard Template Library (STL)
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

template<typename T>
void display_deque(const std::deque<T> &deq) {
    std::cout << "[ ";
    for(const auto &e : deq)
        std::cout << e << " ";
    std::cout << " ]" << std::endl;
}

bool is_palindrome(const std::string& s)
{
    std::deque<char> front_deque;
    std::deque<char> back_deque;
    std::copy_if(s.begin(), s.end(), std::front_inserter(front_deque), [](char x) {
        return (!isalpha(x));
    });
    std::copy_if(s.begin(), s.end(), std::back_inserter(back_deque), [](char x) {
        return (!isalpha(x));
    });
    return (std::equal(front_deque.begin(), front_deque.end(), back_deque.begin()));
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