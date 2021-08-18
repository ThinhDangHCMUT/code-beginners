#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

#define MAX 1000

void EnterMatrix(int **a, int d, int c)
{
    for (int i = 0; i < d; i++)
        for (int j = 0; j < c; j++)
            // a[i][j]=-100+ rand()% 201;
            cin >> a[i][j];
}
void ExportMatrix(int **a, int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Left(int **a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            if (a[i][j] > 0)
                cnt++;
    }
    cout << "The number of positive element of 2D-Matrix is: " << cnt << endl;
}

void SumofBorder(int **a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + a[i][0] + a[i][n - 1];
    }
    for (int i = 1; i < n - 1; i++)
    {
        s = s + a[0][i] + a[n - 1][i];
    }
    cout << "The sum of the border of 2D-Matrix is: " << s << endl;
}

void YenNgua(int **a, int n)
{
    int icol, irow;
    int max, min;
    int col, row;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        max = a[i][0];
        col = 0;
        for (icol = 0; icol < n; icol++)
        {
            if (a[i][icol] > max)
            {
                max = a[i][icol];
                col = icol;
            }
        }
        min = a[0][col];
        row = 0;
        for (irow = 0; irow < n; irow++)
        {
            if (a[i][col] < min)
            {
                min = a[i][col];
                row = irow;
            }
        }
        if (max == min)
        {
            cnt++;
        }
    }
    cout << a[row][col] << " " << cnt << endl;
}

void checkQueen(int **a, int d, int c)
{
    int irow, icol;
    int maxr, maxc, maxcheo1, maxcheo2;
    int col, row;
    int Max;
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < d; i++)
    {
        maxr = a[i][0];
        col = 0;
        for (int icol = 0; icol < c; icol++)
        {
            if (maxr < a[i][icol])
            {
                maxr = a[i][icol];
                col = icol;
            }
        }
        maxc = a[0][col];
        for (int irow = 0; irow < d; irow++)
        {
            if (maxc < a[irow][col])
            {
                maxc = a[irow][col];
                row = irow;
            }
        }
        if (maxc == maxr)
        {
            maxcheo2 = maxcheo1 = maxc;
            //check the first diagonal
            //row-up col-down
            int rowPos = row + 1;
            int colPos = col - 1;
            while (rowPos < d && colPos >= 0)
            {
                if (a[rowPos][colPos] > maxcheo1)
                {
                    maxcheo1 = a[rowPos][colPos];
                }
                rowPos++;
                colPos--;
            }
            //row-down col-up
            rowPos = row - 1;
            colPos = col + 1;
            while (rowPos >= 0 && colPos < c)
            {
                if (a[rowPos][colPos] > maxcheo1)
                {
                    maxcheo1 = a[rowPos][colPos];
                }
                rowPos--;
                colPos++;
            }
            //check the second diagonal
            //row-up col-up
            rowPos = row + 1;
            colPos = col + 1;
            while (colPos < c && rowPos < d)
            {
                if (a[rowPos][colPos] > maxcheo2)
                {
                    maxcheo2 = a[rowPos][colPos];
                }
                rowPos++;
                colPos++;
            }
            //row-down col-down
            rowPos = row - 1;
            colPos = col - 1;
            while (colPos >= 0 && rowPos >= 0)
            {
                if (a[rowPos][colPos] > maxcheo2)
                {
                    maxcheo2 = a[rowPos][colPos];
                }
                rowPos--;
                colPos--;
            }
            if (maxcheo1 == maxcheo2)
            {
                cnt++;
                cout << maxcheo1 << " ";
            }
        }
    }
    cout << endl;
    cout << "The number of queen element in array 2D: " << cnt << endl;
}

