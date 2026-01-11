class Solution {
public:
int largestHist(vector<int>& arr){
    int maxArea = 0;
    int element = -1;
    stack<int> st;
    int nse = -1;
    int pse = -1;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()]> arr[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1: st.top();
            maxArea = max(maxArea, (arr[element] * (nse - pse - 1)));
            
        }
        st.push(i);
    }
    while(!st.empty()){
        element = st.top();
        st.pop();
        nse = n;
        pse = st.empty() ? -1: st.top();
        maxArea = max(maxArea, (arr[element] * (nse - pse - 1)));
    }
    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        if(matrix.empty() || matrix[0].empty()) return 0;
        for(int j =  0; j<m; j++){
            int sum = 0;
            for(int i = 0; i<n; i++){
                if(matrix[i][j] == '1') sum++;
                else sum = 0;
                prefixSum[i][j] = sum;
            }
            
        }
        for(int i = 0; i<n; i++){
            maxArea = max(maxArea, largestHist(prefixSum[i]));
        }
        return maxArea;
    }
};