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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode = NULL;
        Convert(pRootOfTree, &pLastNode);
        //TreeNode* pFirstNode = pRootOfTree;
        while(pRootOfTree!=NULL && pRootOfTree->left!=NULL){
        	pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }

    //这儿递归目的是：将当前节点接入到  （二叉搜索树中）当前节点左侧  已经转换好的双向链表中；
    void Convert(TreeNode * pRootOfTree, TreeNode ** pLastNode){  //这儿需要用二级指针，因为需要接收下级的函数传递过来节点地址值，而如果用
                                                                  //一级指针的话，下级计算出来的节点的地址值是无法传递过来的。
        if(pRootOfTree == NULL)
            return;

        if(pRootOfTree->left){
            Convert(pRootOfTree->left, pLastNode);
        }
        pRootOfTree->left = *pLastNode;

        if(*pLastNode != NULL)
        	(*pLastNode)->right = pRootOfTree;

       	*pLastNode = pRootOfTree;

        if(pRootOfTree->right){
        	Convert(pRootOfTree->right, pLastNode);
        }
    }
};

int main(){
	
	return 0;
}