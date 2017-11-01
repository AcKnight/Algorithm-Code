//
//  main.cpp
//  test
//
//  Created by Ran on 2017/10/9.
//  Copyright © 2017年 Ran. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void merge(int *data, int p, int mid, int r)
{
    int n1,n2,i,j,k;
    n1 = mid - p +1;
    n2 = r - mid;
    int *left=NULL,*right=NULL;
    left = (int *)malloc(sizeof(int)*n1);
    right = (int *)malloc(sizeof(int)*n2);
    for(i = 0;i < n1;i++){
        left[i] = data[p+i];
    }
    for(j = 0;j<n2;j++){
        right[j] = data[mid + 1+ j];
    }
    i =j =0;
    k = p;//当前数组最左端
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            data[k++] = left[i++];
        else
            data[k++] = right[j++];
    }
    for (; i<n1; i++) {
        data[k++] = left[i];
    }
    for(;j<n2;j++){
        data[k++] = right[j];
    }
    
}

void mergeSort(int *data, int p, int r)//
{
    int mid;
    if (p < r) { //还未分完
        mid = p + ((r-p)/2);
        mergeSort(data, p, mid);
        mergeSort(data, mid+1, r);
        merge(data,p,mid,r);
    }
}
int main()
{
    int n;
    int* input = NULL;
    //输入数据
    cout<<"请输入数组的长度: ";
    cin>>n;
    input = (int *)malloc(sizeof(int)*(n));
    cout<<"请对数组赋值: ";
    for(int i=0; i<n; ++i)
    {
        cin>>input[i];
    }
    //处理数据
    mergeSort(input,0,n-1);
    //输出结果
    for(int i=0; i<n; ++i)
        cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}
