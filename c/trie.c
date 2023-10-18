#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
  struct TrieNode *children[26];
  int isLeaf;
} TrieNode;

typedef struct Trie {
  TrieNode *root;
} Trie;

Trie *TrieCreate() {
  Trie *trie = malloc(sizeof(Trie));
  trie->root = malloc(sizeof(TrieNode));
  trie->root->isLeaf = 0;
  for (int i = 0; i < 26; i++) {
    trie->root->children[i] = NULL;
  }
  return trie;
}

void TrieInsert(Trie *trie, char *word) {
  TrieNode *node = trie->root;
  for (int i = 0; i < strlen(word); i++) {
    int idx = word[i] - 'a';
    if (node->children[idx] == NULL) {
      node->children[idx] = malloc(sizeof(TrieNode));
      node->children[idx]->isLeaf = 0;
      for (int j = 0; j < 26; j++) {
        node->children[idx]->children[j] = NULL;
      }
    }
    node = node->children[idx];
  }
  node->isLeaf = 1;
}

int TrieSearch(Trie *trie, char *word) {
  TrieNode *node = trie->root;
  for (int i = 0; i < strlen(word); i++) {
    int idx = word[i] - 'a';
    if (node->children[idx] == NULL) {
      return 0;
    }
    node = node->children[idx];
  }
  return node->isLeaf;
}

int TrieStartsWith(Trie *trie, char *word) {
  TrieNode *node = trie->root;
  for (int i = 0; i < strlen(word); i++) {
    int idx = word[i] - 'a';
    if (node->children[idx] == NULL) {
      return 0;
    }
    node = node->children[idx];
  }
  return 1;
}

int main() {
  Trie *trie = TrieCreate();

  TrieInsert(trie, "app");
  TrieInsert(trie, "apple");
  TrieInsert(trie, "applet");
  TrieInsert(trie, "apply");
  TrieInsert(trie, "applying");

  printf("app: %d\n", TrieSearch(trie, "app"));
  printf("apple: %d\n", TrieStartsWith(trie, "apple"));

  return 0;
}
