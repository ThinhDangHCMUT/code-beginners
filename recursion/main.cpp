#include<iostream>
#include<math.h>
using namespace std;

//Array Fibonacci
int fibonacci(int n)
{
    if(n==1 ||n==2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
//Find UCLN
int UCLN(int a, int b)
{
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b,a%b);
}
//Find BCNN
int BCNN(int a, int b)
{
    if(a==b) return a;
    return a*b/UCLN(a,b);
}
//Find maxUoc of certain number
int maxU(int n)
{
    static int i=n/2;
    if(n%2==1) return n;
    if(n%i==0 && i%2==1) return i;
    i--;
    return maxU(n);
}
//Tinh giai thua cua mot so bat ki
int Giaithua(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    return n*Giaithua(n-1);
}
//Tinh luy thua a^b
int LuyThua(int a, int b)
{
    if(b==1) return a;
    if(b%2==1) return a*LuyThua(a,b/2)*LuyThua(a,b/2);
     return LuyThua(a,b/2)*LuyThua(a,b/2);
}
//Find reverse number
int count(int n)
{
    static int i=0;
    if(n<10) return ++i;
    ++i;
    return  count(n/10);
}
// Reverse the number
int ReNumber(int n)
{
   static int i= count(n);
   if(n<10) return n;
   int rem=n%10;
   i--;
   n=n/10;
   return rem*pow(10,i)+ReNumber(n);
}
//Dec to Bin
int dectobin(int a)
{
    if(a==0) return 0;
    int b=a%2;
    return dectobin(a/2)*10+b;
}
//Find the sum among the amount of letters of the number
int SumofOddnumber(int n)
{
    if(n<0) return -1;
    static int sum=0;
    int i=n%10;
    if(i%2==1) sum+=i;
    n=n/10;
    if(n==0) return sum;
    return SumofOddnumber(n);       
}

int main()
{
 
}