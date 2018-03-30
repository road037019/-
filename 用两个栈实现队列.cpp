class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {  //1、pop的时候记得返回pop到的值；
                 //2、在stack2中pop过之后记得要将数据再还原到stack1之中；
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