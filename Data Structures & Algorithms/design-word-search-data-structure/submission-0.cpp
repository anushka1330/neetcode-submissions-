class WordDictionary {
public:
    vector<string> words;

    WordDictionary() {
    }

    void addWord(string word) {
        words.push_back(word);
    }

    bool search(string word) {
        for (string s : words) {
            if (s.size() != word.size()) continue;

            bool ok = true;
            for (int i = 0; i < s.size(); i++) {
                if (word[i] != '.' && word[i] != s[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};