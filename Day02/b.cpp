#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<61)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
const int maxn = 212345;
const int maxp = 20;
const int mod = 998244353;

void solve(){
	int n;
	cin >> n;
	vi v(n+1);
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}


	int ans = 0;
	for(int i=1;i<=n;i++){
		// just a brute on the linear function
		for(int k=2*i/v[i]+1;v[i]*k - i <= n;k++){
			int value = v[i] * k - i;
			ans += (v[value] == k);
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


