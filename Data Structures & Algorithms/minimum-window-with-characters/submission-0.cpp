class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int start=0;
        int cnt=0;
        vector<int> hash(128,0);
        for(char ch:t){
            hash[ch]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
    }
};
