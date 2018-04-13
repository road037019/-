class Solution {
public:
    int jumpFloorII(int number) {
        int count = 0;
        if(number <= 0)
            return 0;
        else if(number == 1)
            return 1;
        else
            for(int i = 1; i < number; i++)
                count += jumpFloorII(i); //总的跳的次数肯定是第一步跳1阶 + 第一次跳2阶 + 第一次跳3阶 + ···+ 第一次跳n-1阶梯 +
        return count + 1; //一次全跳完；
    }
};