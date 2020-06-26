#include <bits/stdc++.h>
 
using namespace std;
int n, k;
string s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111",
                "1111011"};
int cost[2004][10];
int dp[2004][4004];
 
int main() {
    cin >> n >> k;
    string t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        for (int j = 0; j < 10; ++j) {
            int res = 0;
            for (int l = 0; l < 8; ++l) {
                if (t[l] == '1' && s[j][l] == '0') {
                    cost[i][j] = -1;
                    break;
                }
                if (t[l] == '0' && s[j][l] == '1') {
                    res++;
                }
            }
            if (cost[i][j] != -1)cost[i][j] = res;
        }
    }
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int l = 0; l < 10; ++l) {
            if (cost[i][l] == -1)continue;
            for (int j = 0; j <= k; ++j) {
                if (dp[i + 1][j] == 1)dp[i][j + cost[i][l]] = 1;
            }
        }
    }
    string ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (cost[i][j] == -1)continue;
            if (k < cost[i][j])continue;
            if (dp[i + 1][k - cost[i][j]] != 1)continue;
            ans += '0' + j;
            k -= cost[i][j];
            break;
        }
        if (ans == "") {
            ans = "-1";
            break;
        }
    }
    cout << ans << endl;
}