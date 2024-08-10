#include <bits/stdc++.h>

/*
https://codeforces.com/problemset/problem/1995/B1
*/

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<int> flowers(n);

        for (int i = 0; i < n; i++) {
            cin >> flowers[i];
        }

        sort(flowers.begin(), flowers.end());

        long long mx = 0;
        int p = 0, q = 0;
        long long sum = flowers[p];

        while (q < n) {
            if (sum <= m) {
                mx = max(sum, mx);
                q++;
                if (q < n) sum += flowers[q];
            }

            if (sum > m){
                sum -= flowers[p];
                p++;
            }

            while (q < n && p < n && flowers[q] - flowers[p] > 1 ) {
                sum -= flowers[p];
                p++;
            }
        }

        cout << mx << endl;
    }

    return 0;
}
