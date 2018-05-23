#include <iostream>
#include <vector>
using namespace std; 


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
           return 0;
        if(sequence.size() == 1) //这是很重要的一步，否则的话用例都无法通过！ 
			return 1; 
        int i = 0;
        for(i = 0; i < sequence.size() - 1; i++){
            if(sequence[i] > sequence[sequence.size()-1])
                break;
        }
        vector<int> subl,subr;
        if(i > 0 && i < sequence.size()-1){
            for(int j = 0; j < i; j++){
                subl.push_back(sequence[j]);
            }
            for(int j = i; j < sequence.size()-1; j++){
                subr.push_back(sequence[j]);
                if(sequence[j] < sequence[sequence.size()-1]){	
                    return 0;
                }
            }
            return (VerifySquenceOfBST(subl) && VerifySquenceOfBST(subr));
        }
        else if( i == 0){
            for(int j = i; j < sequence.size()-1; j++){
                subr.push_back(sequence[j]);
                if(sequence[j] < sequence[sequence.size()-1]){	
                    return 0;
                }
            }
            return (VerifySquenceOfBST(subr));
        }
        else{
            for(int j = 0; j < i; j++){
                subl.push_back(sequence[j]);
            }
            return (VerifySquenceOfBST(subl));
        }
    }
};


int main(){
	vector<int> v = {5,4};
	Solution s;
	int i = s.VerifySquenceOfBST(v);
	cout << i;
	
}