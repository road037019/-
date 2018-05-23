//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

#include <iostream>
#include <stack>
using namespace std; 
			
class Solution {
public:
    void push(int value) {
        _v.push(value);
        if(_min.empty() || value < _min.top())  //这儿有两个思想比较重要：①，采用一个_min栈来随时的保存新push进去数据之后的最小值
                                                //②需要判断_min是不是空，不能判断_v是不是空，因为该句的上一句已经使得_v不为空了。
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