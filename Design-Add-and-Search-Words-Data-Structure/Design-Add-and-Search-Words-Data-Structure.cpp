struct node {
    node* children[26];
    bool word = false;
    node() {
        for (int i = 0; i &lt; 26; i++) children[i] = nullptr;
    }
};
class WordDictionary {
public:
    node* root = new node();
    WordDictionary() {}
    void addWord(string word) {
        node* cur = root;
        for (auto &amp;c : word) {
            if (cur-&gt;children[c - 'a'] == nullptr) {
                cur-&gt;children[c - 'a'] = new node();
            }
            cur = cur-&gt;children[c - 'a'];
        }
        cur-&gt;word = true;
    }
    bool dfs(string&amp; word, int index, node* n) {
        if (index == word.length()) {
            return n-&gt;word;
        }
        node* cur = n;
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i &lt; 26; i++) {
                if (cur-&gt;children[i] == nullptr) continue;
                if (dfs(word, index + 1, cur-&gt;children[i])) return true;
            }
            return false;
        } else {
            if (cur-&gt;children[c - 'a'] == nullptr) return false;
            cur = cur-&gt;children[c - 'a'];
            return dfs(word, index + 1, cur);
        }
    }
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
/**
