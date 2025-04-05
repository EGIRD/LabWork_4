#include "../include/interpolation_sort.h"
#include <iostream>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void interpolationSortUtil(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;
    
    int min = arr[low], max = arr[low];
    for (int i = low + 1; i <= high; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    if (min == max) return;
    
    int pivot = low + ((arr[low] - min) * (high - low)) / (max - min);
    pivot = std::max(low, std::min(pivot, high));
    
    std::swap(arr[low], arr[pivot]);
    
    int i = low;
    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < arr[low]) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[low], arr[i]);
    
    std::cout << "После разделения: ";
    printArray(arr);
    
    interpolationSortUtil(arr, low, i - 1);
    interpolationSortUtil(arr, i + 1, high);
}

void interpolationSort(std::vector<int>& arr) {
    std::cout << "Начальный массив: ";
    printArray(arr);
    interpolationSortUtil(arr, 0, arr.size() - 1);
    std::cout << "Отсортированный массив: ";
    printArray(arr);
}