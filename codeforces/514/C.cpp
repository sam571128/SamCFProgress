#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

const int p = 31, MOD = 1e12+9;
int gethash(string s){
	int res = 0, nowp = 1;
	for(auto c : s){
		res = (res+(c-'a'+1)*nowp%MOD)%MOD;
		nowp = nowp*p%MOD;
	}
	return res;
}
const int p2 = 17, MOD2 = 1e9+7;
int gethash2(string s){
	int res = 0, nowp = 1;
	for(auto c : s){
		res = (res+(c-'a'+1)*nowp%MOD2)%MOD2;
		nowp = nowp*p2%MOD2;
	}
	return res;
}

gp_hash_table<int,int,chash> cnt;
gp_hash_table<int,int,chash> cnt2;
gp_hash_table<int,int,chash> len;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	while(n--){
		string s;
		cin >> s;
		int val = gethash(s);
		int val2 = gethash2(s);
		len[s.size()] = 1;
		cnt[val] = 1;
		cnt2[val2] = 1;
	}
	while(m--){
		string s;
		cin >> s;
		int val = gethash(s);
		int val2 = gethash2(s);
		int nowp = 1, nowp2 = 1;
		for(int i = 0;i < s.size();i++){
			for(int j = 1;j <= 3;j++){
				if(j==(s[i]-'a'+1)) continue;
				int tmp1 = ((val-(s[i]-'a'+1)*nowp%MOD+ j*nowp%MOD)%MOD + MOD)%MOD;
				int tmp2 = ((val2-(s[i]-'a'+1)*nowp2%MOD2+ j*nowp2%MOD2)%MOD2 + MOD2)%MOD2;
				if(cnt[tmp1]&&cnt2[tmp2]){
					cout << "YES\n";
					goto stop;
				}
			}
			nowp = nowp*p%MOD;
			nowp2 = nowp2*p2%MOD2;
		}
		cout << "NO\n";
		stop:;
	}
}