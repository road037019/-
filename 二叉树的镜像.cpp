// ���������Ķ�����������任ΪԴ�������ľ��� 
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
        //    return; //�����ڵݹ���õ�ʱ����Ҫ��ʱ��return����
        //if(pRoot->left != NULL && pRoot->right != NULL){  //���ַ�ʽ�Ǵ���ģ���������:{8,6,10,5,7,9,11}
                                                            //��Ӧ���Ӧ��Ϊ:{8,10,6,11,9,7,5}
                                                            //������Ϊ:{8,10,6,7,5,11,9}
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
        
        //Ҫ�������ڵ㽻���������ǽ������ڵ����ֵ������
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