#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/sorter.h"
#include "../include/binary_search.h"

int main() {
    std::srand(std::time(nullptr));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    
    std::cout << "Исходный массив: ";
    std::vector<int> arr(n);
    for (int& num : arr) {
        num = std::rand() % 20;
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    std::vector<int> sortedArr = arr;
  
    heapSort(sortedArr);
    measureSortTime(heapSort, sortedArr, "Heap Sort");
   
    quickSort(sortedArr);
    measureSortTime(quickSort, sortedArr, "Quick Sort");

    mergeSort(sortedArr);
    measureSortTime(mergeSort, sortedArr, "Merge Sort");

    std::cout << "\nОтсортированный массив: ";
    for(int &num : sortedArr) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    int target;
    std::cout << "\nВведите число для бинарного поиска: ";
    std::cin >> target;
    std::cout << "Индекс элемента: " << binarySearch(sortedArr, target) << '\n';

    return 0;
}