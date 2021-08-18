#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

bool isLeapYear(int year)
{
    if(year >=4 && year%4==0) return true;
    return false;
}

void whichCentury(const int year, int& century)
{
    if(year<=99) century=1;
    else if(year>99) century=year/100+1;
}

void LargestMul(int *arr, int& largestAdjacentProduct)
{
     largestAdjacentProduct=arr[0]*arr[1];
     for(int i=1;i<9;i++)
     {
        if(largestAdjacentProduct<arr[i]*arr[i+1])
        largestAdjacentProduct=arr[i]*arr[i+1];
     }
}

bool isSubstring(string& a, string& b)
{
    int check=0;
    int lena=a.length();
    int lenb=b.length();

    if(lena<lenb)
    {
       for(int i=0;i<=lenb-lena;i++)
       {
           for(int j=0;j<lena;j++)
           {
               if(a[j]==b[i+j]) check=1;
               if(a[j]!=b[i+j]) check=0;
           }
           if(check) return true;
       }
    }
    return false; 
}



int main()
{
   string a="abcda";
   string b="bcdddadaaabcda";

   bool check=isSubstring(a,b);
   cout<<check;

}