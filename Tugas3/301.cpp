#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int awal, int akhir, int target) {
    while (awal <= akhir) {
        int tengah = awal + (akhir - awal) / 2;
        if (arr[tengah] == target) {
            return tengah;
        } else if (arr[tengah] < target) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    if (!(cin >> n >> x)) return 0;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    int totalPasangan = 0;

    for (int i = 0; i < n / 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int targetCari = x - arr[i];

        int indeksKetemu = binarySearch(arr, i + 1, n - 1, targetCari);

        if (indeksKetemu != -1) {
            totalPasangan++;
        }
    }

    cout << totalPasangan << endl;

    delete[] arr;
    return 0;
}
