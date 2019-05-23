#include<iostream>
using namespace std;


int thanos_snap(const int arr[],int l,int h)
{
    return (h-l)/2;
}


bool check(const int arr[],int l, int h)
{
    for(int i=l; i<h; i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}


int thanos_snap_out(const int arr[],int l,int h)
{
    bool sorted,sortedA,sortedB;
    sorted=check(arr,l,h);
    if(l==h)
    return 1;
    if(sorted==true)
    return h+1;
    else
    {
        int mid;
        mid=thanos_snap(arr,l,h);
        sortedA=check(arr,l,mid);
        sortedB=check(arr,mid+1,h);
        if(sortedA==true&&sortedB==true)
        return mid+1;
        else
        {
            thanos_snap_out(arr,l,mid);
            thanos_snap_out(arr,mid+1,h);
        }
    }
    
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n;i++)
    cin>>arr[i];
    int l,h;
    l=0,h=n-1;
    cout<<thanos_snap_out(arr,l,h);
    return 0;
}
