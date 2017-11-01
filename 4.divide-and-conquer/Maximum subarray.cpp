#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int cross_middle(int *a,int l,int m,int r){
    int i,
        sum=0,
        l_max=INT_MIN,
        r_max=INT_MIN;
    for(i=m;i>=l;i--){
        sum+=a[i];
        if(sum > l_max) l_max=sum;
    }
    sum=0;
    for(i=m+1;i<=r;i++){//最早i=m,出现BUG
        sum+=a[i];
        if(sum>r_max) r_max=sum;
    }
    return (l_max+r_max);
}
int maxsubset(int *a,int l,int r){
    if(l == r) return a[l];
    //if(l>r) return 0;

    int m=(l+r)/2,
        l_max=INT_MIN,
        r_max=INT_MIN,
        c_max=INT_MIN;
    l_max=maxsubset(a,l,m);
    r_max=maxsubset(a,m+1,r);
    c_max=cross_middle(a,l,m,r);
    if(l_max >= r_max&&l_max >= c_max) return l_max;
    else if(r_max >= l_max&&r_max >= c_max) return r_max;
    else return c_max;
}
int main(){
    int a[]={3,-1,2,5,-3,4,-6,-7,1,8,-3,5,9};

    printf("the maxsubset:%d\n",maxsubset(a,0,12));
    return 0;
}
