#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	vector<int> v;
	while(a--){
		int tmp;
		cin >> tmp;
		v.push(tmp);
	}
	int mi = INT_MAX;
	int ma = INT_MIN;
	for(int i = 0;i < v.size();i++){
		mi = min(mi,v[i]);
		ma = max(ma,v[i]);
	}
	
	int ima = -1,imi = -1;
	for(int i = 0;i < v.size();i++){
		if(v[i]==ma){
			ima = i;
			ma = INT_MAX;
		} 
	}
	for(int i = v.size()-1;~i;i--){
		if(v[i] == mi){
			imi = i;
			mi = INT_MIN;
		}
	}
	int count = ima-1+v.size()-imi;
	if(ima>imi){
		count--;
	}
	cout << count;
}