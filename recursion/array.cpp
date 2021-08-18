#include<iostream>
using namespace std;

int MaxinArr(int a[], int n)
{
     if(n==0) return -1;
     if(n==1) return a[0];
     if(n==2) return max(a[0],a[1]);
     return max(a[n-1],MaxinArr(a,n-1));        
}

int sumArr(int a[], int n)
{
      if(n==0) return -1;
      if(n==1) return a[0];
      return a[n-1]+sumArr(a,n-1);
}

int sumEvenArr(int a[], int n)
{
      if(n==0) return 0;
      if(n==1 && a[0]%2==0) return a[0];
      if(a[n-1]%2==0) return a[n-1]+sumEvenArr(a,n-1);
      return sumEvenArr(a,n-1);
}
bool check(int a[], int n)
{
    if(n==1 && a[0]>0 && a[0]%2==0) return 1;
    if(a[n-1]>0 && a[n-1]%2==0) return check(a,n-1);
    return 0; 
}

void ExportArr(int a[], int n)
{
    static int r=n;
    static int i=0;
    cout<<a[i]<<" ";
    i++;
    if(i==r) return;
    ExportArr(a,i);

}
int main()
{
   int a[10]={12,2,6,4,4,6,2,2,4,4};
   int max=MaxinArr(a,10);
  bool checks= check(a,10);
  // int sum=sumEvenArr(a,10);
   ExportArr(a,10);
}