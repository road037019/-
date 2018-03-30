class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {  //1��pop��ʱ��ǵ÷���pop����ֵ��
                 //2����stack2��pop��֮��ǵ�Ҫ�������ٻ�ԭ��stack1֮�У�
        if (stack1.empty())
            return 0;
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};