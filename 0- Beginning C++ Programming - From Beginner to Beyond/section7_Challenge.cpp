// Section 7: Arrays and Vectors
// Challenge

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vector1;
    vector<int> vector2;
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Elements of vector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "Size of vecotr1: " << vector1.size() << endl;
    cout << "====================================================" << endl;
    vector2.push_back(100);
    vector2.push_back(200);
    cout << "Elements of vector2: " << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "Size of vector2: " << vector2.size() << endl;
    cout << "====================================================" << endl;
    vector <vector<int>> vector_2D;
    vector_2D.push_back(vector1);
    vector_2D.push_back(vector2);
    cout << "Elements of 2D Vectors: " << endl;
    cout << vector_2D.at(0).at(0) << endl;
    cout << vector_2D.at(0).at(1) << endl;
    cout << vector_2D.at(1).at(0) << endl;
    cout << vector_2D.at(1).at(1) << endl;
    cout << "====================================================" << endl;
    vector1.at(0) = 1000;
    cout << "Elements of 2D Vectors: " << endl;
    cout << vector_2D.at(0).at(0) << endl;
    cout << vector_2D.at(0).at(1) << endl;
    cout << vector_2D.at(1).at(0) << endl;
    cout << vector_2D.at(1).at(1) << endl;
    cout << "Elements of vector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    return 0;
}