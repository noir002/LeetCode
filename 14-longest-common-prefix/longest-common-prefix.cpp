class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort(strs.begin(),strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        string ans="";
        int i=0;
        while( i<s1.length() && i<s2.length())
        {
            if(s1[i]!=s2[i])
            {
                break;
            }
            ans+=s1[i++];
        }
        return ans;
    }
};