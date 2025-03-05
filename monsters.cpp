#include <bits/stdc++.h>
using namespace std;

bool solve(int cur_monster, vector<int> &danger, vector<vector<int>> &adj_list, vector<bool> &starts);

int main()
{

    long long t;
    cin >> t;

    vector<string> outputs;
    while (t--)
    {

        long long vertices, edges;

        cin >> vertices >> edges;

        vector<int> danger(vertices);

        queue<int> start;
        vector<bool> start_point(vertices, false);

        for (int i = 0; i < vertices; i++)
        {
            int d;
            cin >> d;
            danger[i] = d;

            // cout << "monster " << i << " with danger " << d << endl;

            if (d == 0)
            {
                start.push(i);
                start_point[i] = true;
            }
        }

        bool fully_connected = false;

        vector<vector<int>> adj_list(vertices);

        for (int i = 0; i < edges; i++)
        {
            int e1, e2;

            cin >> e1 >> e2;

            adj_list[e1 - 1].push_back(e2 - 1);
            adj_list[e2 - 1].push_back(e1 - 1);
        }

        while (start.size())
        {
            int cur_monster = start.front();
            start.pop();

            if (start_point[cur_monster] == false)
                continue;
            fully_connected = solve(cur_monster, danger, adj_list, start_point);
            if (fully_connected)
                break;
        }

        if (fully_connected)
            outputs.push_back("YES\n");
        else
            outputs.push_back("NO\n");
    }

    for (auto &s : outputs)
        cout << s;
}

bool solve(int start_mon, vector<int> &danger, vector<vector<int>> &adj_list, vector<bool> &starts)
{
    long long slain_monsters = 0;

    // cout << "start monster: " << start_mon << endl;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<bool> visited(danger.size(), false);
    visited[start_mon] = true;
    pq.push({0, start_mon});

    while (pq.size())
    {
        int dg = pq.top()[0];
        int mon = pq.top()[1];
        pq.pop();

        // cout << "cur monster: " << mon << endl;
        // cout << "slain monsters: " << slain_monsters << endl;
        // cout << "danger of monster: " << dg << endl;

        if (dg > slain_monsters)
            return false;

        // cout << "current monster: " << mon << endl;
        slain_monsters += 1;

        if (dg == 0)
            starts[mon] = false;
        // cout << "slain monsters: " << slain_monsters << endl;

        for (auto &edge : adj_list[mon])
        {
            // cout << "cur edge: " << edge << endl;
            if (!visited[edge])
            {
                // cout << "monster " << edge << " met the condition\n";
                vector<int> new_entry = {danger[edge], edge};
                pq.push(new_entry);
                visited[edge] = true;
            }
        }
    }

    return slain_monsters == visited.size();
}