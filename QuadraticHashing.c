#include <stdio.h>

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

//bucket and array + size of both
void hashing(int table[], int tsize, int arr[], int N)
{
   for (int i = 0; i < N; i++)
   {
      // Direct hash when no collision
      int hv = arr[i] % tsize;

      // insert if it was empty before
      if (table[hv] == -1)
      {
         table[hv] = arr[i];
      }
      else
      {
         // If there is a collision
         for (int j = 0; j < tsize; j++)
         {
            // Calculating the new hash value
            int t = (hv + j * j) % tsize;

            //search till we get next empty bucket place
            if (table[t] == -1)
            {
               table[t] = arr[i];
               break;
            }
         }
      }
   }
   printArray(table, N);
}


int main()
{

   int arr[] = {50, 700, 76, 85, 92, 73, 101};
   int N = 7;

   // Size of the hash table
   int L = 7;
   int hash_table[7];

   // Initializing the hash table with -1 to denote empty
   for (int i = 0; i < L; i++)
   {
      hash_table[i] = -1;
   }

   hashing(hash_table, L, arr, N);
   return 0;
}