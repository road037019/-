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
        //vector<int> v;  //�����������������������
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
        
        //��α�������Ҫʹ�ö��У�
        vector<int> v;
        if(root == NULL) //��һ�εĴ���һֱ��ջ������󣬲����˽�����Сʱ��ֻ��ȱ��root�Ƿ�Ϊ�յ��жϣ�
            return v;
        queue<TreeNode *> q;
        q.push(root); //��Ҫע����ǣ����û�������if���Ļ�����ʹrootΪNULL���þ���Ȼ�ᱻִ�У����� 
        while(!q.empty()){  //while��Ϊ�� 
            TreeNode* temp = q.front(); //���tempȡ������NULL 
            q.pop();  
            v.push_back(temp->val); //��NULLȡval���ͻ����ջ����Ĵ��� 
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