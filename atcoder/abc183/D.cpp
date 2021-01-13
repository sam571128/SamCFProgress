#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int arr[N];

signed main(){
	fastio
	int n,w;
	cin >> n >> w;
	for(int i = 0;i < n;i++){
		int s,t,p;
		cin >> s >> t >> p;
		arr[s]+=p;
		arr[t]-=p;
	}
	int now = 0;
	for(int i = 0;i < N;i++){
		now += arr[i];
		if(now > w){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}