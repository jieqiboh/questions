#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll k[n];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    map<ll,ll> mp;
    ll i=0,j=0,c=0,ans=0;
    while(j<n)
    {
        if(mp[k[j]]==0)
        {
            mp[k[j]]++;
            c++;
            ans=max(ans,c);
            j++;
        }
        else
        {
            c--;
            mp[k[i]]--;
            i++;
        }
    }
    cout<<ans;
}

