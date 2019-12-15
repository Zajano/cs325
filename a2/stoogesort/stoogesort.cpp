//Author:     Zack Jaffe-Notier
//date:       Oct 15, 2019
//description: stooge sort algorithm based off of HW2 #3


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
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
	ifstream in("data.txt");
	ofstream out("stooge.txt");

  int size;

  //take input for size of array
	while(in >> size)
	{
    //create array of size
		int *arr = new int[size];

		//get elements from array
		int j = 0;
		while(j < size)
		{
			in >> arr[j];
			j++;
		}

		//Sorting array
		stoogeSort(arr, 0, size-1);

		//print to file
		for (int i = 0; i < size; i++)
		{
			out << arr[i] << " ";
		}

		out << endl;

		//delete array!
		delete[] arr;
	}

	in.close();
	out.close();

  cout << "Input from data.txt sorted and printed to stooge.txt" << endl;

	return 0;
}
