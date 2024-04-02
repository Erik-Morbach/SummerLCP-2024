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
const int maxn = 1123456;
const int mod = 998244353;

int primos[maxn];
void crivo(){
	for(ll i=2;i<maxn;i+=2){
		primos[i]++;
	}
	for(ll i=3;i<maxn;i+=2){
		if(primos[i] != 0) continue;
		primos[i] = 1;
		for(ll j=2*i;j<maxn;j+=i){
			primos[j]++;
		}
	}
}
ll ss[maxn][11];

void solve(){
	ll a, b, k;
	cin >> a >> b >> k;
	cout << ss[b][k] - ss[a-1][k] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	crivo();
	for(int i=0;i<maxn;i++){
		for(int j=0;j<=10;j++){
			ss[i][j] += primos[i] == j;
			ss[i+1][j] = ss[i][j];
		}
	}
	int t = 1;
	cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}

