#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    int grid[n][m];
    for(int i = 0; i < n;i++){
        for(int j = 0;j < m;j++) cin >> grid[i][j];
    }
    bool ok = true;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if((i==0&&j==0)||(i==n-1&&j==m-1)||(i==0&&j==m-1)||(i==n-1&&j==0)){
                if(grid[i][j] > 2){
                    ok = false;
                    break;
                }
                grid[i][j] = 2;
            }else if((i==0)||(j==0)||(i==n-1)||(j==m-1)){
                if(grid[i][j] > 3){
                    ok = false;
                    break;
                }
                grid[i][j] = 3;
            }else{
                if(grid[i][j] > 4){
                    ok = false;
                    break;
                }
                grid[i][j] = 4;
            }
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) cout << grid[i][j] << " ";
            cout << "\n";
        }
    }else{
        cout << "NO\n";
    }
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}