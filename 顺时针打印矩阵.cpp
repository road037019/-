#include <iostream>
#include <vector>
using namespace std;
	
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> temp;
        if(matrix.empty())
            return temp; 
        for(int i = 0; i < matrix[0].size(); i++){
            temp.push_back(matrix[0][i]);
        }
        vector<vector<int> > residue;
        for(int i = 1; i < matrix.size(); i ++){
            vector<int> residue_temp;
            for(int j = 0; j < matrix[i].size(); j ++){
                residue_temp.push_back(matrix[i][j]);
            }
            residue.push_back(residue_temp);
        }
        //vector<vector<int>> m = rotate(residue);
        vector<int> t = printMatrix(rotate(residue)); //递归求rotate(residue) 的顺时针矩阵
        temp.insert(temp.end(), t.begin(), t.end()); //将两个vector拼接到一块
        return temp;
    }
    
    //将矩阵逆时针旋转90度；
     vector<vector<int> > rotate(vector<vector<int> > &matrix){ 
        vector<vector<int> > rotator;
        if(matrix.empty())
        	return rotator;
        for(int i = 0; i < matrix[0].size(); i ++){
            vector<int> rotator_temp;
            for(int j = 0; j < matrix.size(); j ++){
                rotator_temp.push_back(matrix[j][matrix[0].size() - i -1]);
            }
            rotator.push_back(rotator_temp);
        }
        return rotator;
    }
};

int main(){
	vector<int> v1={1, 2};
	vector<int> v2={3, 4};
	vector<vector<int>> v={v1, v2};
	
	Solution s;
	vector<int> temp = s.printMatrix(v);
	for(int i =0; i < temp.size(); i++)
			cout << temp[i] << ' ';
}