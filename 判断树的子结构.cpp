//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

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
                //if(pRoot1->val == pRoot2->val) //��������ôд�жϵĻ����ᵼ������ֲ��Ĳ����㣬����һ���ڵ����㣬��һ���ڵ㲻���㣬��ʧ����
                //    return(IsSubtree(pRoot1, pRoot2));
                //else 
                    return(IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
            //}
        }
    }
    
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) //pRoot2Ϊ�գ�Ϊ�����У������棻
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