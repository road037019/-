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
                count += jumpFloorII(i); //�ܵ����Ĵ����϶��ǵ�һ����1�� + ��һ����2�� + ��һ����3�� + ������+ ��һ����n-1���� +
        return count + 1; //һ��ȫ���ꣻ
    }
};