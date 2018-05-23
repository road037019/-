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

    //����ݹ�Ŀ���ǣ�����ǰ�ڵ���뵽  �������������У���ǰ�ڵ����  �Ѿ�ת���õ�˫�������У�
    void Convert(TreeNode * pRootOfTree, TreeNode ** pLastNode){  //�����Ҫ�ö���ָ�룬��Ϊ��Ҫ�����¼��ĺ������ݹ����ڵ��ֵַ���������
                                                                  //һ��ָ��Ļ����¼���������Ľڵ�ĵ�ֵַ���޷����ݹ����ġ�
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