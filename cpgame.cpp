#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> maze, int row, int col, vector<vector<bool>> &seen);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int cols;
        cin >> cols;

        vector<vector<char>> maze(2);

        string row1, row2;

        cin >> row1 >> row2;

        vector<vector<bool>> seen(2);

        for (int i = 0; i < cols; i++)
        {
            maze[0].push_back(row1[i]);
            maze[1].push_back(row2[i]);
            seen[0].push_back(false);
            seen[1].push_back(false);
        }

        if (dfs(maze, 0, 0, seen))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

bool dfs(vector<vector<char>> maze, int row, int col, vector<vector<bool>> &seen)
{

    // cout << "cur row: " << row << endl;
    // cout << "cur col: " << col << endl;
    if (row == 1 && col == maze[0].size() - 1)
        return true;

    seen[row][col] = true;

    bool go_right = false;
    bool go_down = false;
    bool go_diagonal = false;

    // cout << "starting checks\n";
    if (col < maze[0].size() - 1 && maze[row][col + 1] == '0' && !seen[row][col + 1])
    {
        // cout << "going to [" << row + 1 << ", " << col << "]" << endl;
        go_right = dfs(maze, row, col + 1, seen);
    }

    if (row != 1 && maze[row + 1][col] == '0' && !seen[row + 1][col])
    {
        // cout << "going to [" << row << ", " << col + 1 << "]" << endl;
        go_down = dfs(maze, row + 1, col, seen);
    }

    if (col < maze[0].size() - 1 && row == 0 && maze[row + 1][col + 1] == '0' && !seen[row + 1][col + 1])
    {
        // cout << "going to [" << row + 1 << ", " << col + 1 << "]" << endl;
        go_diagonal = dfs(maze, row + 1, col + 1, seen);
    }

    if (col < maze[0].size() - 1 && row == 1 && maze[row - 1][col + 1] == '0' && !seen[row - 1][col + 1])
    {
        // cout << "going to [" << row - 1 << ", " << col + 1 << "]" << endl;
        go_diagonal = dfs(maze, row - 1, col + 1, seen);
    }

    if (go_right || go_down || go_diagonal)
        return true;
    else
        return false;
}