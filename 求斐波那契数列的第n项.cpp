class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)  //�ڵ�һ���ύ����ʱ������������©���� 
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int i = 3;
        int first = 1, second = 1;
        for(i = 3; i <= n; i ++){
            second = first + second;
            first = second - first;
        }
        return second;
    }
};