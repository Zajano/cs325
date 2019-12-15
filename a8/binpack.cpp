//Author:     Zack Jaffe-Notier
//date:       Dec 4, 2019
//description: Uses first-fit, first-fit decreasing, and best-fit algorithms to

//STILL GET 0 nanoSECONDS! tested with Sleep() to make sure timing is working, and it is.
//https:https://www.geeksforgeeks.org/merge-sort/
//https://www.techiedelight.com/measure-elapsed-time-program-chrono-library/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <array>
#include <chrono>
#include <unistd.h>
#include <cerrno>
#include <stdlib.h>
//#include <windows.h>

using namespace std;

//basic merge sort
void merge(int arr[], int p, int q, int r)
{
  int i, j, k;
  int n1 = q - p + 1;   //get indexes for middle
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

  //check for larger value to move back into array
  while (i < n1 && j < n2)
  {
    if (Left[i] >= Right[j])
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

//nested loops for each item and each bin
//takes item and bin arrays, length of arrays, and bin size
int firstFit(int iArr[], int bArr[], int len, int bSize)
{
  int i = 0; //for items
  int j = 0; //for bins
  while(j < len)
  {
    if(bArr[j] >= iArr[i])
    {
      bArr[j] -= iArr[i]; //reduce capacity
      if(i < len-1)       //avoid indexing issue
      {
        i++;    //next item
        j = 0;  //back to first bin
      }
      else //end of items
      {
        j = len;
      }
    }
    else
    {
      j++; //next bin
    }
  }

  //see how many bins have reduced capacity
  int numBins = 0;
  while(bArr[numBins] < bSize)
  {
    numBins++;
  }

  return (numBins);
}

int ffDecreasing(int iArr[], int bArr[], int len, int bSize)
{
  //sort items
  mergeSort(iArr, 0, len - 1);
  // for(int i = 0; i < len; i++)
  // {
  //   cout << iArr[i] << " ";
  // }
  return firstFit(iArr, bArr, len, bSize);
  //place items
  // int j=0; //for bins
  // for(int i=0; i < len; i++)
  // {
  //   if(bArr[j] >= iArr[i])
  //   {
  //     bArr[j] -= iArr[i];
  //     cout << "added " << iArr[i] << " to bin " << j << endl;
  //     j = 0;  //back to first bin
  //   }
  //   else  //next bin
  //   {
  //     j++;
  //     bArr[j] -= iArr[i];
  //     cout << "added " << iArr[i] << " to bin " << j << endl;
  //     j = 0
  //   }
  // }
  //
  // for(int i = 0; i < len; i++)
  // {
  //   cout << bArr[i] << " ";
  // }
  //
  // //see how many bins have reduced capacity
  // int numBins = 0;
  // while(bArr[numBins] < bSize)
  // {
  //   numBins++;
  // }
  //
  // return (numBins);
}

int bestFit(int iArr[], int bArr[], int len, int bSize)
{
  int difference = bSize; //between bin capacity and item size
  int index;     //of bin with lowest difference

  for(int i = 0; i < len; i++)
  {
    for(int j = 0; j < len;j++)
    {
      if(difference > bArr[j] - iArr[i] && bArr[j] - iArr[i] >= 0)
      {
        difference = bArr[j] - iArr[i];
        index = j;
      }
    }//after going through all bins, place item where there's the least difference
    bArr[index] -= iArr[i];
    difference = bSize;
  }

  // for(int i = 0; i < len; i++)
  // {
  //   cout << bArr[i] << " ";
  // }

  //see how many bins have reduced capacity
  int numBins = 0;
  while(bArr[numBins] < bSize)
  {
    numBins++;
  }

  return (numBins);
}

int main()
{
  int cases, binSize, numItems, theseBins;
  //clock_t t;                //counting time
  //double seconds;           //for output
  long long timed;
  //tics = CLOCKS_PER_SEC;
  //double millisec = tics/1000;
  //cout << "nano: " << millisec << endl;
  //cout << "tics: " << tics << endl;
  //srand(time(NULL));        //seed with time

  ifstream in("bin.txt");

  in >> cases;

  for(int test = 1; test <= cases; test++)
  {
    //get size of bins to be used and number of items
    in >> binSize;
    in >> numItems;

    //array for items and bins. max bins will = num items
    int itemArr[numItems];
    int binArr[numItems];
    for(int i = 0; i < numItems; i++)
    {
      in >> itemArr[i];
      binArr[i] = binSize;
    }

    //what am i doing there has to be a better way
    int tempItems[numItems];
    int tempBins[numItems];

    for(int i = 0; i < numItems; i++)
    {
      tempItems[i] = itemArr[i];
      tempBins[i] = binArr[i];
    }
    //array<int, numItems> tempItems3 = itemArr;
    //array<int, numItems> tempBins3 = binArr;

    cout << "Test Case " << test << ":" << endl;
    //first-fit
    //t = clock();
    auto start = chrono::steady_clock::now();
    theseBins = firstFit(tempItems, tempBins, numItems, binSize);     //run method
    auto end = chrono::steady_clock::now();
    //t = clock() - t;                                      //get time difference
    timed = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    //seconds = timed / tics;   //clock ticks per second to get actual seconds
    cout << "First-Fit: " << theseBins << " bins in " << timed << " nanoseconds." << endl;

    //reset arrays
    for(int i = 0; i < numItems; i++)
    {
      tempItems[i] = itemArr[i];
      tempBins[i] = binArr[i];
    }
    //first-fit decreasing
    //t = clock();
    start = chrono::steady_clock::now();
    theseBins = ffDecreasing(tempItems, tempBins, numItems, binSize);     //run method
    //Sleep(1);
    end = chrono::steady_clock::now();
    //t = clock() - t;                                      //get time difference
    timed = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    //seconds = timed / tics;   //clock ticks per second to get actual seconds
    cout << "First-Fit Decreasing: " << theseBins << " bins in " << timed << " nanoseconds." << endl;

    //reset arrays
    for(int i = 0; i < numItems; i++)
    {
      tempItems[i] = itemArr[i];
      tempBins[i] = binArr[i];
    }
    //first-fit decreasing
    //t = clock();
    start = chrono::steady_clock::now();
    theseBins = bestFit(tempItems, tempBins, numItems, binSize);     //run method
    //Sleep(1);
    end = chrono::steady_clock::now();
    //t = clock() - t;                                      //get time difference
    timed = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    //seconds = timed / tics;   //clock ticks per second to get actual seconds
    cout << "Best-Fit: " << theseBins << " bins in " << timed << " nanoseconds." << endl;



    cout << endl;
  }//while close

  in.close();
  //cout << "Input from shopping.txt calculated and printed to results.txt" << endl;
  return 0;
}
