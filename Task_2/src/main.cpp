#include "../include/interpolation_sort.h"
#include "../include/binpow.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int searchElement( std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::srand(std::time(nullptr));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::vector<int> arr;
    for(int i = 1; i <= 100; ++i) {
        arr.push_back(i);
    }
    
    std::random_shuffle(arr.begin(), arr.end());
    arr.resize(n);
    interpolationSort(arr);

    int target;
    std::cout << "\nВведите элемент для поиска: ";
    std::cin >> target;

    int index = searchElement(arr, target);
    
    if (index != -1) {
        int mod;
        std::cout << "\nВведите модуль: ";
        std::cin >> mod;
        
        int size = arr.size();
        int result = binpow(index, size, mod);
        
      std::cout << "\nРезультат:\n";
        std::cout << index << "^" << size << " mod " << mod << " = " << result << "\n";
    }
    else {
        std::cout << "Элемент " << target << " не найден в массиве." << std::endl;
    }
     
    return 0;
}

