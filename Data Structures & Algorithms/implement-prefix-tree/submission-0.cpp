class PrefixTree {
public:
    unordered_set<string> words;

    PrefixTree() {
    }

    void insert(string word) {
        words.insert(word);
    }

    bool search(string word) {
        return words.count(word);
    }

    bool startsWith(string prefix) {
        for (string s : words) {
            if (s.substr(0, prefix.size()) == prefix)
                return true;
        }
        return false;
    }
};