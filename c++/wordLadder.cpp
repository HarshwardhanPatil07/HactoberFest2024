#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
 
    if (!dict.count(endWord)) return 0;

    queue<pair<string, int>> q;
    q.push(make_pair(beginWord, 1));
     
    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        for (int i = 0; i < word.length(); i++) {
            string newWord = word;

            for (char c = 'a'; c <= 'z'; c++) {
                newWord[i] = c;

                if (newWord == endWord) {
                    return level + 1;
                }

                if (dict.count(newWord) && !visited.count(newWord)) {
                    visited.insert(newWord);
                    q.push(make_pair(newWord, level + 1));
                }
            }
        }
    }

    return 0;
}
