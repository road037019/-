class Solution {
public:
    int jumpFloor(int number) {
         if (number< 1) {
             return 0;//���С��1����������
         }
 
         if (number == 1) {
             return 1;//ʣ��һ���Ļ���ֻ��һ������ 
         }
        
         if (number == 2){  //ʣ�������Ļ��������������� 
             return 2;
         }
 
         return jumpFloor(number - 1) + jumpFloor(number - 2);//ÿ����Ծ��ʣ��Ϊn-3����n-5����Ϊ�´δ���Ծ��̨����

        
    }
};