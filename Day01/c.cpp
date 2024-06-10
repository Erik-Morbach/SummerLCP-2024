#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<60)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
#define MOD 1000000007
const int maxn = 1123456;


void solve(){
	int n;
	cin >> n;
	vll v(n);
	ll avg = 0;
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(all(v));

	if(n%2==0)
		avg = (v[n/2-1]+v[n/2])/2;
	else avg = v[n/2];
	ll best = 0;
	for(int i=0;i<n;i++){
		best += abs(v[i] - avg);
	}

	cout << best << "\n";

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0)->tie(0);
	int t = 1;
	//cin >> t;

	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}
