#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

bool can(int m, int s){
	return s>=0&&s<=9*m;
}

int main(){
	fastio
	cini(a);
	cini(b);
	if(a==1&&b==0){
		cout << "0 0";
		return 0;
	}
	if(ceil(1.0*b/a)>9||1.0*b/a==0){
		cout << "-1 -1";
		return 0;
	}
	int s = b;
	string mi = "";
	for(int i = 0;i < a;i++)
		for(int j = 0;j < 10;j++){
			if((i>0||j>0||(a==1&&j==0))&&can(a-i-1,s-j)){
				mi+=char('0'+j);
				s-=j;
				break;
			}
		}
	s = b;
	cout << mi << " ";
	string ma = "";
	for(int i = 0;i < a;i++)
		for(int j = 9;j > 0;j--){
			if(can(a-i-1,s-j)){
				ma+=char('0'+j);
				s-=j;
				break;
			}
		}
	while(ma.size()!=a)ma+=char('0');
	cout << ma;
}