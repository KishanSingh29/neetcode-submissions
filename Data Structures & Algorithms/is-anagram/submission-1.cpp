class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(char p : t){
            mp[p]--;
            if(mp[p]<0){
                return false;
            }
        }
        return true;

    }
};
