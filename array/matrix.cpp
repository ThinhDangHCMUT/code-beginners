#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

#define MAX 1000

void EnterArray(int a[], int size)
{
    //srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        // a[i] = rand() % 100;
        cin>>a[i];
    }
}

void ExportArray(int a[], int size)
{
    cout << "------------" << endl;
    cout << "Array for " << size << " element is: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//check Even or Odd element in array 
void EvenOdd(int a[], int size, int count)
{

    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
            count++;
    }
    cout << "The number of the evennum is: " << count << endl;
}

//Check Square Number
void checkSquareNumber(int a[], int size)
{
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < a[i]; j++)
        {
            if (a[i] == j * j)
                cnt++;
        }
    }
    cout << "Square Number is: " << cnt << endl;
}

bool checkSquareNumber(int a)
{
    for (int j = 1; j < a; j++)
    {
        if (a == j * j)
            return 1;
    }
    return 0;
}

//check Prime
bool checkPrime(int a)
{
    int cnt = 0;
    if (a == 0 || a == 1)
        return 0;
    if (a == 2 || a == 3)
        return 1;
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            cnt++;
    }
    if (cnt >= 1)
        return 0;
    else
        return 1;
}

//check Fibonacci Array
bool checkFibo(int a[], int Fibo[], int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<50;j++)
        {
          if(a[i]==Fibo[j]) {cnt++; break;}
        }
    }
    if(cnt>=(n/2+1)) return 1;
    return 0;
}

//Sorting Array
void sort(int a[], int size)
{
    int l=0, r=-1;
    int cnt=1;
    int max=0;
    
    for(int i=0;i<size;i++)
    {
        if(a[i+1]>a[i])
        {
            cnt++;
            if(i+1==size-1)
            {
                  if(max<cnt)
                  {
                      max=cnt;
                      cnt=1;
                      r=size-1;
                      l=r-max+1;
                      break;
                  }
            }
        }
        else{
            if(max<cnt)
            {
                max=cnt;
                cnt=1;
                r=i;
                l=(r-max)+1;

            }
        }
    }

   

   int s=0;
   for(int i=l;i<=r;i++)
   {
       s+=a[i];
   }

   cout<<"Sum: "<<s<<endl;
    
}

//Bubble Sorting
void bubbleSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

//Sum of three last elements in array
void SumOfThree(int a[], int size)
{
    int sum = a[size - 1] + a[size - 2];
    int k = size - 3;
    // 2 even or 2 odd
    if ((a[size - 1] % 2 == 0 && a[size - 2] % 2 == 0) || (a[size - 1] % 2 == 1 && a[size - 2] % 2 == 1))
    {
        while (k >= 0)
        {
            if (a[k] % 2 == 0)
            {
                sum += a[k];
                break;
            }
            k--;
        }
    }
    // 1 even 1 odd
    if ((a[size - 1] % 2 == 0 && a[size - 2] % 2 == 1) || (a[size - 1] % 2 == 1 && a[size - 2] % 2 == 0))

    {
        while (k >= 0)
        {
            if (a[k] % 2 == 1)
            {
                sum += a[k];
                break;
            }
            k--;
        }
    }

    cout << "The maxsum of three element in array is: " << sum << endl;
}

//Find the position of the nguyento element in array
int FindPrimeNumber(int a[], int n)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(a[i]))
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void firstNum(int a[], int n)
{
    int s=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           if(j==i) j++;
           if(a[i]==a[j]) {cnt++;}
       }
       if(cnt==0) s+=a[i];
       else cnt=0;
    }

    cout<<"Sum of them: "<<s<<endl;
}
// Check the element that exist two times in array
void secondNum(int a[], int n)
{
    int c=0;
    int count=0;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           if(j==i) j++;
           if(a[i]==a[j]) {cnt++;}

       }
       if(cnt==2) 
       { 
           for(int k=i;k<n;k++) a[k]=a[k+1]; n--;
           count++; cnt=1;
        }
       if(cnt>2){cnt=1;}  // reset cnt về 1
    }

    cout<<"The number of the element had two time in arrays: "<<count<<endl;
}

//Check the medium element
int checkMedian(int a[],int n)
{
    int MedianNum;
    bubbleSort(a,n);
    if(n%2==0) MedianNum=a[n/2-1];
    if(n%2==1) MedianNum=a[n/2];

    return MedianNum;
}


//MAIN
int main()
{
    int arr[MAX];
    int n;
    int pos;
    cout << "Enter amount of array: ";
    cin >> n;

    EnterArray(arr, n);
    ExportArray(arr, n);
    // int Count;
    // numEven(arr,n,Count);
    // checkSquareNumber(arr,n);
    // bubbleSort(arr,n);
    // ExportMang(arr,n);
    // SumOfThree(arr,n);
    // pos = checkPrime(arr, n);
    // cout << "The position of the Nt element in array: " << pos << endl;
    
    //Declare Fibonacci array
    // int *f = new int[MAX];
    // f[0] = 0;
    // f[1] = 1;
    // for (int i = 2; i < MAX; i++)
    // {2
    //     f[i] = f[i - 1] + f[i - 2];
    // }

    // if(checkFibo(arr,f,n)) cout<<"Right! "<<endl;
    // else cout<<"Not! "<<endl;
  
    //sort(arr,n);
    //firstNum(arr,n);
    //secondNum(arr,n);
    return 0;
}
