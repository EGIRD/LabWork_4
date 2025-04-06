#include "../include/calculate_medium.h"
#include "../include/sorting.h"
#include <algorithm>

std::vector<int> calculate_medium(std::vector<int> a) {
    std::vector<int> answer;
    
    for (size_t i = 0; i < a.size(); i += 3) {
        size_t end = std::min(i + 3, a.size());
        
        if (end - i == 3) {
            quickSort(a, i, end - 1);
            answer.push_back(a[i + 1]);
        }
        else if (end - i == 2) {
            answer.push_back((a[i] + a[i + 1]) / 2);
        }
        else {
            answer.push_back(a[i]);
        }
    }
    return answer;
}