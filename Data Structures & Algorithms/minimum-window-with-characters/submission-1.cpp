class Solution {
public:
    string minWindow(string s, string t) {
         vector<int> need(128, 0);

        // count t chars
        for (char c : t) need[c]++;

        int left = 0, count = t.size();
        int start = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (need[s[right]] > 0) count--;
            need[s[right]]--;

            // valid window
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0) count++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
