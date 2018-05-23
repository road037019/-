//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

#include <iostream>
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //if(pRoot2 == NULL)
        //    return 0;
        //else if(pRoot1 == NULL && pRoot2 != NULL){
        //    return 0;
        //}
        if(pRoot1 == NULL)
            return false;
        else if(pRoot1 != NULL && pRoot2 == NULL){
            return false;
        }
        else{
            //while(pRoot1 != NULL && pRoot2!= NULL){
                //if(pRoot1->val == pRoot2->val) //这儿如果这么写判断的话，会导致陷入局部的不满足，即第一个节点满足，后一个节点不满足，就失败了
                //    return(IsSubtree(pRoot1, pRoot2));
                //else 
                    return(IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
            //}
        }
    }
    
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) //pRoot2为空，为子序列，返回真；
            return true;
        else if(pRoot1 == NULL && pRoot2 != NULL){
            return false;
        }
        //else if((pRoot1 == NULL && pRoot2 != NULL) || (pRoot1 != NUll && pRoot2 == NULL)) 
        //    return 0;
        else{
            //while(pRoot1 != NULL && pRoot2 != NULL){
                if(pRoot1->val == pRoot2->val){
                    return(IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right));
                }
                else 
                    return false;
            //}
        }
    }
};

int main(){
	TreeNode N1(1), N2(2), N3(3), N0(0);
	N1.left = &N2;
	N1.right = &N3;
	
	Solution s;
	cout << s.HasSubtree(&N1, &N1) << endl;
	
	
}