// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        if (pairs.empty())
        return {};

        vector<vector<Pair>> ans;
        ans.push_back(pairs);

        int n = pairs.size();

        for (int i = 1; i < n; i++) {

            Pair key = pairs[i];
            int j = i - 1;

            while (j >= 0 && pairs[j].key > key.key) {
                pairs[j + 1] = pairs[j];
                j--;
            }

            pairs[j + 1] = key;

            ans.push_back(pairs);
        }

        return ans;
    }
};