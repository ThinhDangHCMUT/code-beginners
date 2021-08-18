#include <iostream>
using namespace std;

int main()
{
    int a[100][100];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j]<<" ";
        cout<<endl;
    }


   int ir, ic;
   int cnt=0;
   int max,min;
   int col,row;

   for(int i=0;i<3;i++)
   {
       max=a[i][0];
       col=0;
       for(ic=0;ic<3;ic++)
       {
           if(a[i][ic]>max)
           {
               max=a[i][ic];
               col=ic;
           }
       }
       min=a[0][col];
       row=0;
       for(ir=0;ir<3;ir++)
       {
           if(a[ir][col]<min)
           {
               min=a[ir][col];
               row=ir;
           }
       }

       if(max==min)
       {
           cnt++;
           cout<<a[row][col];
       }
   }
   cout<<endl;
   cout<<cnt;
}
  
    
