#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int temp[100];

    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}