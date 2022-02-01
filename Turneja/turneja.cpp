#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
   long long n, q;
   long long tren;

   long long zadovoljni;
   long long max;

   cin >> n >> q;
   vector<pair<long long, long long>> lista;
   vector<long long> lista2;
   pair<long long, long long> par;
   for (long long i = 0; i < n; i++)
   {
      cin >> par.first >> par.second;
      lista.push_back(par);
   }
   for (long long j = 0; j < q; j++)
   {
      cin >> tren;
      lista2.push_back(tren);
   }
   sort(lista.begin(), lista.end());
   for (auto z = 0; z < q; z++)
   {
      long long zadovoljni = 0;
      long long max = 0;

      for (vector<pair<long long, long long>>::reverse_iterator i = lista.rbegin();
           i != lista.rend(); ++i)
      {
         if (zadovoljni >= lista2[z])
         {
            break;
         }
         else
         {
            max = i->first;
            zadovoljni += i->second;
         }
      }
      if (zadovoljni < lista2[z])
         max = -1;
      cout << max << endl;
   }

   return 0;
}