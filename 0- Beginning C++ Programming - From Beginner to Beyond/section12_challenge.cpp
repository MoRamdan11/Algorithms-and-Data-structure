// Section 12: Pointers and References
// Challenge
#include <iostream>

using namespace std;

void print(const int *const arr, size_t arr_size);
int* apply_all(const int *const arr1, size_t arr1_size, const int *const arr2, size_t arr2_size);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    
    cout << endl;
    delete [] results;
    return 0;
}

void print(const int *const arr, size_t arr_size) {
  cout << "[ ";
  for(size_t i{}; i < arr_size; i++) 
    cout << *(arr + i) << " ";
  cout << "]" << endl;
}

int* apply_all(const int *const arr1, size_t arr1_size, const int *const arr2, size_t arr2_size) {
  int *result = new int[arr1_size * arr2_size];
  int count{};
  for(size_t i{}; i < arr2_size; i++) {
    for(size_t j{}; j < arr1_size; j++) {
      result[count++] = arr1[j] * arr2[i];
    }
  }
  return result;
}