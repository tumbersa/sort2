#include <iostream>
using namespace std;

void print(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
}

void merge(int* A, int* B, int p, int q, int r, bool flag) {
    cout << "Before" << endl;
    int j = p;
    for (int i = 0; i < r - p + 1; i++) {
        cout << A[j] << " ";
        j++;
    }

    cout << endl;
    
    int in_pos1 = p;
    int in_pos2 = q + 1;
    int out_pos = 0;
    while (in_pos1 <= q && in_pos2 <= r) {
        if ((A[in_pos1] < A[in_pos2] && flag == 0) || (A[in_pos1] > A[in_pos2] && flag == 1)) {
            B[out_pos++] = A[in_pos1++];
        }
        else B[out_pos++] = A[in_pos2++];
    }
    while (in_pos1 <= q)
        B[out_pos++] = A[in_pos1++];
    while (in_pos2 <= r) 
        B[out_pos++] = A[in_pos2++];
    for (int i = 0; i < r - p + 1; i++) {
        A[p + i] = B[i];
    }
    cout << "After" << endl;
    j = p;
    for (int i = 0; i < r - p + 1; i++) {
        cout << A[j] << " ";
        j++;
    }
    cout << endl;
}
void mergeSort(int* A, int* B, int p, int r, bool flag) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, B, p, q, flag);
        mergeSort(A, B, q + 1, r, flag);
        merge(A, B, p, q, r, flag);
    }
}
int main() {
    int arr[] = { 12, 34, 54, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);



    cout << "Array before sorting: \n";
    print(arr, n);
    cout << endl;
    int* b = new int[n];
    mergeSort(arr, b, 0,n-1,false);

    cout << "\nArray after sorting: \n";
    print(arr, n);

    return 0;
}