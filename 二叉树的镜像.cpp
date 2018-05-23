// 操作给定的二叉树，将其变换为源二叉树的镜像。 
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        //if(pRoot == NULL)
        //    return; //当存在递归调用的时候，需要及时的return？吗
        //if(pRoot->left != NULL && pRoot->right != NULL){  //这种方式是错误的，测试用例:{8,6,10,5,7,9,11}
                                                            //对应输出应该为:{8,10,6,11,9,7,5}
                                                            //你的输出为:{8,10,6,7,5,11,9}
        //    int temp;
        //    temp = pRoot->left->val;
        //    pRoot->left->val = pRoot->right->val;
        //    pRoot->right->val = temp;
        //    Mirror(pRoot->left);
        //    Mirror(pRoot->right);
        //}
        //if(pRoot->left != NULL && pRoot->right == NULL){
        //    pRoot->right = pRoot->left;
        //    pRoot->left = NULL;
        //    Mirror(pRoot->right);
        //}
        //if(pRoot->left == NULL && pRoot->right != NULL){
        //    pRoot->left = pRoot->right;
        //    pRoot->right = NULL;
        //    Mirror(pRoot->left);
        //}
        
        //要将两个节点交换，而不是将两个节点的数值交换；
        if(pRoot == NULL)
            return;
        else{
            TreeNode *temp;
            temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};