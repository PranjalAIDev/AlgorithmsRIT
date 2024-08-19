#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;


void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}


int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void generateRandomNumbers(vector<int> &arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

   
    char choice;
    cout << "Do you want to enter the elements manually? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    } else {
        generateRandomNumbers(arr, n);
        cout << "Generated random elements: ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken by Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
