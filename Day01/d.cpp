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

ll binPow(ll base, ll ex){
	if(ex==0) return 1;
	if(ex==1) return base;
	ll ans = binPow(base, ex/2);
	ans *= ans;
	if(ex%2) ans *= base;
	return ans;
}

void solve(){
	ll a,b;
	cin >> a >> b;
	cout << binPow(a, b) + binPow(b, a) << "\n";
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
