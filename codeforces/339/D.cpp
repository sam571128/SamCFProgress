#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> t;

int n, m;
void modify(int pos, int val){
	t[pos+n] = val;
	pos += n;
	pos >>= 1;
	for(bool ok = false;pos;pos>>=1, ok = !ok){
		t[pos] = (ok ? (t[pos<<1]^t[pos<<1|1]) : (t[pos<<1]|t[pos<<1|1]));

	}
}

signed main(){
	fastio
	cin >> n >> m;
	n = 1<<n;
	t.resize(n<<1,0);
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		modify(i,tmp);
	}
	while(m--){
		int a,b;
		cin >> a >> b;
		modify(a-1,b);
		cout << t[1] << "\n";
	}
}