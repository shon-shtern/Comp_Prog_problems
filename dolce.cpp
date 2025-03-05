#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    while (n--)
    {

        int t, x;

        cin >> t >> x;

        long long cost = 0;
        vector<int> stores;

        // cout << "num stores: " << t << endl;
        // cout << "budget x: " << x << endl;

        for (int i = 0; i < t; i++)
        {
            int store;
            cin >> store;
            stores.push_back(store);
        }

        sort(stores.begin(), stores.end(), greater<int>());
        long long packs = 0;
        int stores_passed = 0;
        // cout << "store size: " << stores.size() << endl;
        while (stores.size())
        {

            // cout << "index: " << i + 1 << endl;
            cost += stores[stores.size() - 1];

            // cout << "cost: " << cost << endl;

            if (x - cost < 0)
                break;
            packs += ((x - cost) / (stores_passed + 1) + 1);

            stores_passed += 1;
            stores.pop_back();
        }

        cout << packs << endl;
    }
}