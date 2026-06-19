class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U' ){
                st.push(s[i]);
                s[i] = '*';
            }
        }

       for(int j = 0; j<s.size(); j++){
            if(s[j] == '*'){
                s[j] = st.top();
                st.pop();
            }
        }

        return s;
    }
};