#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;


int Length(char s[])
{
   if(*(s+0)==0) return 0;
   return 1+Length(s+1);
}

int FindX(char s[], char c)
{
   static int k=0;
   if(*(s)==c) return k;
   k++;
   return FindX(s+1,c);
}

void String(char s[], int n)
{
   if(n==0) return;
   cout<< *(s+n-1);
   return String(s,n-1);
}

bool checkBin(char s[])
{
   static int n=Length(s);
   static int i=0;
   if(*s != '1' && *s != '0') return false;
   i++;
   if(i==n) return true;
   return checkBin(s+1);
}

int BintoDec(char s[])
{
   static int n=Length(s);
   static int dec=0;
   static int i=0;
   dec+= pow(2,i)*((*s)-48);
   i++;
   if(i==n) return dec;
   return BintoDec(s+1);
}

bool checkPalind(char s[])
{
   static int len=Length(s);
   static int l=0;
   static int r=len-1; 

   if(*(s+l)!=*(s+r)) return false;
   l++;
   r--;
   if(l==r) 
   {
      if(*(s+l)!=*(s+r)) return false;
      return true;
   }
   return checkPalind(s);
}



int main()
{      
   char s[20]="1234543";
   
  bool check=checkPalind(s);
  cout<<check<<endl;
}

