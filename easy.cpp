#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    string s;

    cin >> n >> s;

    long long min_cost;

    vector<vector<int>> dp(5, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    vector<int> ambiguity;

    string hard = "hard";

    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        ambiguity.push_back(cost);
    }

    for (int i = 1; i <= 4; i++)
    {

        char cur_letter = hard[i - 1];

        for (int j = 1; j <= n; j++)
        {

            cout << dp[i - 1][j - 1] << endl;
            if (cur_letter != s[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + ambiguity[j - 1]);
            }
        }
    }

    cout << dp[4][n] << endl;
}