#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	int temp = base;
        if(exponent == 0)
            return 1;
        
        else if(exponent > 0){
            for(int i = 0; i < exponent - 1; i++){
                base *= temp;
            }
            return base;
        }
        else{
            for(int i = 0; i < -exponent -1; i++){
                base *= temp;
            }
            return 1/base;
        }
    }
};
int main(){
	Solution s;
	cout << s.Power(3, 2);
	return 0;
}