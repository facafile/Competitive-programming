#include <iostream>
#include <algorithm>
 typedef long long ll;
using namespace std;
 
ll najmanjiBrojPromjena(ll a[], ll n)
{
    ll y;
    if (n % 2 == 1)
        y = a[n / 2];
 
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
 
    ll s = 0;
    for(int i = 0; i < n; i++)
        s += abs(a[i] - y);
         
    return s;
}
 
 
int main(void){
	ll n,m,x,y;
    x=0;
    y=0;
    cin>>n;
    m=(n*n-n)/2;
    ll array[n][n];
    ll array_g[m];
    ll array_d[m];
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>array[i][j];
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i<j){
                array_g[x]=array[i][j];
                x++;
            }
            else if(i>j){
                array_d[y]=array[i][j];
                y++;
            }
        }
 
    sort(array_g,array_g+m);
    sort(array_d,array_d+m);
    x= najmanjiBrojPromjena(array_g, m);
    y= najmanjiBrojPromjena(array_d, m);
    if(x<=y)cout<<x;
    else cout<<y;
 
    return 0;
}
//https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/, ovdje sam uzeo ideju za kod