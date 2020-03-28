#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int s,n;
	cin >> s >> n;
	vector<pair<int,int>> d;
	while(n--){
		int a,b;
		cin >> a >> b;
		d.push(pair<int,int>(a,b));
	}
	sort(d.begin(),d.end());
	for(int i = 0;i < d.size();i++){
		if(s<=d[i].first){
			cout<<"NO";
			return 0;
		}else{
			s+=d[i].second;
		}
	}
	cout << "YES";
}