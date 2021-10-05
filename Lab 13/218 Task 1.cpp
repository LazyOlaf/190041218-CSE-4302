#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,4,6,8,10};
    set<int>s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    vector<int>v(8);
    merge(arr,arr+5,s.begin(),s.end(),v.begin());
    for(int i=0; i<8; i++)
        cout<<v[i]<<" ";
    return 0;
}
