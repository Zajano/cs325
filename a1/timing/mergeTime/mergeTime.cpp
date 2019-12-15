//Author:     Zack Jaffe-Notier
//date:       Oct 8, 2019
//description:merge sort timing measurement


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

void merge(int arr[], int p, int q, int r)
{
  int i, j, k;
  int n1 = q - p + 1; //subarray length
  int n2 = r - q;
  int Left[n1], Right[n2];

  //copy array into left
  for (i = 0; i < n1; i++)
  {
    Left[i] = arr[p + i];
  }

  //copy array into right
  for (j = 0; j < n2; j++)
  {
    Right[j] = arr[q + j + 1];
  }

  i = 0;
  j = 0;
  k = p;

  //check for smaller value to move back into array
  while (i < n1 && j < n2)
  {
    if (Left[i] <= Right[j])
    {
      arr[k] = Left[i];
      i++;
    }
    else
    {
      arr[k] = Right[j];
      j++;
    }
    k++;
  }

  //catch leftovers
  while (i < n1)
  {
    arr[k] = Left[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = Right[j];
    j++;
    k++;
  }
}

//sorts elements in the subarray
void mergeSort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = p + (r - p)/2; //index q for partition
    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);
  }
}

int main()
{
  int size;                //how many numbers to sort
  int num;                //number to add to array
  clock_t t;              //counting time
  double seconds;         //for output
  double tics, timed;      //tics per second
  tics = CLOCKS_PER_SEC;
  srand(time(NULL));      //seed with time
  int choice;

  cout << " start:1, stop:2" << endl;
  cin >>choice;
  while(choice != 2)
  {
    cout << "How big is the array to be sorted?" << endl;
    cin >> size;

    int arr[size];

    for(int i = 0; i < size; i++)
    {
      num = 1 + rand() % 10000;
      arr[i] = num;
    }
    //testing to see is array generation actually worked
    //cout << "unsorted array: " <<endl;
    //for(int i = 0; i <size; i++)
    //{
    //  cout << arr[i] << " ";
    //}

    t = clock();
    mergeSort(arr, 0, size - 1);     //run method
    t = clock() - t;                 //get time difference
    timed = t;
    seconds = timed / tics;   //clock ticks per second to get actual seconds
    cout << "Merge method took " << seconds << " seconds to sort " << size << " numbers." << endl;

    //cout << "sorted array: " <<endl;
    //for(int i = 0; i <size; i++)
    //{
    //  cout << arr[i] << " ";
    //}
    cout << "run again? 1- yes, 2- no" << endl;
    cin >> choice;
  }

  return 0;
}
