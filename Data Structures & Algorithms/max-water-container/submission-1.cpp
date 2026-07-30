class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int maxarea=INT_MIN;
        int area;
        while(i<j){
            if(heights[i]>heights[j]){
               area=heights[j]*(j-i);
               j--;
            }
            else{
                area=heights[i]*(j-i);
                i++;
            }
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};
