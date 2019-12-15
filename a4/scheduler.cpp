//Author:     Zack Jaffe-Notier
//date:       Oct 28, 2019
//description: max activity scheduler using start and stop times

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//for data given in act.txt
struct Activity{
  int num;
  int start;
  int finish;
};

//bubble sort for simplicity
void swap(Activity *x, Activity *y)
{
    Activity temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(Activity arr[], int size)
{
    for (int i = 0; i < size-1; i++)
      for (int j = 0; j < size-i-1; j++)
          if (arr[j].start > arr[j+1].start)
              swap(&arr[j], &arr[j+1]);
}


int main()
{
  int acts;            //number of activities
  int set = 1;         //which set is being compared
  //int numActs;       //how many activities are selected
  int setStart;        //compare to finish times
  vector<int> chosen;  //track chosen activities

  ifstream in("act.txt");

  //eof since there's no given N for sets to review
  while (!in.eof())
  {
    //reset number of activities
    chosen.clear();

    //create array of activities of proper size
    in >> acts;
    Activity actArr[acts];

    //get attributes for activities
    for (int i = 0; i < acts; i++)
    {
      in >> actArr[i].num;
      in >> actArr[i].start;
      in >> actArr[i].finish;
    }

    bubbleSort(actArr, acts);

    cout << "Set " << set << endl;
    set++;

    //will always add last activity in array
    setStart = actArr[acts-1].start;
    chosen.push_back(actArr[acts-1].num);

    //start from next-to-last activity
    for(int i = acts-2; i >= 0; i--)
    {
      //see if it's compatible with latest start time
      if(actArr[i].finish <= setStart)
      {
        chosen.push_back(actArr[i].num);
        setStart = actArr[i].start;
      }
    }

    cout << "Number of activities selected: " << chosen.size() << endl;
    cout << "Activities: ";
    int cSize = chosen.size();
    for(int i=0;i < cSize; i++)
        cout << chosen[i] << ' ';

    cout << endl;
  }//while close

  in.close();
  //cout << "Input from shopping.txt calculated and printed to results.txt" << endl;
  return 0;
}
