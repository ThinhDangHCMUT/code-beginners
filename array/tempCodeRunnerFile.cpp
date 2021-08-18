

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

int checkNguyento(int a[], int 