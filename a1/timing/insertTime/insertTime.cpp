//Author:     Zack Jaffe-Notier
//date:       Oct 8, 2019
//description:insert sort timing measurement

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

//Insertion Sort function start
void insertionSort(int arr[], int n)
{
  int key, j, i; //variables from pseudocode

  //n will be array length
  for (i = 1; i < n; i++)
  {
    key = arr[i]; //value to check
    j = i - 1;

    //if j-spot is greater than key, move forward
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
} //insertion sort end

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
    insertionSort(arr, size);     //run method
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
