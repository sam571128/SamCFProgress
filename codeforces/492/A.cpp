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
	cini(a);
	intz(result);
	int count = 1;
	int sum = count*(count+1)/2;
	while(a>=sum){
		result++;
		count++;
		sum+=count*(count+1)/2;
	}
	cout << result;
	
}