#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    int n;
    cin >> n;

    while (n--) {

        int nums;
        cin >> nums;

        unordered_map<int, int> my_nums;
        vector<int> colors;

        int color = 1;

        while (nums--) {
            int cur_num;
            cin >> cur_num;

            for (int prime : primes) {

                if (cur_num % prime)
                    continue;
                
                if (my_nums.find(prime) != my_nums.end()) {
                    colors.push_back(my_nums[prime]);
                } else {
                    colors.push_back(color);
                    my_nums[prime] = color;
                    color++;
                }

                break;
            }
        }
        cout << color - 1 << endl;

        for (int c : colors) {
            cout << c << " ";
        }
        cout << endl;
    }
}