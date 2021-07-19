#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define lp(n) for(lli i=0;i<n;i++)
#define inf 1e9
#define mod inf+7
lli countDistinct(lli arr[], lli k, lli n)
{
    // Creates an empty hashmap hm
    unordered_map<int, int> hm;
 
    // initialize distinct element count for current window
    lli dist_count = 0;
 
    // Traverse the first window and store count
    // of every element in hash map
    for (int i = 0; i < k; i++) {
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
    }
 
    // Print count of first window
    lli ans=dist_count;
 
    // Traverse through the remaining array
    for (int i = k; i < n; i++) {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (hm[arr[i - k]] == 1) {
            dist_count--;
        }
        // reduce count of the removed element
        hm[arr[i - k]] -= 1;
 
        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count
 
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
 
        // Print count of current window
        ans=max(ans,dist_count);
    }
    return ans;
}
int main()
{
    lli n,k;
    cin>>n>>k;
    lli arr[n];
    lp(n)
    cin>>arr[i];
    cout<<countDistinct(arr,k,n);

}