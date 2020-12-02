#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
int trie[N*32][2], val[N*32], cnt = 1;
int tmp[N*32];

void insert(int num){
	int now = 0;
	for(int i = 30;~i;i--){
		int bit = ((num>>i)&1);
		if(!trie[now][bit]){
			trie[cnt][0] = trie[cnt][1] = 0;
			trie[now][bit] = ++cnt;
		}
		now = trie[now][bit];
		tmp[now]++;
	}
	val[now] = num;
}

int query(int num){
	int now = 0, ans = 0;
	for(int i = 30;~i;i--){
		int bit = ((num>>i)&1);
		if(trie[now][bit]&&tmp[trie[now][bit]]){
			now = trie[now][bit];
		}else{
			now = trie[now][bit^1];
		}
		tmp[now]--;
	}
	return val[now];
}

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		insert(tmp);
	}
	for(auto x : arr){
		cout << (x^query(x)) << " ";
	}
}