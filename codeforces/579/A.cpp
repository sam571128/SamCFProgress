#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int result = 0;
	cini(a);
	while(a!=0){
		result++;
		int temp = 0;
		while(a>=pow(2,temp)){
			temp++;
		}
		a-=pow(2,temp-1);
	}
	cout << result;
}