#include <iostream>
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i]) //����һ�������⣬
				                          //1���������������еĳ���ҪС�ڵ����㵱ǰ����ֵ
										  //2��ͨ��1���Լ�������������еĳ���ֵ����Ҫѡ��������ģ�Ҳ����d[j]+1>d[i] 
                d[i] = d[j] + 1;
        if(d[i]>len) len = d[i];   //��������еĳ���ֵ�ŵ�length�У� 
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