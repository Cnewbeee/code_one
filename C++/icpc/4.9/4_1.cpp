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

    // ���뵥�ʵ�Trie����
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

    // �ݹ鸨�����������ڼ���ڵ���
    int countNodes(TrieNode* node) const {
        if (!node) return 0;

        int count = 1;  // ��ǰ�ڵ����
        for (TrieNode* child : node->children) {
            count += countNodes(child);
        }
        return count;
    }

    // ����Trie���Ľڵ���
    int countNodes() const {
        return countNodes(root) - 1; // ��ȥ���ڵ�
    }
};
#include <iostream>
#include <string>
using namespace std;

// TrieNode �� Trie �ඨ��

int main() {
    Trie trie;
    trie.insert("APPLE");
    trie.insert("APP");
    trie.insert("APRICOT");
    trie.insert("CAT");

    cout << "�ܽڵ���: " << trie.countNodes() << endl;
    return 0;
}
