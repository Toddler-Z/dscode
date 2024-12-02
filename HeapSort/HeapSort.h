#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm> // 用于std::make_heap

template <typename T>
class HeapSort {
private:
    // 调整堆节点vec[i]，使得vec[i]与其左右子节点相比最大
    void percDown(std::vector<T>& vec, int i, int n) {
        int child;   // 子节点下标
        T tmp;       // 所调整节点的临时变量
        for(tmp = std::move(vec[i]); i * 2 + 1 <n ; i = child){
            child = i * 2 + 1;    //暂定为左节点
            if (child != (n -1 )&& vec[child + 1] > vec[child]) {
                child++; // 选择右节点
            }     //存在右节点且右节点大，选择右节点
            if (tmp < vec[child]) {
                vec[i] = std::move(vec[child]); // 父节点与子节点交换
            } else {
                break; // 父节点大于子节点，无需调整
            } 
        }   // 将调整节点更新为刚才替换的子节点，并调整。
             vec[i] = std::move(tmp); // 更新刚才子节点内容为刚才调整节点内容，实现交换。
    }
    

public:
    // 堆排序的主函数
    void heapsort(std::vector<T>& vec) {
        // 构建堆，使用 STL 提供的make_heap
        std::make_heap(vec.begin(), vec.end());

        // 排序，使用percDown以及循环语句从最后一个元素开始调整堆
        for (int i = vec.size() - 1; i > 0; --i) {
            pop_heap(vec.begin(), vec.begin()+i+1); // 将堆顶最大元素移到最后
            percDown(vec, 0, i - 1); // 调整堆
        }
    }
        
};

#endif // HEAPSORT_H