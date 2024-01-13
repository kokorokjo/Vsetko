#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <string>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, k, l, pomocna, kr;
    cin >> n >> k >> l;
    k--;
    int arr[n], hlavny[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pomocna;
        arr[i] = pomocna;
        hlavny[n] = pomocna;
    }
    kr = arr[k];

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    if (kr != arr[k])
    {
        cout << "nie" << endl;
        return 0;
    }


    return 0;
}

