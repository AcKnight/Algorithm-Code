//
//  main.cpp
//  test
//
//  Created by Ran on 2017/11/6.
//  Copyright © 2017年 Ran. All rights reserved.
//
#include <iostream>
using namespace std;
void visitAllNode(int array[], int size)    // 访问所有数据
{
    cout << array[0];
    for (int i = 1; i < size; ++i)
    {
        cout << "-->" << array[i];
    }
    cout << endl;
}
void max_heapify(int array[], int parent, int size) // 保持最大堆性质；最大堆：根节点永远大于左、右子节点
{
    int left = 2 * (parent + 1) - 1;    // 左节点
    int right = 2 * (parent + 1);       // 右节点

    int largest;    // 寻找最大的节点位置
    if (left < size &&  array[parent] < array[left])
        largest = left;
    else
        largest = parent;
    if (right < size && array[right] > array[largest]) //注意此处跟largest比较
        largest = right;

    if (largest != parent)  // 最大值不是父节点
    {
        swap(array[parent], array[largest]);    // 交换成功
        max_heapify(array, largest, size);      // 需要保持最大堆性质
    }
}


void build_max_heap(int array[], int size){         //建立最大堆
    for(int i = size/2; i > -1; --i){               //从size/2 开始递减，因为size/2 是最大的父节点，即再大的结点都是叶子结点
        max_heapify(array,i,size);
    }
}


void heap_sort(int array[] , int size){           // 最大堆排序
    build_max_heap(array,size);                   //首先建立起最大堆
    visitAllNode(array, size);
    for(int i = size - 1; i >=1 ;i--){            //走到倒数第二个元素即可
        swap(array[0],array[i]);                 //将当前最大元素放到数组尾部
        --size;                                  //数组长度-1
        max_heapify(array, 0, size);             //原来根的孩子结点仍然是最大堆，而新的根结点可能会违背最大堆的性质，所以调用MAX_HEAPIFY(A,  0),从而在A[1...n-1]上构造一个新的最大堆
    }
}



int main(){
    int array[]={14,7,18,3,10,19,11,23,2,25,16,17};
    int size = sizeof(array)/sizeof(array[0]);
    heap_sort(array,size);
    visitAllNode(array, size);
    cout << endl;
    return 0;
}


