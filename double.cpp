#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int bin_search(vector<string> &arr, string &s)
{
    int low = 0;
    int high = arr.size();
    if (high == 0)
    {
        return -1;
    }
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < s)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low < arr.size() && arr[low] == s)
    {
        return low;
    }
    else
    {
        return -1;
    }
}

// int bin_search1(vector<string> &arr, string &s) {
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] == s) {
//             return i;
//         }
//     }
//     return -1;
// }

int solve(vector<string> arr[8], vector<string> ordered)
{
    string ret = "";
    for (unsigned int i = 0; i < ordered.size(); i++)
    {
        string s = ordered[i];
        if (s.length() == 1)
        {
            ret += "0";
            continue;
        }
        for (unsigned int j = 1; j <= s.length() / 2; j++)
        {
            bool lowsmall = false;
            bool highsmall = false;
            bool lowbig = false;
            bool highbig = false;
            string low_part = s.substr(0, j);
            string high_part = s.substr(s.length() - j, j);
            int found = bin_search(arr[j], low_part);
            if (found != -1)
            {
                lowsmall = true;
            }
            found = bin_search(arr[j], high_part);
            if (found != -1)
            {
                highsmall = true;
            }

            if (j == s.length() / 2 && s.length() % 2 == 0)
            {
                if (lowsmall && highsmall)
                {
                    ret += "1";
                }
                else
                {
                    ret += "0";
                }
                break;
            }
            low_part = s.substr(0, s.length() - j);
            high_part = s.substr(j, s.length() - j);
            found = bin_search(arr[s.length() - j], low_part);
            if (found != -1)
            {
                lowbig = true;
            }
            found = bin_search(arr[s.length() - j], high_part);
            if (found != -1)
            {
                highbig = true;
            }
            if ((lowsmall && highbig) || (lowbig && highsmall))
            {
                ret += "1";
                break;
            }
            else if (j == s.length() / 2)
            {
                ret += "0";
            }
        }
    }
    cout << ret << endl;
    return 0;
}
int main()
{
    int n_over;
    cin >> n_over;
    for (int i = 0; i < n_over; i++)
    {
        vector<string> arr[9];
        vector<string> ordered;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            arr[s.length()].push_back(s);
            ordered.push_back(s);
        }
        for (int i = 0; i < 8; i++)
        {
            sort(arr[i].begin(), arr[i].end());
        }
        solve(arr, ordered);
        for (int i = 0; i < 8; i++)
        {
            arr[i].clear();
        }
        ordered.clear();
    }
}