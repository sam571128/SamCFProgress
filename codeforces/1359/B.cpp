#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	if(2*x<y) y = 2*x;

	int ans = 0;
	char arr[n][m];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m-1;j++){
			if(arr[i][j] == '.' &&  arr[i][j+1]=='.'){
				ans += y;
				arr[i][j] = '*';
				arr[i][j+1] = '*'; 
			}
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j]=='.'){
				ans += x;
			}
		}
	}
	cout << ans << "\n";

}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}