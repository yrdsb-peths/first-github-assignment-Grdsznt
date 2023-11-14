#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* TYPES  */
#define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vll vector<long long>
// #define mii map<int, int>
// #define si set<int>
// #define sc set<char>


// /* INPUTS */
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

// /* UTILS */
// #define MOD 1000000007
// #define PI 3.1415926535897932384626433832795
// ll min(ll a,int b) { if (a<b) return a; return b; }
// ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,int b) { if (a>b) return a; return b; }
// ll max(int a,ll b) { if (a>b) return a; return b; }
// ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
// ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
// bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }


// /* TYPEDEF */
// typedef long int int32;
// typedef unsigned long int uint32;
// typedef long long int int64;
// typedef unsigned long long int  uint64;



const int MM = 1.5e5 +2; const int LOG = __lg(MM);

int st[LOG+1][MM];

int qry (int l, int r) {
    int k = 31-__builtin_clz(r-l+1);
    return gcd(st[k][l], st[k][r-(1<<k)+1]);
} // equiv to the 2 ranges up to 2^k intersection gcd

int N, M, x[MM], y[MM], z[MM], da[17][MM], a[MM];

int main() {
    cin >> N >> M;

    for (int i = 1; i<=M;i++) {
        cin >> x[i] >> y[i] >> z[i];
        da[z[i]][x[i]]++; da[z[i]][y[i]+1]--;
    }
    for (int i = 1;i<=N;i++) {
        a[i] = 1;
        for (int k=1;k<=16;k++) {
            da[k][i] += da[k][i-1];
            if (da[k][i]) a[i] = lcm(a[i], k);

        }
        st[0][i] = a[i];
    }

    for (int k = 1;k<=LOG;k++) {
        for (int i = 1; i+(1<<k)-1<=N;i++) {
            st[k][i] = gcd(st[k-1][i], st[k-1][i+(1<<k-1)]);
        }
    }

    for (int i = 1;i<=M;i++) {
        if (qry(x[i], y[i]) != z[i]) {
            cout << "Impossible" << endl; return 0;
        }
    }

    for (int i = 1;i<=N;i++) cout << a[i] << " \n"[i==N];
}
