class Solution {
public:
    int characterReplacement(string s, int k) {
    vector<int> f(26, 0);
    int l = 0, maxF = 0, ans = 0;

    for (int r = 0; r < s.size(); r++) {
        maxF = max(maxF, ++f[s[r] - 'A']);

        while ((r - l + 1) - maxF > k)
            f[s[l++] - 'A']--;

        ans = max(ans, r - l + 1);
    }

    return ans;
}
};
