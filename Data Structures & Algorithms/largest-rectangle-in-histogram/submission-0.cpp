class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int height=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,height*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int height=heights[st.top()];
            st.pop();
            int nse=heights.size();
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,height*(nse-pse-1));
        }
        return maxarea;
    }
};
