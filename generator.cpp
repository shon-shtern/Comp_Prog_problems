#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("test.txt");

    int n = 299999;
    int m = 299998;
    long long x = 1;

    fout << n << " " << m << " " << x << "\n";

    for (int i = 0; i < n; i++)
    {
        fout << 1 << (i + 1 < n ? ' ' : '\n');
    }

    for (int i = 1; i < n; i++)
    {
        fout << i << " " << i + 1 << "\n";
    }

    fout.close();
    return 0;
}
