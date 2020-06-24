#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6;
int vis[N+5];
int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		vis[tmp] = 1;
	}
	cout << n << "\n";
	int c = 0;
	for(int i = 1;i <= 1e6;i++){
		if(vis[i] == 1){
			if(vis[N-i+1]==0){
				cout << N-i+1 << " ";
				c++;
				vis[N-i+1] = 2;
			}
		}
	}

	for(int i = 1;i <= 1e6;i++){
		if(c < n){
			if(vis[i]==0&&vis[N-i+1]==0){
				cout << i << " " << N-i+1 << " ";
				c += 2;
			}
		}
	}
}