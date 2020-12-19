#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e3+5;
char grid[N][N];
int dp[N][N] = {}, go[N][N] = {}, st = 0;
signed main(){
    fastio
    int n,k;
    cin >> n >> k;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    string ans(2*n-1,'a');
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i==0&&j==0){
                dp[i][j] = (grid[0][0]!='a');
                continue;
            }
            dp[i][j] = min((i==0 ? 1e9 : dp[i-1][j]),(j==0 ? 1e9 : dp[i][j-1])) + (grid[i][j]!='a');

            if(dp[i][j]<=k) {
                st = max(st,i+j+1);
                go[i+1][j] = 1, go[i][j+1] = 1;
            }
        }
    }
    go[0][0] = 1;
    for(int i = st; i < 2*n-1;i++){
        char c = 'z';
        for(int j = 0;j < n;j++){
            if(i-j>=0&&i-j<n&&go[j][i-j]){
                c = min(grid[j][i-j],c);
            }
        }
        for(int j = 0;j < n;j++){
            if(i-j>=0&&i-j<n&&go[j][i-j]&&c==grid[j][i-j])
                go[j+1][i-j] = 1, go[j][i-j+1] = 1;
        }
        ans[i] = c;
    }
    for(int i = 0;i < min(k,2*n-1);i++) ans[i] = 'a';
    cout << ans << "\n";
}