#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FindMaxNth(int *a, int size, int n)
{
	int cnt = 0;
	int max = a[0];
	while (cnt<size)
	{
		cnt++;
		for (int i = 0; i < size; i++)
		{
			if(a[i]>=max) max=a[i];
		}
		if(cnt==n) {break;}
		for (int i = 0; i < size; i++)
		{
			if(a[i]==max) {a[i]=0;}
		}
		max=a[0];
	}
	return max;
}

int main()
{

	int *a = new int[10]{1, 2, 3, 4, 5, 6, 7, 6, 7, 7};
	int max=FindMaxNth(a,10,2);
	cout<<max<<endl;
}
