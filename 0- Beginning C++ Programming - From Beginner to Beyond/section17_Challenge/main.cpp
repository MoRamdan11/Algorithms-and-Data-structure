// Section 17: Smart Pointers
// Challenge
#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::unique_ptr;

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr;
    ptr = std::make_unique<vector<shared_ptr<Test>>>();
    return ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    for(int i{}; i < num; i++) {
        cout << "Enter data [" << i+1 << "]" <<  endl;
        int data{};
        cin >> data;
        vec.push_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>>&vec) {
    for(const auto vec_element : vec) {
        cout << vec_element->get_data() << endl;   
    }
}