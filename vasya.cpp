#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> displacement;

    int n;

    cin >> n;
    string dir;
    cin >> dir;
    int x_goal, y_goal;
    cin >> x_goal >> y_goal;

    pair<int, int> dirs = {0, 0};
    for (int i = 0; i < n; i++)
    {

        if (dir[i] == 'R')
            dirs.first += 1;
        else if (dir[i] == 'L')
            dirs.first -= 1;
        else if (dir[i] == 'U')
            dirs.second += 1;
        else
            dirs.second -= 1;

        displacement.push_back(dirs);
    }

    if (dirs.first == x_goal && dirs.second == y_goal)
    {
        cout << 0 << endl;
        return 0;
    }

    int min_id = -1;

    int low = 0;
    int high = n;
    bool seen = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        for (int i = mid - 1; i < n; i++)
        {

            pair<int, int> left_side;
            if (i - mid + 1 == 0)
                left_side = {0, 0};
            else
                left_side = displacement[i - mid];
            int rem_x = left_side.first + (displacement[n - 1].first - displacement[i].first);
            int rem_y = left_side.second + (displacement[n - 1].second - displacement[i].second);

            int new_goal_x = x_goal - rem_x;
            int new_goal_y = y_goal - rem_y;

            if (mid >= abs(new_goal_x) + abs(new_goal_y) &&
                ((mid - (abs(new_goal_x) + abs(new_goal_y))) % 2 == 0))
            {

                if (min_id != -1)
                    min_id = min(mid, min_id);
                else
                    min_id = mid;
                seen = true;
                break;
            }
        }

        if (seen)
        {
            seen = false;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << min_id << endl;
}