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
	//递归的思想：对于每一个节点，如果其是一个叶节点，并且其是一条正确的路径，则将其添加到path中，如果其不是一条正确的路径，则将该条路径往上返回一步，即path_temp.pop_back(); 
	//如果其不是一个叶节点，则往下查找其左右孩子里是否有正确路径，并将其insert到当前path中（有的话就insert正确的路径，没有的话就insert空） 
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