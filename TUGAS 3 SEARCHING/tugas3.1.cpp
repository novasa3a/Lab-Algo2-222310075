#include <iostream>

using namespace std;

int BinarySearch(int arr[], int lowValue, int highValue, int search);
void BubbleSort(int arr[], int size);

int main() {
  int arr[5] = {0, 6, 12, 18, 24};
  int lowValue = 0;
  int search;

  int size = sizeof(arr) / sizeof(arr[0]);
  int highValue = size - 1;

  cout << "\n ";

  BubbleSort(arr, size);

  while (lowValue < size) {
    cout << arr[lowValue] << " ";
    lowValue++;
  }

  lowValue = 0;

  cout << endl;
  cout << "\nMasukkan Bilangan yang akan dicari: ";
  cin >> search;

  int resultSearch = BinarySearch(arr, lowValue, size - 1, search);

  if (resultSearch == -1) {
    cout << "Nilai tidak ditemukan! \n";
  } else {
    cout << "Nilai ditemukan pada indeks ke - " << resultSearch << endl;
  }
}

int BinarySearch(int arr[], int lowValue, int highValue, int search) {
  while (lowValue <= highValue) {
    int midValue = lowValue + (highValue - lowValue) / 2;

    if (arr[midValue] == search) {
      return midValue;
    } else if (arr[midValue] < search) {
      lowValue = midValue + 1;
    } else {
      highValue = midValue - 1;
    }
  }
  return -1;
}

void BubbleSort(int arr[], int size) {
  bool isSort = false;
  int tempValue;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tempValue = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tempValue;

        isSort = true;
      }
    }

    if (isSort == false) {
      break;
    }
  }
}