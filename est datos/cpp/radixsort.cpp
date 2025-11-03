#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>  

void printArray(const std::string& prefix, const std::vector<int>& arr) {
    std::cout << prefix;
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void countingSort(std::vector<int>& arr, int exp1) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0); 

    for (int i = 0; i < n; i++) {
        int index = arr[i] / exp1;
        count[index % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = arr[i] / exp1;
        output[count[index % 10] - 1] = arr[i];
        count[index % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int max1 = *std::max_element(arr.begin(), arr.end());

    for (int exp = 1; max1 / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {10, 34, 21, 45, 78, 12, 90, 34};
    printArray("Antes de ordenar: ", arr);
    radixSort(arr);
    printArray("Despues de ordenar: ", arr);

    return 0;
}