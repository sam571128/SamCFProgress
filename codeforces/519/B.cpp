#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push emplace_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	cini(n);
	int sum1 = 0;
	for(int i = 0;i < n;i++){
		cini(temp);
		sum1+=temp;
	}
	int sum2=0;
	for(int i = 0;i < n-1;i++){
		cini(temp);
		sum2+=temp;
	}
	cout << sum1-sum2 << "\n";
	sum1 = 0;
	for(int i = 0;i < n-2;i++){
		cini(temp);
		sum1+=temp;
	}
	cout << sum2-sum1 << "\n";
}