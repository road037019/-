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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> path;
        vector<int> path_temp;
        int currentNumber = 0;
        if(root == NULL)
            return path;
        return FindPath(root, expectNumber, path_temp, currentNumber);
        
    }
	//�ݹ��˼�룺����ÿһ���ڵ㣬�������һ��Ҷ�ڵ㣬��������һ����ȷ��·����������ӵ�path�У�����䲻��һ����ȷ��·�����򽫸���·�����Ϸ���һ������path_temp.pop_back(); 
	//����䲻��һ��Ҷ�ڵ㣬�����²��������Һ������Ƿ�����ȷ·����������insert����ǰpath�У��еĻ���insert��ȷ��·����û�еĻ���insert�գ� 
    vector<vector<int>> FindPath(TreeNode * root, int expectNumber, vector<int> &path_temp, int currentNumber){
        vector<vector<int>> path;
        
        path_temp.push_back(root->val);
        currentNumber = currentNumber + root->val;
        
        bool isLeaf = root->left == NULL && root->right == NULL;
        if(currentNumber == expectNumber && isLeaf){
            path.push_back(path_temp);
        }
        if(root->left != NULL){
            vector<vector<int>> temp = FindPath(root->left, expectNumber, path_temp, currentNumber);
            path.insert(path.end(), temp.begin(), temp.end());
        }
        if(root->right != NULL){
            vector<vector<int>> temp = FindPath(root->right, expectNumber, path_temp, currentNumber);
            path.insert(path.end(), temp.begin(), temp.end());
        }
        path_temp.pop_back();
        return path;
    }
};