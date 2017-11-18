//
//  main.cpp
//  test
//
//  Created by Ran on 2017/11/18.
//  Copyright © 2017年 Ran. All rights reserved.
//
#include <iostream>
#include<vector>
using namespace std;
int  partition(vector <int > &vi ,int low, int up ){ // vector的初始化
    int x = vi[up];
    int i = low -1 ;   //i = -1
    for (int j = low;j < up;j++)
    {
        if(vi[j] <= x){ //如果比较元素大于轴，则仅有j+1，反之则先i = i+1,后交换vi[j],vi[i]
            i = i + 1;
            swap(vi[j],vi[i]);
        }
    }
    swap(vi[i+1],vi[up]);// 最后交换轴跟i与j之间的第一个元素
    return i+1;
}


void quicksort(vector<int> &vi,int low, int up){
    if(low < up)
    {
        int mid = partition(vi,low,up);//先找mid
        quicksort(vi, low, mid-1);
        quicksort(vi, mid+1, up);
    }
}




int main (){
    int a[11]={3,5,7,9,2,3,1,0,7,5,4};
    vector<int> va(a,a+11);
    cout<<"before quicksort:\n";
    for(auto x:va)
        cout<<x<<" ";
    cout<< endl;
    quicksort(va,0,int(va.size())-1);
    cout<<"After quicksort:\n";
    for(auto x:va)
        cout<<x<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
