#include <iostream>
#include <vector>

class Shellsort {
public:
    static void display(const std::vector<int>& arr) {
        for (int i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    int sort(std::vector<int>& arr) {
        int size = arr.size();
        int gapsize = size / 2;

        while (gapsize > 0) {
            for (int j = gapsize; j < size; j++) {
                int temp = arr[j];
                int k = j;

                while (k >= gapsize && arr[k - gapsize] > temp) {
                    arr[k] = arr[k - gapsize];
                    k -= gapsize;
                }
                arr[k] = temp;
            }
            gapsize = gapsize / 2;
        }
        return 0;
    }
};

int main() {
    std::vector<int> arr = {12, 34, 54, 2, 3};
    std::cout << "Arreglo antes del ordenamiento:" << std::endl;
    Shellsort::display(arr);
    
    Shellsort obj;
    obj.sort(arr);
    
    std::cout << "Arreglo despues del ordenamiento:" << std::endl;
    Shellsort::display(arr);
    
    return 0;
}