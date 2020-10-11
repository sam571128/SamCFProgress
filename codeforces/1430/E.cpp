#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int bit[N];
 
void modify(int pos, int val){
	while(pos<N){
		bit[pos] += val;
		pos += pos&-pos;
	}
}
 
int query(int pos){
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos&-pos;
	}
	return res;
}
int arr[N];
vector<int> v[26];
signed main(){
	fastio
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0;i < 26;i++) v[i].reserve(N);
	reverse(s.begin(),s.end());
	for(int i = 0;i < n;i++){
		v[s[i]-'a'].push_back(i);
	}
	reverse(s.begin(),s.end());
	for(int i = 0;i < 26;i++) reverse(v[i].begin(), v[i].end());
	for(int i = 0;i < n;i++){
		assert(!v[s[i]-'a'].empty());
		arr[i] = v[s[i]-'a'].back()+1; v[s[i]-'a'].pop_back();
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += query(N-1)-query(arr[i]);
		modify(arr[i],1);
	}
	cout << ans << "\n";	
}