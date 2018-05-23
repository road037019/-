#include <iostream>
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i]) //对于一个子问题，
				                          //1、子问题的最长子序列的长度要小于等于你当前的数值
										  //2、通过1可以计算出若干子序列的长度值，需要选择里面最长的，也就是d[j]+1>d[i] 
                d[i] = d[j] + 1;
        if(d[i]>len) len = d[i];   //将最长子序列的长度值放到length中； 
    }
    delete[] d;
    return len;
}
int main(){
    int A[] = {
        5, 3, 4, 8, 6, 7, 8 
    };
    cout<<lis(A, 7)<<endl;
    return 0;
}