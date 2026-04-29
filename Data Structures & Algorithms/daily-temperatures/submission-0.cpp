class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st; // store indices

        for(int i = 0; i < n; i++) {
            while(!st.empty() && t[i] > t[st.top()]) {
                int idx = st.top(); st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};