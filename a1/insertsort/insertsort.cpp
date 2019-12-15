//Author:     Zack Jaffe-Notier
//date:       Oct 7, 2019
//description:insert sort algorithm based off of textbook pseudocode

#include <iostream>
#include <cstdlib>
#include <fstream>

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
  //open data.txt and create output
  ifstream in("data.txt");
  ofstream out("insert.txt");

  int n;
  //take input
  while(in >>n ) //number of ints
  {
    //create array
    int *arr = new int[n];
    // reading integers
    int j = 0;
    while(j < n)
    {
      in >> arr[j]; //put ints into array
      j++;
    }

    //sort array
    insertionSort(arr, n);

    //write sorted array to file
    for(int i=0; i<n; i++)
    {
      out << arr[i] << " "; //spaces!
    }

    out << endl;
  }

  in.close();
  out.close();

  cout << "Input from data.txt sorted and printed to insert.txt" << endl;

  return 0;
}
