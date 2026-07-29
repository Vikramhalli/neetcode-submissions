class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int num=numbers[i]+numbers[j];
            if(num==target){
                return {i+1,j+1};
            }
            else if(num<target) i++;
            else j--;
        }
        return {};
    }
};
