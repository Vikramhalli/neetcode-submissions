class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<int> hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]!=0) {
                return false;
            }    
        }
        return true;
    }
};
