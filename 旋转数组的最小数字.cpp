class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int min = rotateArray[0];
        for(int i =0; i < rotateArray.size(); i++){
            if(rotateArray[i] < min)
                min = ratateArray[i];
        }
        return min;
    }
};