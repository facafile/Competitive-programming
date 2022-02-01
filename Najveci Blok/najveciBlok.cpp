#include <iostream>
using namespace std;

int longestSubSeg(long long a[], long long n, long long k)
{
   long long cnt0 = 0;
   long long l = 0;
   long long max_len = 0;

   for (long long i = 0; i < n; i++)
   {
      if (a[i] == 0)
         cnt0++;

      while (cnt0 > k)
      {
         if (a[l] == 0)
            cnt0--;
         l++;
      }

      max_len = max(max_len, i - l + 1);
   }

   return max_len;
}

int main()
{
   long long n;
   long long k;
   cin >> n >> k;
   string str;
   cin >> str;
   long long a[n];
   for (long long i = 0; i < n; i++)
   {
      a[i] = str[i] - '0';
   }
   cout << longestSubSeg(a, n, k);
   return 0;
}
// https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/