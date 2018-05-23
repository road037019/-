#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //if(pushV.size() != popV.size()) //题意理解错误；
        //    return 0;
        //else{
        //    for(int i = 0; i < pushV.size(); i ++){
        //        if(pushV[i] != popV[popV.size()-1-i])
        //            return 0;
        //    }
        //    return 1;
        //}
        
        if(pushV.size() != popV.size())
            return 0;
        stack<int> temp;
        int j = 0;
        for(int i = 0; i < pushV.size(); i ++){ //不管怎么样，需要将pushV序列中的所有元素都压进栈中。
            temp.push(pushV[i]); 
            while( !temp.empty() && temp.top() == popV[j]){ //如果栈顶元素等于弹出序列对应的数字，就弹出。注意可能连续弹出多次，所以使用的是while
                temp.pop();
                j++;
            }
        }
        return temp.empty() ? 1 : 0;
    }
};
int main(){
	vector<int> v1 = {1, 2};
	vector<int> v2 = {2, 1};
	Solution s;
	s.IsPopOrder(v1, v2);
} 