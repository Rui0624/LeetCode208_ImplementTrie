//
//  main.cpp
//  LeetCode208_ImplementTrie
//
//  Created by Rui on 1/25/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false){
        for(auto &a: child){
            a = NULL;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(auto &a: word){
            int i = a - 'a';
            if(!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(auto &a: word)
        {
            int i = a - 'a';
            if(!p->child[i])
                return false;
            p = p->child[i];
        }
        
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        
        for(auto &a : prefix)
        {
            int i = a - 'a';
            if(!p->child[i])
                return false;
            p = p->child[i];
        }
        return true;
    }
    
private:
    TrieNode* root;
};
