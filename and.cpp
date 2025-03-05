#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>

using namespace std;

int main()
{
    int main_outer;
    cin >> main_outer;
    for (int i = 0; i < main_outer; i++)
    {

        long long int n, d;
        cin >> n >> d;
        vector<bool> arr1;
        for (int i = 0; i < n; i++)
        {
            bool s;
            cin >> s;
            arr1.push_back(s);
        }
        int groups = gcd(n, d);
        int group_size = n / groups;
        // cout << groups << " " << group_size << endl;
        int max_ones = 0;
        for (long long int i = 0; i < groups; i++)
        {
            int begin_ones = 0;
            bool begin = true;
            int cont_ones = 0;
            for (long long int j = 0; j < group_size; j++)
            {
                if (arr1[(i + j * d) % n] == 1)
                {
                    cont_ones++;
                    if (begin)
                    {
                        begin_ones++;
                    }
                }
                else
                {
                    if (cont_ones > max_ones)
                    {
                        max_ones = cont_ones;
                    }
                    begin = false;
                    cont_ones = 0;
                }
            }
            if (begin)
            {
                begin_ones = 0;
            }
            if (cont_ones + begin_ones > max_ones)
            {
                max_ones = cont_ones + begin_ones;
            }
        }

        if (max_ones == group_size)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << (max_ones) << endl;
        }
    }
}