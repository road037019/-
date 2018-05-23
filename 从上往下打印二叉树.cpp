#include <iostream>
#include <queue>
using namespace std;
 
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        //vector<int> v;  //代码错误，这好像是先序遍历！
        //while(root != NULL){
        //    v.push_back(root->val);
        //    if(root->left != NULL){
        //        vector<int> temp = PrintFromTopToBottom(root->left);
        //        v.insert(v.end(), temp.begin(), temp.end());
        //    }
        //    if(root->right != NULL){
        //        vector<int> temp = PrintFromTopToBottom(root->right);
        //        v.insert(v.end(), temp.begin(), temp.end());
        //    }
        //}
        
        //层次遍历，需要使用队列；
        vector<int> v;
        if(root == NULL) //第一次的代码一直报栈溢出错误，查找了将近半小时，只是缺少root是否为空的判断；
            return v;
        queue<TreeNode *> q;
        q.push(root); //需要注意的是，如果没有上面的if语句的话，即使root为NULL，该句依然会被执行，导致 
        while(!q.empty()){  //while不为空 
            TreeNode* temp = q.front(); //这儿temp取到的是NULL 
            q.pop();  
            v.push_back(temp->val); //对NULL取val，就会产生栈溢出的错误； 
            if(temp->left)
                q.push(temp->left);
            if(temp->right){
                q.push(temp->right);
            }
        }
        return v;
    }
};

int main(){
	TreeNode N1(1), N2(2), N3(3), N0(0);
	N1.left = &N2;
	N1.right = &N3;
	Solution s;
	vector<int> v = s.PrintFromTopToBottom(&N1);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	
	return 0; 
}