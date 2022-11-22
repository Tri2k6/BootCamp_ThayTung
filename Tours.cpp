#include <bits/stdc++.h>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

#define ll long long 
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)

const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

string str;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(input,str);
    int n = str.length();
    int r = n - 1;
    int l = 0;
    while (str[l] != str[n - 1]) l++;
    while (str[r] != str[0]) r--;
    output << max(n - l,r) - 1;
    return 0;
}
