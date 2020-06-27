#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int arr[n];
	for(int i = 0;i < n;i++){
		if(s[i]=='R') arr[i] = 1;
		else arr[i] = 0;
	}
	queue<vector<int>> q;
	int ma = 0;
	vector<int> v;
	while(true){
		v.clear();
		for(int i = 0;i < n-1;i++){
			if(arr[i]&&!arr[i+1]){
				v.push_back(i);
				swap(arr[i],arr[i+1]);
				i++;
			}
		}
		if(v.size()==0) break;
		ma += v.size();
		q.push(v);
	} 
	if(k < q.size() || k > ma){
		cout << -1 << "\n";
		return 0;
	}
	int cnt = k - q.size();
	while(!q.empty()){
		vector<int> tmp = q.front(); q.pop();
		while(tmp.size()>1&&cnt>0){
			cnt--;
			cout << 1 << " " << tmp.back()+1 << "\n";
			tmp.pop_back();
		}
		cout << tmp.size() << " ";
		for(auto x : tmp) cout << x+1 << " ";
		cout << '\n';
	}
}