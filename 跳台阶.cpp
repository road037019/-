class Solution {
public:
    int jumpFloor(int number) {
         if (number< 1) {
             return 0;//如果小于1，则跳不了
         }
 
         if (number == 1) {
             return 1;//剩余一级的话，只有一种跳法 
         }
        
         if (number == 2){  //剩余两级的话，有两种跳法； 
             return 2;
         }
 
         return jumpFloor(number - 1) + jumpFloor(number - 2);//每次跳跃，剩下为n-3或者n-5，作为下次待跳跃的台阶数

        
    }
};