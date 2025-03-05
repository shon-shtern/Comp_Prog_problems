#include <bits/stdc++.h>
using namespace std;

/* Thank you so much to the professor and Ken for helping me debug this
 * algorithm! I'm really happy with how it turned out, and I learned so much
 * from their help.
 */

// Source: https://www.geeksforgeeks.org/unordered-set-of-vectors-in-c-with-examples/
struct hashFunction
{
    size_t operator()(const vector<int>
                          &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

/*
 * The union find data structure used to connect everything
 * Source: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
 */
class UnionFind
{
    vector<int> parent;

public:
    UnionFind(int size)
    {
        parent.resize(size);

        // Initialize the parent array with each
        // element as its own representative
        for (int i = 1; i <= size; i++)
        {
            parent[i - 1] = i;
        }
    }

    // Find the representative (root) of the
    // set that includes element i
    int find(int i)
    {

        // If i itself is root or representative
        if (parent[i - 1] == i)
        {
            return i;
        }

        // Else recursively find the representative
        // of the parent
        return find(parent[i - 1]);
    }

    // Unite (merge) the set that includes element
    // i and the set that includes element j
    void unite(int i, int j)
    {

        // Representative of set containing i
        int irep = find(i);

        // Representative of set containing j
        int jrep = find(j);

        // Make the representative of i's set
        // be the representative of j's set
        parent[irep - 1] = jrep;
    }
};

int main()
{

    int num_cities, num_roads, x;
    long long asphalt;

    cin >> num_cities >> num_roads >> x;

    multiset<vector<long long>, greater<vector<long long>>> cities;
    UnionFind combined_cities(num_cities);
    long long asphalt_amounts[num_cities + 1];
    vector<int> r_add;

    // Keep track of the asphalts for each city, which we use in the priority queue
    for (int i = 1; i <= num_cities; i++)
    {
        cin >> asphalt;
        cities.insert({asphalt, i});
        asphalt_amounts[i] = asphalt;
    }

    vector<vector<vector<int>>> adj_set(num_cities + 1);

    for (int i = 0; i < num_roads; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        adj_set[c1].push_back({c2, i + 1});
        adj_set[c2].push_back({c1, i + 1});
    }

    while (cities.size() != 1)
    {
        vector<long long> ciphalt = *cities.begin();
        cities.erase(cities.begin());

        int city = ciphalt[1];
        long long asphalt = ciphalt[0];
        long long summed_asphalt;
        long long new_asphalt;
        vector<int> new_connection = {};

        // Search for a new road to connect two cities
        // Note that a while loop is used because an edge is removed one by one
        while (!adj_set[city].empty())
        {
            vector<int> edge = adj_set[city].back();
            adj_set[city].pop_back();
            int other_city = combined_cities.find(edge[0]);
            new_asphalt = asphalt_amounts[other_city];
            summed_asphalt = new_asphalt + asphalt - x;

            // Same root, so redundant check
            if (city == other_city)
                continue;

            // Claim: if condition doesn't hold for any edge, it is automatically false
            if (summed_asphalt >= 0)
            {
                new_connection = edge;
                r_add.push_back(edge[1]);
                asphalt_amounts[other_city] = summed_asphalt;
                asphalt_amounts[city] = summed_asphalt;
                cities.erase({new_asphalt, other_city});
            }

            break;
        }

        // Didn't find a match
        if (!new_connection.size())
        {
            cout << "NO" << endl;
            return 0;
        }

        // Merge the two adjacency sets
        int a = city;
        int b = combined_cities.find(new_connection[0]);

        if (adj_set[a].size() > adj_set[b].size())
        {
            int temp = a;
            a = b;
            b = temp;
        }

        // Merge the lists. Use the short-big method to make it
        // an O(logn) time merge
        for (vector<int> edge : adj_set[a])
        {
            adj_set[b].push_back(edge);
        }

        combined_cities.unite(a, b);

        cities.insert({summed_asphalt, b});
    }

    cout << "YES" << endl;

    for (int r : r_add)
        cout << r << endl;

    return 0;
}