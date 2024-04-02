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
const int mod = 998244353;


ll fat[maxn];
void solve(){
	string s;
	cin >> s;
	vi blocks;
	int count = 1;
	for(int i=1;i<s.size();i++){
		if(s[i] != s[i-1]){
			blocks.push_back(count);
			count = 0;
		}
		count++;
	}
	blocks.push_back(count);

	int qnt = 0;
	ll ans = 1;
	for(int i=0;i<blocks.size();i++){
		qnt += (blocks[i] - 1);
		ans *= blocks[i];
		ans %= mod;
	}

	ans = (ans * fat[qnt]) % mod;

	cout << qnt << " " << ans <<"\n";
}

int main(){
	fat[0] = 1;
	for(int i=1;i<maxn;i++)
		fat[i] = (fat[i-1]*i)%mod;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}

