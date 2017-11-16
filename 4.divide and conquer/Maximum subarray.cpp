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
#include <limits.h>
using namespace std;
//寻找跨越中点的最大子数组；
void find_crossing_subarray(int*a, int low, int mid, int high, int& start, int& end, int& max_sum) {
    int sum = 0;
    int left_sum = INT32_MIN;
    for (int i = mid; i>=low; i--) {
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            start = i;
        }
    }
    sum =0;
    int right_sum = INT32_MIN;
    for(int i = mid+1;i <= high;i++){
        sum += a[i];
        if(sum > right_sum){
            right_sum = sum;
            end = i;
        }
    }
    max_sum = left_sum + right_sum;
}
void find_maximum_subarray(int*a, int low, int high, int &start, int &end, int &max_sum) {
    if(low == high){
        start = low;
        end = high;
        max_sum = a[low];
    }
    else{
        int mid = low + (high - low)/2;
        int left_start ,left_end,left_sum;
        find_maximum_subarray(a, low, mid,left_start,left_end,left_sum);//寻找左边区间的最大子数组
        int right_start,right_end,right_sum;
        find_maximum_subarray(a, mid+1, high, right_start, right_end, right_sum);//寻找右边区间的最大子数组
        int cross_start,cross_end,cross_sum;
        find_crossing_subarray(a, low,mid, high, cross_start, cross_end,  cross_sum);//寻找跨越中间点的最大子数组
        //比较
        if ((left_sum >= cross_sum) && (left_sum >= right_sum)) {
            start = left_start;
            end = left_end;
            max_sum = left_sum;
        }
        else if ((cross_sum >= left_sum) && (cross_sum >= right_sum)) {
            start = cross_start;
            end = cross_end;
            max_sum = cross_sum;
        }
        else {
            start = right_start;
            end = right_end;
            max_sum = right_sum;
        }
    }
}
int main() {
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int max=0,start = 0,end = 0;
    find_maximum_subarray(a, 0, 12, start, end, max);
    cout << "最大子区间和为：" << endl << max <<endl;
    cout << "开始和截止下标为：" << start << ","<< end << endl;
}

