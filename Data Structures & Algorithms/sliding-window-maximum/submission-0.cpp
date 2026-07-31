class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l=0;
        int r=k-1;
        int maxi=INT_MIN;
        while(r<nums.size()){
            for(int i=l;i<=r;i++){
                maxi=max(maxi,nums[i]);
            }
            ans.push_back(maxi);
            maxi=INT_MIN;
            r++;
            l++;
        }
        return ans;
    }
};
