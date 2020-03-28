#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	vector<int> h;
	vector<int> g;
	while(n--){
		int a,b;
		cin >> a >> b;
		h.push(a);
		g.push(b);
	}
	int result = 0;
	for(int i = 0;i < h.size();i++){
		for (int j = 0; j < i; ++j)
        {
            if (h[i] == g[j])
            {
                result += 1;
            }
            if (g[i] == h[j])
            {
                result += 1;
            }
        }
	}
	cout << result;
}