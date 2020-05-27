#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		--n;
		string a, str[n];
		cin >> a;
		for(int i = 0;i < n;i++){
			cin >> str[i];
		}
		queue<string> q;
		string tmp = a;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 26;j++){
				a[i] = ('a' + j);
				q.push(a);
			}
			a = tmp;
		}
		bool done = false;
		while(!q.empty()){
			string s = q.front();
			q.pop();
			int count = 0;
			for(int i = 0;i < n;i++){
				count = 0;
				for(int j = 0;j < m;j++){
					if(s[j]!=str[i][j]) count++;
				}
				if(count>1) break;
			}
			if(count>1) continue;
			done = true;
			cout << s << "\n";
			break;
		}
		if(!done){
			cout << -1 << "\n";
		}
	}
}