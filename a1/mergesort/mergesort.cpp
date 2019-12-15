//Author:     Zack Jaffe-Notier
//date:       Oct 7, 2019
//description:merge sort algorithm based off of textbook pseudocode


#include <iostream>
#include <cstdlib>
#include <fstream>

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
  //open data.txt and create output
  ifstream in("data.txt");
  ofstream out("merge.txt");

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
    mergeSort(arr, 0, n - 1);

    for(int i=0; i<n; i++)
    {
      out << arr[i] << " "; //spaces!
    }

    out << endl;
  }

  in.close();
  out.close();

  cout << "Input from data.txt sorted and printed to merge.txt" << endl;

  return 0;
}
