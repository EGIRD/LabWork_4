#include "../include/interpolation_sort.h"
#include "../include/binpow.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::cout << "Исходный массив: ";
    std::vector<int> arr(n);
    for(int& num : arr) {
        num = std::rand() % 20;
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    interpolationSort(arr);

    int target;
    std::cout << "Введите элемент для поиска: ";
    std::cin >> target;

    



    return 0;
}