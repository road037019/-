#include <iostream>
 using namespace std; 
	
class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;
        
        int count = 0;// ���������� 
      // i����ܳ���n��Լ����ͬ��j
    for (int i = 0; i <= number / 1; i++) {
        for (int j = 0; j <= number / 2; j++) {
            if (1 * i + 2 * j == number) {
            	// count++;// �������������ҵ���һ������
                count = count + C(i, i + j);//i+j����Ծ�У���1��̨�׵Ŀ��ܴ�����ÿ����һ������
							            	//(�ҵ���1��λ�ã���ʣ��Ϊ2��λ�á���������2����λ��Ҳ���ԣ�
            	//cout << count << '\n' << C(i, i + j)<< endl; 
            }
        }
    }
      return count;
   }
 
   // ��������
    static unsigned long long  A(long long up, long long bellow) { //��������forѭ������bellow�����ӣ���Ѹ�ٵ����ӣ� 
       unsigned long long result = 1;
       for (long long i = up; i > 0; i--) {
           result *= bellow;
           bellow--;
       }
       return result;
   }
 
   // �������
     static unsigned long long C(long long up, long long below) {
         if(up == 0)
             return 1;
         else{
             // ��ĸ
             unsigned long long denominator = A(up, up); // A(6,6)������6*5*4*3*2*1,Ҳ������6�Ľ׳�
             // ����
             unsigned long long numerator = A(up, below);// ���ӵ�������
             if(denominator != 0)
                 return numerator / denominator;
             else 
                 return 0; 
         }
    }
};

int main(){
	Solution a;
 	int result = a.jumpFloor(29);
	cout << endl << result << endl; 
	//cout << sizeof(long long) << endl; 
}