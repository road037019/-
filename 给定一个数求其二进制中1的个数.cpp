#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 
		
			
class Solution {
public:
     int  NumberOf1(int n) {
     	//float f = 24.4;
     	//unsigned int i = 4294967296;
     	//cout << i << endl;
     	 //cout << sizeof(short)<< " " << sizeof(long) << endl;
   		 //cout << "形参：" << n << endl; 

         if(n == 0)
             return 0;
         else if(n > 0 && n < pow(2, 31) - 1){
      	  	 cout << "确认 n > 0" << endl; //由于形参n是int，也就是说是有符号型
				 						   //那么对于2147483648=1000 0000···0这个数，
									       //出去第一位是1外，其余位全是零，这样的话计算机会
										   //认为这不是一个正数，这是-2^31； 
             int count = 0, remain = 0;
             while(n != 0){
                 remain = n % 2;
                 if(remain == 1){
                     count++;
                     remain = 0;
                 }
                 n = n / 2;
             }
             return count;
         }
         else{
             unsigned int num = n; 
             cout << "num :" << num << endl;
             int count = 0;
             vector<int> bit1; 
             while(num != 0){
                  bit1.push_back(num % 2); //bit1里面数据的顺序是从高位到低位； 
                  num = num / 2;
             }
             
             //测试 
       		 for(int i = 0; i < bit1.size(); i++){
             	  cout << bit1[i] ;
             }
             cout << "原始数据" << endl; 
             
             //按位取反；
             for(int i = 0; i < bit1.size(); i++){
            	  //cout <<bit1[i] << " ";
             	  if(bit1[i] == 1)
             	  	bit1[i] = 0;
      	  	      else bit1[i] = 1;
      	  	      cout << bit1[i]; //测试按位取反； 
             	  //cout <<bit1[i] << " "; 
             }
             cout << "按位取反" << endl;

             
             //加1；
             int carry_bit = 0;
             vector<int> bit2; 

             bit1[0] += 1;
             cout << bit1[0] << endl;

             for(int i = 0; i < bit1.size(); i++){///////////?????????????
                 if(bit1[i] + carry_bit >= 2){
                     bit1[i] = bit1[i] + carry_bit - 2; //此处注意应该是先减2，再 
                 	 carry_bit = 1; //进位 
                 }
                 else{
                     bit1[i] = bit1[i] + carry_bit;
                     carry_bit = 0;
                 }
                 bit2.push_back(bit1[i]);  //bit2里面数据的顺序是从高位到低位 
             }
             
             //测试； 
             for(int i = 0; i < bit2.size(); i++){
             	 cout << bit1[i] ;
             }
             cout << endl;
             
             if (carry_bit == 1)
                 bit2.push_back(1);
             cout << "bit2.size()" << bit2.size() << endl;
             
             //计算1的数量；
             count += (32 - bit2.size());
             //cout << "count =" << count <<  endl;
             for(int i = 0; i < bit2.size(); i++){
             	 cout << bit2[i];
                 if(bit2[i] == 1)
                     count ++;
             }
             cout << endl;
             return count;
         }
         
       /*
	   //方法二； 
	     int count = 0;
         while(n != 0){
         	count ++;
			n &= (n-1);
         	
         }
         return count; */

     }
};

int main(){
	Solution s;
	cout << s.NumberOf1(4294967295) << endl;
	return 0;
}