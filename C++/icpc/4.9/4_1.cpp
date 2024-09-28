class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (auto &child : children) {
            child = nullptr;
        }
    }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // 插入单词到Trie树中
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // 递归辅助函数，用于计算节点数
    int countNodes(TrieNode* node) const {
        if (!node) return 0;

        int count = 1;  // 当前节点计数
        for (TrieNode* child : node->children) {
            count += countNodes(child);
        }
        return count;
    }

    // 返回Trie树的节点数
    int countNodes() const {
        return countNodes(root) - 1; // 减去根节点
    }
};
#include <iostream>
#include <string>
using namespace std;

// TrieNode 和 Trie 类定义

int main() {
    Trie trie;
    trie.insert("APPLE");
    trie.insert("APP");
    trie.insert("APRICOT");
    trie.insert("CAT");

    cout << "总节点数: " << trie.countNodes() << endl;
    return 0;
}
