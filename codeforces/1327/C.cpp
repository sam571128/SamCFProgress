#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	pair<int,int> start[k];
	pair<int,int> end[k];
	for(int i = 0;i < k;i++){
		int x,y;
		cin >> x >> y;
		start[i] = {x,y};
	}
	for(int i = 0;i < k;i++){
		int x,y;
		cin >> x >> y;
		end[i] = {x,y};
	}
	cout << (n-1)+(m-1)+(n-1)*(m)+(m-1) << "\n";
	for(int i = 0;i < n-1;i++) cout << "U";
	for(int i = 0;i < m-1;i++) cout << "L";
	for(int i = 0;i < n-1;i++){
		for(int j = 0;j < m-1;j++) if(i&1^1) cout << "R"; else cout << "L";
		cout << "D";
	}
	for(int j = 0;j < m-1;j++) if((n-1)&1^1) cout << "R"; else cout << "L";
}