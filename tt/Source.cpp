#include <iostream>
using namespace std;

void print(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
}

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            
            int temp = arr[i];

           
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                print(arr, n);
            }
            print(arr, n);
            arr[j] = temp;
        }
        print(arr, n);
    }
    return 0;
}
int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    
    int gap = n;

  
    bool swapped = true;

    
    while (gap != 1 || swapped == true)
    {
        
        gap = getNextGap(gap);

        
        swapped = false;

        
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
            print(a, n);
        }
    }
}
void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
        print(arr, n);
    }
    return;
}
int main() {
    int arr[] = { 12, 34, 54, 2, 3 }, i;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: \n";
    print(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    print(arr, n);

    return 0;
}