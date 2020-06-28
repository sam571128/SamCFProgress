#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int arr[26], pos[N], t[N];
void solve(){
	memset(arr,0,sizeof arr);
	memset(pos,0,sizeof pos);
	memset(t,0,sizeof t);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0, tmp;i < m;i++) cin >> tmp, pos[tmp-1]++;
	pos[n-1] = 1;
	t[n-1] = pos[n-1];
	for(int i = n-2;i >= 0;i--) t[i] += t[i+1] + pos[i];
	for(int i = 0;i < n;i++) arr[s[i]-'a'] += t[i];
	for(int i = 0;i < 26;i++) cout << arr[i] << " ";
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}