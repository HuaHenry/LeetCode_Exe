class Solution {
public:
    set<char> charSet;

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
        int l = 0;
        int ans=0;
        for(int r=0;r<n;r++){
            while(charSet.find(s[r])!=charSet.end()){
                //有重复元素
                charSet.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            charSet.insert(s[r]);
        }
        return ans;
    }
};