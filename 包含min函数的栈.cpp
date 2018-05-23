//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

#include <iostream>
#include <stack>
using namespace std; 
			
class Solution {
public:
    void push(int value) {
        _v.push(value);
        if(_min.empty() || value < _min.top())  //���������˼��Ƚ���Ҫ���٣�����һ��_minջ����ʱ�ı�����push��ȥ����֮�����Сֵ
                                                //����Ҫ�ж�_min�ǲ��ǿգ������ж�_v�ǲ��ǿգ���Ϊ�þ����һ���Ѿ�ʹ��_v��Ϊ���ˡ�
            _min.push(value);
        else
            _min.push(_min.top());
    }
    void pop() {
        _v.pop();
        _min.pop();
    }
    int top() {
        return _v.top();
    }
    int min() {
        return _min.top();
    }
    
private:
    stack<int> _v;
    stack<int> _min;
};

int main(){
	Solution s;
	s.push(1);
}