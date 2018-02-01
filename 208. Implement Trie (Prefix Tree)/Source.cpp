#include <iostream>
#include <unordered_map>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
    char current;
    TrieNode(char current) : current(current) {}
};
class Trie {
  private:
    TrieNode *root;

  public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(0);
        root->isWord = true;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *t = root, *plus;
        for (char c : word) {
            if (t->children.find(c) == t->children.end()) {
                plus = new TrieNode(c);
                t->children[c] = plus;
                t = plus;
            } else {
                t = t->children[c];
            }
        }
        t->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *t = root;
        for (char c : word) {
            if (t->children.find(c) == t->children.end()) {
                return false;
            } else {
                t = t->children[c];
            }
        }
        return t->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for (char c : prefix) {
            if (t->children.find(c) == t->children.end()) {
                return false;
            } else {
                t = t->children[c];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
