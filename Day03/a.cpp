#include <algorithm>
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
const int mod = 1000000000 + 7;

void solve(){
	int n;
	cin >> n;
	vi nPode(10, 0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		nPode[x] = 1;
	}

	ll ans = 0;
	for(int i=0;i<=9;i++){
		if(nPode[i]) continue;
		for(int j=i+1;j<=9;j++){
			if(nPode[j]) continue;
			ans += 4*3/2;
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

