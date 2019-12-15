//Author:     Zack Jaffe-Notier
//date:       Oct 15, 2019
//description: stooge sort algorithm based off of HW2 #3


#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//take array and index locations
void stoogeSort(int arr[], int first, int last)
{
  //length of array portion being checked
  int size = last - first+1;

	//check array size for swap of first and last
	if (size < 3)
	{
		if (arr[first] > arr[last])
		{
			int temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
		}
    return; //escape
	}

  //get 1/3 size of array
	int third = size/3;

	//sort the first 2/3rd
	stoogeSort(arr, first, last - third);

	//sort second 2/3rd
	stoogeSort(arr, first + third, last);

	//sort first 2/3 again
	stoogeSort(arr, first, last - third);

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
      //  cout << "unsorted array: " <<endl;
      //    for(int i = 0; i <size; i++)
      //      {
      //          cout << arr[i] << " ";
      //      }

    t = clock();
    stoogeSort(arr, 0, size - 1);     //run method
    t = clock() - t;                 //get time difference
    timed = t;
    seconds = timed / tics;   //clock ticks per second to get actual seconds
    cout << "Stoogesort took " << seconds << " seconds to sort " << size << " numbers." << endl;

    //testing to see is array sorting actually worked
    //  cout << "sorted array: " <<endl;
    //    for(int i = 0; i <size; i++)
    //      {
    //          cout << arr[i] << " ";
    //      }

    cout << "run again? 1- yes, 2- no" << endl;
    cin >> choice;
  }

  return 0;
}
