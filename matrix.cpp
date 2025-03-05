#include <bits/stdc++.h>
using namespace std;

int main()
{

    short t;

    cin >> t;

    while (t--)
    {

        int rows, cols;

        cin >> rows >> cols;

        int parity;
        vector<int> parity_vec;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int parity = (i + j) % 2;

                int num;
                cin >> num;

                if (num % 2 != parity)
                    num += 1;

                parity_vec.push_back(num);
            }
        }

        for (int i = 0; i < parity_vec.size(); i++)
        {
            cout << parity_vec[i];
            if (i % cols != cols - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
}