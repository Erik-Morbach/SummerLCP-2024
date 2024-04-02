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
	ll k;
	cin >> k;
	ll cp = k-1;
	vi dig;
	while(cp>=0){
		if(cp == 0){
			dig.push_back(0);
			break;
		}
		dig.push_back(cp%26);
		cp/=26;
		cp--;
	}
	reverse(all(dig));
	for(auto w: dig){
		cout << char('A'+ w);
	}
	cout << "\n";
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

