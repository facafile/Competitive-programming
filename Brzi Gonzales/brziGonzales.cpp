#include <iostream>

using namespace std;

int main(void)
{
   int n;
   long long rj = 0;
   cin >> n;
   long long arr[n][n];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cin >> arr[i][j];
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         rj += arr[i][j];
   }
   cout << rj;
   return 0;
}