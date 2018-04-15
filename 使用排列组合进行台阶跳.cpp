#include <iostream>
 using namespace std; 
	
class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;
        
        int count = 0;// 跳法总数； 
      // i最大不能超过n的约数，同理j
    for (int i = 0; i <= number / 1; i++) {
        for (int j = 0; j <= number / 2; j++) {
            if (1 * i + 2 * j == number) {
            	// count++;// 满足条件，则找到了一种跳法
                count = count + C(i, i + j);//i+j次跳跃中，跳1级台阶的可能次数，每次算一种跳法
							            	//(找到了1的位置，则剩下为2的位置。或者找跳2级的位置也可以）
            	//cout << count << '\n' << C(i, i + j)<< endl; 
            }
        }
    }
      return count;
   }
 
   // 求排列数
    static unsigned long long  A(long long up, long long bellow) { //这儿的这个for循环随着bellow的增加，会迅速的增加； 
       unsigned long long result = 1;
       for (long long i = up; i > 0; i--) {
           result *= bellow;
           bellow--;
       }
       return result;
   }
 
   // 求组合数
     static unsigned long long C(long long up, long long below) {
         if(up == 0)
             return 1;
         else{
             // 分母
             unsigned long long denominator = A(up, up); // A(6,6)就是求6*5*4*3*2*1,也就是求6的阶乘
             // 分子
             unsigned long long numerator = A(up, below);// 分子的排列数
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