#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 55;
char arr[N][N];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(ll i, ll j){
	return (i<=n&&j<=m&&i>0&&j>0);
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> arr[i][j];
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++){
				if(arr[i][j]=='B'){
					for(int k = 0;k < 4;k++){
						ll ni = i + dir[k][0];
						ll nj = j + dir[k][1];
						if(valid(ni,nj)&&arr[ni][nj]=='.'){
							arr[ni][nj] = '#';
						}
					}
				}
			}
		//for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cout << arr[i][j];
		queue<pair<int,int>> q;
		bool visited[n+5][m+5];
		memset(visited,false,sizeof visited);
		if(arr[n][m]=='.'){
			q.push({n,m});
			visited[n][m] = true;
		}
		while(!q.empty()){
			auto x = q.front();
			q.pop();
			for(int k = 0;k < 4;k++){
				ll ni = x.first + dir[k][0];
				ll nj = x.second + dir[k][1];
				if(valid(ni,nj)&&arr[ni][nj]!='#'&&!visited[ni][nj]){
					q.push({ni,nj});
					visited[ni][nj] = true;
				}
			}
		}
		bool ans = true;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if((arr[i][j] == 'G'&& !visited[i][j])||(arr[i][j]=='B'&&visited[i][j])){
					ans = false;
					break;
				}
			}
		}

		cout << (ans?"Yes\n":"No\n");

	}
}