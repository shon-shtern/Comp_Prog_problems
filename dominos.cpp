#include <bits/stdc++.h>
using namespace std;

int main()
{

    int inputs;

    cin >> inputs;

    while (inputs--)
    {

        int dominos;
        unordered_set<int> set1;
        unordered_set<int> set2;
        bool duplicate = false;

        cin >> dominos;

        while (dominos--)
        {
            int side1, side2;

            cin >> side1 >> side2;

            if (duplicate)
                continue;

            if (side1 == side2)
            {
                duplicate = true;
                continue;
            }

            if (set1.find(side1) == set1.end() && set1.find(side2) == set1.end())
            {
                set1.insert(side1);
                set1.insert(side2);
            }
            else if (set2.find(side1) == set2.end() && set2.find(side2) == set2.end())
            {
                set2.insert(side1);
                set2.insert(side2);
            }
            else
            {
                duplicate = true;
            }
        }

        if (duplicate)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}