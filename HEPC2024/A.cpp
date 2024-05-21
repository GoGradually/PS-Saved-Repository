#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin>>n;
    vector<int> arr(n), arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        arr2[i] = arr[i];
    }

    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(arr[j-1] > arr[j]){ 
                swap(arr[j-1], arr[j]);
                ans1++;
            }
        }
    }
    int ans2 = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n-1; j++)
        {
            if(arr2[j] < arr2[j+1]){
                swap(arr2[j], arr2[j+1]);
                ans2++;
            }
        }
        
    }
    cout<<min(ans1, ans2)<<'\n';
    
    return (0);
}