void checkMaxPoint(int **a, int d, int c)
{
    int max;
    int check = 0;
    int cnt = 0;
    int irow, icol;
    for (irow = 0; irow < d; irow++)
    {
        for (icol = 0; icol < c; icol++)
        {
            max = a[irow][icol];
            if (irow == 0 && icol == 0)
            {
                if (a[irow + 1][icol] < max && a[irow][icol + 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == d - 1 && icol == c - 1)
            {
                if (a[irow - 1][icol] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == d - 1 && icol == 0)
            {
                if (a[irow - 1][icol] < max && a[irow][icol + 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == 0 && icol == c - 1)
            {
                if (a[irow + 1][icol] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == d - 1 && icol == 0)
            {
                if (a[irow - 1][icol] < max && a[irow][icol + 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == 0 && icol > 0 && icol < c - 1)
            {
                if (a[irow + 1][icol] < max && a[irow][icol + 1] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow == d - 1 && icol > 0 && icol < c - 1)
            {
                if (a[irow - 1][icol] < max && a[irow][icol + 1] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow < d - 1 && irow > 0 && icol == 0)
            {
                if (a[irow + 1][icol] < max && a[irow - 1][icol] < max && a[irow][icol + 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow < d - 1 && irow > 0 && icol == c - 1)
            {
                if (a[irow + 1][icol] < max && a[irow - 1][icol] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }
            if (irow < d - 1 && irow > 0 && icol < c - 1 && icol > 0)
            {
                if (a[irow + 1][icol] < max && a[irow - 1][icol] < max && a[irow][icol + 1] < max && a[irow][icol - 1] < max)
                    check = 1;
                else
                    check = 0;
            }

            if (check)
                cnt++;
        }
    }

    cout << "The maxpoint members are: " << cnt << endl;
}

bool Checkchinhphuong(int a)
{
    for (int i = 1; i <= a; i++)
    {
        if (i * i == a)
            return true;
    }
    return false;
}

void CPMatrix(int **a, int d, int c)
{
    int posx, posy;
    for (int i = 1; i < d; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Checkchinhphuong(a[i][j]))
            {
                if (a[i][j] == a[j][i])
                {
                    cout << "Positon: " << i << j << endl;
                }
            }
        }
    }
}

void rotate90(int **a, int **b, int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            b[i][j] = a[j][d - 1 - i];
        }
    }
}

void rotate180(int **a, int **b, int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            b[i][j] = a[d - 1 - i][j];
        }
    }
}

void rotate270(int **a, int **b, int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            b[i][j] = a[d - 1 - j][d - 1 - i];
        }
    }
}

void mul2Matrix(int **a, int **b, int **m, int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = 0;
            for (int k = 0; k < c; k++)
            {
                m[i][j] = m[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

void AsubB(int **a, int **b, int arow, int acol, int brow, int bcol)
{
    int max = 0;
    int s = 0;
    // bool flag;

    for (int iArow = 0; iArow <= arow - brow; iArow++)
    {
        for (int iAcol = 0; iAcol <= acol - bcol; iAcol++)
        {
            for (int i = 0; i < brow; i++)
            {
                for (int j = 0; j < bcol; j++)
                {
                    s += a[iArow + i][iAcol + j];
                }
            }
            if (s >= max)
            {
                max=s;
                for (int i = 0; i < brow; i++)
                {
                for (int j = 0; j < bcol; j++)
                {
                    b[i][j]= a[iArow + i][iAcol + j];
                }
                }
                s=0;   // update the value of "s" variable 
                
            }
        }
    }

    cout << "The equal is: " << max << endl;
}

int main()
{
    int d;
    int c;
    cout << "Enter the row of array2D: ";
    cin >> d;
    cout << endl;
    cout << "Enter the col of array2D: ";
    cin >> c;
    cout << endl;
    //Declare array a
    int **a = new int *[d];
    for (int i = 0; i < d; i++)
        a[i] = new int[c];
    //Declare array b
    int **b = new int *[d];
    for (int i = 0; i < d; i++)
        b[i] = new int[c];
    //Declare array m
    int **m = new int *[d];
    for (int i = 0; i < d; i++)
        m[i] = new int[c];
    EnterMatrix(a, d, c);
    ExportMatrix(a, d, c);
    // Left(a, n);
    // SumofBorder(a, n);
    // EnterMatrix(b,d,c);
    // ExportMatrix(b,d,c);
    // YenNgua(a, n);
    //checkQueen(a,d,c);
    // checkMaxPoint(a, d, c);
    // CPMatrix(a,d,c);
    //rotate90(a,b,d,c);
    //rotate180(a,b,d,c);
    // rotate270(a,b,d,c);
    // ExportMatrix(b, d, c);
    // mul2Matrix(a,b,m,d,c);
    // ExportMatrix(m,d,c);
    
    cout << "-----------------" << endl;
    AsubB(a, b, d, c, 2, 2);
    ExportMatrix(b, 2, 2);


for(int i=0;i<d;i++)
delete [] a[i];
delete [] a;
a=nullptr;
    return 0;
}