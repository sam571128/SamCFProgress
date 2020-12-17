#include <bits/stdc++.h>

#define int long long 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void count_sort(vector<int> &pos, vector<int> &rank){
	int n = pos.size();
	vector<vector<int>> cnt(n);
	for(int i : pos) cnt[rank[i]].push_back(i);
	for(int i = 0, idx = 0;i < n;i++)
		for(auto x : cnt[i])
			pos[idx++] = x;
}

void get_suffix(string s, vector<int> &pos){
	s += '$';
	int n = s.size();
	vector<int> rank(n);
	//k = 0
	iota(pos.begin(),pos.end(),0);
	sort(pos.begin(),pos.end(),[&](int a, int b){ return s[a] < s[b]; });
	for(int i = 0;i < n;i++){
		if(i==0){ 
			rank[pos[i]] = 0;
		}else{
			rank[pos[i]] = rank[pos[i-1]] + (s[pos[i]]!=s[pos[i-1]]);
		}
	}
	//k > 0
	vector<int> new_rank(n);
	for(int k = 0;(1<<k) <= n;k++){
		for(int i = 0;i < n;i++)
			pos[i] = (pos[i] - (1<<k)%n + n ) % n;
		count_sort(pos,rank);
		new_rank[pos[0]] = 0;
		for(int i = 1;i < n;i++){
			pair<int,int> prev = {rank[pos[i-1]], rank[(pos[i-1]+(1<<k))%n]};
			pair<int,int> now = {rank[pos[i]], rank[(pos[i]+(1<<k))%n]};
			new_rank[pos[i]] = new_rank[pos[i-1]] + (prev!=now);
		}
		rank = new_rank;
	}
}

const int N = 3e5+5;
int bit[2][N];

void update(int idx, int pos, int val){
	pos++;
	while(pos <= N){
		bit[idx][pos] += val;
		pos += pos&-pos;
	}
}

int query(int idx, int pos){
	pos++;
	int res = 0;
	while(pos){
		res += bit[idx][pos];
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	fastio
	string s;
	cin >> s;
	vector<int> SA1(s.size()+1);
	get_suffix(s,SA1);
	string s2 = s;
	reverse(s2.begin(),s2.end());
	vector<int> SA2(s.size()+1);
	get_suffix(s2,SA2);
	vector<int> SA1T(s.size()+1);
	vector<int> SA2T(s.size()+1);
	for(int i = 0;i <= s.size();i++){
		SA1T[SA1[i]] = i-1;
	}
	for(int i = 0;i <= s.size();i++){
		SA2T[SA2[i]] = i-1;
	}
	/*for(auto x : SA1) cout << x << " ";
	cout << "\n";
	for(auto x : SA2) cout << x << " "; 
	cout << "\n";*/
	int n;
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		int l = 1, r = s.size()+1;
		while(l < r){
			int mid = l+r>>1;
			string tmp = s.substr(SA1[mid],str.size());
			if(tmp < str){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		int lb1 = l;
		l = 1, r = s.size()+1;
		while(l < r){
			int mid = l+r>>1;
			string tmp = s.substr(SA1[mid],str.size());
			//cout << l << " " << r << " " << mid << " " << tmp << " " << str << " " << (tmp < str) << "\n";
			if(tmp <= str){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		int rb1 = l;
		if(lb1 < rb1){
			update(0,lb1-1,1);
			update(0,rb1-1,-1);
		}
		reverse(str.begin(),str.end());
		l = 1, r = s.size()+1;
		while(l < r){
			int mid = l+r>>1;
			string tmp = s2.substr(SA2[mid],str.size());
			if(tmp < str){
				l = mid+1;
			}else{
				r = mid;
			}
		}

		int lb2 = l;
		l = 1, r = s.size()+1;
		while(l < r){
			int mid = l+r>>1;
			string tmp = s2.substr(SA2[mid],str.size());
			if(tmp <= str){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		int rb2 = l;
		if(lb2 < rb2){
			update(1,lb2-1,1);
			update(1,rb2-1,-1);
		}
		//cout << lb1 << " " << rb1 << "\n";
		//cout << lb2 << " " << rb2 << "\n";
	}
	int ans = 0;
	for(int i = 1;i < s.size();i++){
		//cout << "Q " << SA1T[i] << " " << SA2T[s.size()-i] << "\n";//<< " " << query(0,SA1[i]) << " " << query(1,SA2[s.size()-i]) << "\n";
		ans += query(0,SA1T[i])*query(1,SA2T[s.size()-i]);
	}
	cout << ans << "\n";
}

/*
mtkpuovwudselwfbxxik
10
xx
vwu
kp
tk
ud
xi
ik
i
tk
xxi
*/