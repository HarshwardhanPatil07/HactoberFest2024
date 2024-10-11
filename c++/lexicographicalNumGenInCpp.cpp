#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, int n, vector<int>& result) {
    if (current > n) return;
    result.push_back(current);
    for (int i = 0; i <= 9; ++i) {
        int next = current * 10 + i;
        if (next > n) return;
        dfs(next, n, result);
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i <= 9; ++i) dfs(i, n, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    
    if (n <= 0) return 0;

    vector<int> result = lexicalOrder(n);
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}
