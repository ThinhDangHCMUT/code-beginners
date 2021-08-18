#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{

    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    char tmp, tmp1;

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1'))
        {
            if (i == 0)
            {
                if (tmp == '1')
                {
                    s3 += "01";
                }
                else
                    s3 += '1';
            }
            else
            {
                if (tmp == '1')
                {
                    s3 += '0';
                }
                else
                {
                    s3 += '1';
                }
            }
        }

        if (s1[i] == '0' && s2[i] == '0')
        {
            if (tmp == '1')
            {
                s3 += '1';
                tmp = '0';
            }
            else
            {
                s3 += '0';
            }
        }

        if (s1[i] == '1' && s2[i] == '1')
        {
            if (i == 0)
            {
                if (tmp == '1')
                {
                    s3 += "11";
                }
                else
                    s3 += "01";
                break;
            }
            if (i == s1.length() - 1)
            {
                s3 += '0';
                tmp = '1';
            }
            else
            {
                if (tmp == '1')
                {
                    s3 += '1';
                }
                else
                {
                    s3 += '0';
                    tmp = '1';
                }
            }
        }
    }

    string s4;
    for (int i = s3.length() - 1; i >= 0; i--)
    {
        s4 += s3[i];
    }

    cout << s4;
    return 0;
}