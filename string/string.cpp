#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;


void SingleChar(string s)
{
    int cnt=0;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        
        if(s[i]==' ') cnt++;
        if(i==len-1)
        {
            if('a'<=s[i]<='z' || 'A'<=s[i]<='Z') cnt++;
        }
    }

    cout<<"The number charaters in the string is: "<<cnt<<endl;
}

void SecondChar(string s)
{
    int len=s.length();
    int cnt=0;
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ') cnt++;
        if(s[i]==' ' || i==len-1)
        {
            if(cnt>=2)
            {
              count++; cnt=0;
            }
        }
    }

    cout<<"The equal is: "<<count<<endl;
}

void maxChar(string s)
{
    int len=s.length();
    int lens1=0;
    int max=0;
    int l=0;
    int r;
    
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            lens1=i-l;
            if(lens1>max)
            {
                max=lens1;
            }
            l=i+1;
        }
        if(i==len-1)
        {
            for(int j=len-1;j>=0;j--)
            {
               if(s[j]==' ')
               {
                   lens1=len-j-1;
                   if(lens1>max)
                   {
                       max=lens1;
                      
                   }
                   break;
               }
            }
        }
    }

    cout<<"Max is: "<<max<<endl;
}

void reverse(string s)
{
    int len=s.length();
    string s1;
   for(int i=len-1;i>=0;i--)
   {
       s1+=s[i];
   }
   s=s1;
   cout<<"The string after revesing is: "<<s<<endl;
}

void checkPalind(string s)
{
    int len=s.length();
    int l=0,r=0;
    int check=1;

    if(len%2==1)
    {
        l=len/2-1; r=len/2+1;
        while(l>=0 && r<=len-1)
        {
            if(s[l] != s[r])
            {
                 check=0;
                 break;
            }
            l--;r++;
        }
    }
    if(len%2==0)
    {
        l=len/2-1; r=len/2;
        while(l>=0 && r<=len-1)
        {
            if(s[l] != s[r])
            {
                 check=0;
                 break;
            }
            l--;r++;
        }
    }

    if(check) cout<<"Palindrome!"<<endl;
    else cout<<"Not Palindrome!"<<endl;
}

void checksubPalind(string s)
{
    int cnt=0;
    int len=s.length();
    for(int i=1; i < len-1 ; i++)
    { 
        if(s[i-1]==s[i+1]) cnt++;
    }
    for(int i=0; i <= len-1 ; i++)
    { 
        if(s[i]==s[i+1]) cnt++;
    }

    cout<<"The number of subPalindrome string is: "<<cnt<<endl;
}

void maxSubPalind(string s)
{
    int max=1;
    int start=0;
    int l,r;
    int len=s.length();
    for(int i=1; i<len; i++)
    {
        //for even substring
        l=i-1;r=i;
        while(l>=0 && r<len && s[l]==s[r])
        {
            if(r-l+1>=max)
            {
                max=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
        //for odd substring
        l=i-1;r=i+1;
        while(l>=0 && r<len && s[l]==s[r])
        {
            if(r-l+1>=max)
            {
                max=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
    }

    cout<<"The max length of substring is: "<<max<<endl;
    cout<<"The sub string is: "<<s.substr(start,max)<<endl;
}

void countSubstr(string s, string s1)
{
   int len=s.length();
   int len1=s1.length();
   int cnt=0;
   int count=0;

   for(int i=0;i<=len-len1;i++)
   {
       for(int j=0;j<len1;j++)
       {
           if(s1[j]==s[i+j]) cnt++;
       }
       if(cnt==len1){ count++; cnt=0;}
       else cnt=0;
   }

   cout<<"The time of present substring in string s is: "<<count<<endl;
}

void FindMaxSubstr(string s)
{
     int len=s.length();
     string s1;
     s1=s[0];
     int max=1;
     int cnt=1;
     
     for(int i=1;i<len;i++)
     {
        if(s1.find(s[i])!=-1)    //tìm thấy trong s1 phần tử s[i] 
        {
            if(cnt>=max) max=cnt;
            cnt=1;   //reset lại cnt
            s1=s[i];
        }
        else
        {
            cnt+=1;
            s1+=s[i];
        }
        if(i==len-1)
        {
            if(cnt>=max) max=cnt;
        }

     }

     cout<<"The equal is: "<<max<<endl;
}

int main()
{
   string s;
   getline(cin,s);
   string s1;
   getline(cin,s1);
    
   cout<<"---------------THE TASK---------------"<<endl;
   cout<<'\n';

//    SingleChar(s);
//    cout<<endl;
//    SecondChar(s);
//    cout<<endl;
//    maxChar(s);
//    cout<<endl;
//    reverse(s);
//    cout<<endl;
//    checkPalind(s);
//    cout<<endl;
//    checksubPalind(s);
//    cout<<endl;
//    maxSubPalind(s);
      countSubstr(s,s1);
      FindMaxSubstr(s);

   

   
   cout<<'\n';
   cout<<"----------------THE END-----------------"<<endl;
   return 0;
}