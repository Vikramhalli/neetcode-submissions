class Solution {
public:
    int findmaxele(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    int calhrs(vector<int>& piles, int k){
        int totalhrs=0;
        for(int i=0;i<piles.size();i++){
            totalhrs+=ceil((double)piles[i]/k);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmaxele(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalhrs=calhrs(piles,mid);
            if(totalhrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
