#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
 	TreeNode *left;
  	TreeNode *right;
   	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() && vin.empty())  //递归基的第一种情况，vector的大小为空，此时只需要直接返回空即可；
            return NULL;
        else if(pre.size() == 1){  //递归基的第二种情况，vector的大小为1，此时需要构造一个数值为vector中的数值的树节点，然后返回即可
        	TreeNode *root = new TreeNode(pre[0]);
        	return root;
        }else{
        	
            TreeNode *root = new TreeNode(pre[0]);
            //cout << root->val<<endl; 
            
            vector<int>::iterator r = find(vin.begin(), vin.end(), pre[0]); //找左右子树的分割点； 
            auto distance = r - vin.begin(); //因为r是vin的迭代器，在pre中不能用，所以在这儿转化一下，变成可以在pre中使用的距离； 
            
            //求解左右子树的前序和中序遍历序列 
            vector<int> vin_left(vin.begin(), r);    //中序遍历序列的左子树 
            vector<int> vin_right(r+1, vin.end());    //中序遍历序列的右子树 
            vector<int> pre_left(pre.begin()+1, pre.begin() + distance + 1 ); //前序遍历序列的左子树 
            vector<int> pre_right(pre.begin() + distance + 1, pre.end());   //前序遍历序列的左子树 
            
            //将左右子树合成一颗完整的树； 
            root->left = reConstructBinaryTree(pre_left, vin_left);
            root->right = reConstructBinaryTree(pre_right, vin_right);
            
            return root;
        }
    }
    
int main()
{
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin = {4,7,2,1,5,3,8,6};
	
	TreeNode *root = reConstructBinaryTree(pre,vin);
	return 0;
}
