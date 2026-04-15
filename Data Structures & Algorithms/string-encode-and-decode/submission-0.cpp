class Solution {
public:

    string encode(vector<string>& strs) {
         string res = "";

    for (string s : strs) {
        res += to_string(s.size()) + "#" + s;
    }

    return res;

    }

    vector<string> decode(string s) {
         vector<string> res;
    int i = 0;

    while (i < s.size()) {

        int j = i;

        // find '#'
        while (s[j] != '#') {
            j++;
        }

        // get length
        int len = stoi(s.substr(i, j - i));

        // get word
        string word = s.substr(j + 1, len);

        res.push_back(word);

        // move forward
        i = j + 1 + len;
    }

    return res;

    }
};
