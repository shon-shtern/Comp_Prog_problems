#include <bits/stdc++.h>
using namespace std;

int main()
{

    int s;
    int t;
    cin >> t;

    int coins[4] = {10, 6, 3, 1};

    vector<int> inputs;
    while (t--)
    {
        cin >> s;
        inputs.push_back(s);
    }

    for (int input : inputs)
    {
        int total = input / 15;

        int remainder = input % 15;

        if (remainder == 5 && total > 0)
        {
            total += 1;
            remainder = 0;
        }
        else if ((remainder == 8 && total > 0) || remainder == 12)
        {
            total += 2;
            remainder = 0;
        }
        else
        {
            for (int coin : coins)
            {
                total += remainder / coin;
                if (remainder != 1)
                    remainder %= coin;
            }
        }

        cout << total << endl;
    }

    return 0;
}