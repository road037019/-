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
        if(pre.empty() && vin.empty())  //�ݹ���ĵ�һ�������vector�Ĵ�СΪ�գ���ʱֻ��Ҫֱ�ӷ��ؿռ��ɣ�
            return NULL;
        else if(pre.size() == 1){  //�ݹ���ĵڶ��������vector�Ĵ�СΪ1����ʱ��Ҫ����һ����ֵΪvector�е���ֵ�����ڵ㣬Ȼ�󷵻ؼ���
        	TreeNode *root = new TreeNode(pre[0]);
        	return root;
        }else{
        	
            TreeNode *root = new TreeNode(pre[0]);
            //cout << root->val<<endl; 
            
            vector<int>::iterator r = find(vin.begin(), vin.end(), pre[0]); //�����������ķָ�㣻 
            auto distance = r - vin.begin(); //��Ϊr��vin�ĵ���������pre�в����ã����������ת��һ�£���ɿ�����pre��ʹ�õľ��룻 
            
            //�������������ǰ�������������� 
            vector<int> vin_left(vin.begin(), r);    //����������е������� 
            vector<int> vin_right(r+1, vin.end());    //����������е������� 
            vector<int> pre_left(pre.begin()+1, pre.begin() + distance + 1 ); //ǰ��������е������� 
            vector<int> pre_right(pre.begin() + distance + 1, pre.end());   //ǰ��������е������� 
            
            //�����������ϳ�һ������������ 
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
