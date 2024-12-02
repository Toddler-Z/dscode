#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "HeapSort.h"

void RandomSequenceGenerator(std::vector<int>& vec, size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 2000000);
    
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
}

void SortedSequenceGenerator(std::vector<int>& vec, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(i);
    }
}

void ReverseSequenceGenerator(std::vector<int>& vec, size_t size) {
    for (size_t i = size; i > 0; --i) {
        vec.push_back(i);
    }
}

void RepetiveSequenceGenerator(std::vector<int>& vec, size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        vec.push_back(i);
    }
    for (size_t i = 0; i < size / 2; ++i) {
        vec.push_back(i);
    }
}
 // 检查排序结果是否正确
bool check(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false; // 如果有元素比前一个小，说明排序错误
        }
    }
     return true; // 如果顺序正确，返回true
    
}
void testheapsort(std::vector<int>& vec){
    // 测试HeapSort
    HeapSort<int> heapsort;
    auto start = std::chrono::high_resolution_clock::now();
    heapsort.heapsort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> heap_duration = end - start;
    std::cout << "heapsort: " << heap_duration.count() << "s" << std::endl;
// 检查排序正确性
    if (check(vec)) {
        std::cout << "heapsort passed the check!" << std::endl;
    } else {
        std::cout << "heapsort failed the check!" << std::endl;
    }
}
void testsort_heap(std::vector<int>& vec){
    // 测试std::sort_heap
    HeapSort<int> heapsort;
    auto start = std::chrono::high_resolution_clock::now();
    std::make_heap(vec.begin(), vec.end());
    std::sort_heap(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sort_heap_duration = end - start;
    std::cout << "std::sort_heap: " << sort_heap_duration.count() << "s" << std::endl;
    // 检查排序正确性
    if (check(vec)) {
        std::cout << "sort_heap passed the check!" << std::endl;
    } else {
        std::cout << "sort_heap failed the check!" << std::endl;
    }
}
int main() {
    size_t size = 1000000;
    // heapsort测试序列
    std::vector<int> random_sequence1;
    RandomSequenceGenerator(random_sequence1, size);
    std::vector<int> sorted_sequence1;
    SortedSequenceGenerator(sorted_sequence1, size);
    std::vector<int> reverse_sequence1;
    ReverseSequenceGenerator(reverse_sequence1, size);
    std::vector<int> repetitive_sequence1;
    RepetiveSequenceGenerator(repetitive_sequence1, size);
    // sort_heap测试序列
    std::vector<int> random_sequence2;
    RandomSequenceGenerator(random_sequence2, size);
    std::vector<int> sorted_sequence2;
    SortedSequenceGenerator(sorted_sequence2, size);
    std::vector<int> reverse_sequence2;
    ReverseSequenceGenerator(reverse_sequence2, size);
    std::vector<int> repetitive_sequence2;
    RepetiveSequenceGenerator(repetitive_sequence2, size);

    std::cout << "Random sequence test:" << std::endl;
    testheapsort(random_sequence1);
    testsort_heap(random_sequence2);

    std::cout << "Sorted sequence test:" << std::endl;
    testheapsort(sorted_sequence1);
    testsort_heap(sorted_sequence2);

    std::cout << "Reverse sequence test:" << std::endl;
    testheapsort(reverse_sequence1);
    testsort_heap(reverse_sequence2);

    std::cout << "Repetitive sequence test:" << std::endl;
    testheapsort(repetitive_sequence1);
    testsort_heap(repetitive_sequence2);
    return 0;
}
