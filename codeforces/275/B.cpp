#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 50;
int vis[N][N];

int main(){
	fastio
	int n, m;
	cin >> n >> m;	
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			char tmp; 
			cin >> tmp;
			if(tmp=='B') v.push_back({i,j}), vis[i][j] = true;
		}
	for(int i = 0;i < v.size();i++){
		for(int j = i + 1;j < v.size();j++){
			if(v[i].first==v[j].first){
				for(int k = min(v[i].second,v[j].second);k <= max(v[i].second,v[j].second);k++){
					if(!vis[v[i].first][k]){
						cout << "NO\n";
						return 0;
					}
				}
			}
			if(v[i].second==v[j].second){
				for(int k = min(v[i].first,v[j].first);k <= max(v[i].first,v[j].first);k++){
					if(!vis[k][v[i].second]){
						cout << "NO\n";
						return 0;
					}
				}
			}
			if(!(vis[v[i].first][v[j].second]||vis[v[j].first][v[i].second])){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}