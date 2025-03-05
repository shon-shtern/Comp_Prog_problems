#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int marks = 0;

        for (int i = 0; i < s.length(); i++) {

            if ((s[i] == ')' && i == 0) || (s[i] == '(' && i == s.length() - 1)) {
                marks = 1;
                break;
            }

            if (s[i] == '?')
                marks++;
        }

        if (marks % 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}