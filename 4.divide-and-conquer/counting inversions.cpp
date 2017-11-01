
//
//  main.cpp
//  test
//
//  Created by Ran on 2017/10/9.
//  Copyright © 2017年 Ran. All rights reserved.
//
#include <iostream>
using namespace std;
int tem[12];
int ans = 0;
void merge(int*a,int low, int mid,int high){
    int k = low;
    int j = mid+1;
    int i = low;
    while(i <= mid && j <= high){
        if(a[i] > a[j]){
            tem[k++] = a[j++];
            ans += mid - i + 1; //多这一个步骤
        }
        else{
            tem[k++] = a[i++];
        }
    }
    while(i<=mid)
        tem[k++] = a[i++];
    while(j<=high)
        tem[k++] = a[j++];
    for(int i=low;i<=high;i++)
        a[i] = tem[i];
}
void merge_sort(int* a ,int low,int high){
    if(low < high){
        int mid = low + (high - low)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a,low,mid,high);
    }
}
int main(){
    int a[]={14,7,18,3,10,19,11,23,2,25,16,17};
    int low = 0;
    int high = 11;
    merge_sort(a,low,high);
    cout <<"排好的顺序为：" <<endl;
    for(int i = 0;i <= high;i++){
        cout<< a[i]<<" ";
    }
    cout <<"逆序数对的个数为：" << ans << endl;
    return 0;
}
