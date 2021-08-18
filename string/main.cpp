#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;


int main()
{
   
   string s="11011";
   int len=s.length();

int a=0;
   for(int i=0;i<len;i++)
   {
      a+=pow(2,i)*(s[len-1-i]-48);
   }

   cout<<a;

   
return 0;
}