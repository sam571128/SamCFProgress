#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	priority_queue<int,vector<int>,greater<int>> q;
	int cnt = 1e9;
	int tmp = 0;
	for(int i = 0, x;i < n;i++){
		cin >> x;
		if(x>=0) cnt++;
		else{
			q.push(cnt);
			cnt = 0;
			tmp++;
		}
	}
	if(tmp > k){
		cout << -1 << "\n";
		return 0;
	}
	if(q.empty()){
		cout << 0 << "\n";
		return 0;
	}
	k -= tmp;
	while(q.top()<=k){
		k -= q.top();
		q.pop();
	}
	if(k>=cnt) cout << q.size()*2-1;
	else cout << q.size()*2;
}