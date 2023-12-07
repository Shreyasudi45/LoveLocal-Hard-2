#include <bits/stdc++.h>
using namespace std;
string shortestPalindrome(const string& s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string new_s = s + "#" + rev_s;
    int n = new_s.length();
    vector<int> kmpTable(n, 0);
    for (int i = 1, j = 0; i < n; ) {
        if (new_s[i] == new_s[j]) {
            kmpTable[i++] = ++j;
        } else {
            if (j > 0) {
                j = kmpTable[j - 1];
            } else {
                kmpTable[i++] = 0;
            }
        }
    }
    int lenToAdd = s.length() - kmpTable[n - 1];
    return rev_s.substr(0, lenToAdd) + s;
}

int main() {
    string s;
    cout << "s = ";
    cin >> s;
    string result = shortestPalindrome(s);
    cout << result << endl;
}