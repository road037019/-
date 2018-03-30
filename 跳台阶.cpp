class Solution {
public:
    int jumpFloor(int number) {
         if (number< 1) {
             return 0;//如果小于3，则跳不了
         }
 
         if (number == 1) {
             return 1;//只剩下3级或者5级，则只有一种跳法，跳3级或者5级，一次跳完
         }
        
         if (number == 2){
             return 2;
         }
 
         return jumpFloor(number - 1) + jumpFloor(number - 2);//每次跳跃，剩下为n-3或者n-5，作为下次待跳跃的台阶数

        
    }
};