#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>
#include <chrono>

void heapSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);

void measureSortTime(void (*sortFunc)(std::vector<int>&), 
                    std::vector<int> arr, 
                    const std::string& sortName);

#endif // SORTER_H