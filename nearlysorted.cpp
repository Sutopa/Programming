/*
Given an array of n elements, where each element is at most k away from its target position.
 The task is to print array in sorted form.

Input:
First line consists of T test cases. 
First line of every test case consists of two integers N and K, 
denoting number of elements in array and at most k positions away from its target position respectively. 
Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56

*/
######### Just for learning github ###########
#include <iostream>
using namespace std;
int arr[100];

void swaap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}


int part(int l,int h)
{
    int piv,i,j;
    piv=l;
    j=h;
    i=l;
    while(i<j)
    {
      do{
        i++;
      }while(arr[i]<=arr[piv]);

      do{
        j--;
      }while(arr[j]>arr[piv]);

      if(i<j)
      {
          swaap(&arr[i],&arr[j]);
      }
    }
    swaap(&arr[j],&arr[piv]);
    return j;

}

void quick_sort(int l,int h)
{
    int i;
    if(l<h)
    {
        i=part(l,h);
        quick_sort(l,i);
        quick_sort(i+1,h);
    }
}



int main() 
{
	//code
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        int N,K,l,h;
        cin>>N>>K;
        for(int i=0;i<N; i++)
        cin>>arr[i];

        l=0,h=N;
        arr[N]=9999999;
        quick_sort(l,h);
        for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";

    }	
	return 0;
}
