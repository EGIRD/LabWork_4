#include "../include/sorting.h"
#include "../include/calculate_medium.h"
#include <vector>
#include <iostream>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    
    std::cout << "Вектор а: ";
    std::vector<int> arr(n);
    for (int& num : arr) {
        num = std::rand() % 20;
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Вектор b: ";
    std::vector<int> medians = calculate_medium(arr);  
    for (int& medium : medians) {
        std::cout << medium << " ";
    }
    std::cout << std::endl;

    return 0;
}