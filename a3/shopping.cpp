//Author:     Zack Jaffe-Notier
//date:       Oct 21, 2019
//description: shopping spree algo based off knapsack DP in lecture
// additional resources:
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://www.geeksforgeeks.org/printing-items-01-knapsack/
// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int[], int[], int, int, vector<int>&);
int max(int, int);

int main()
{
  //variables laid out by 4c
  int T;       //test cases (1 <= T <= 100)
  int N;       //items (1 <= N <= 100)
  int P[100];  //array for prices of items, max 100
  int W[100];  //array for weights of items, max 100
  int F;       //number of people in the family (1 <= F <= 30)
  int M;       //maximum weight that can be carried
  vector<vector<int> > itemsVec(100); //store items of each family member

  ifstream in("shopping.txt");
  ofstream out("results.txt");

  out << "Zack Jaffe-Notier" << endl << "Oct 21, 2019" << endl << "Shopping results" << endl << endl;

  //get number of test cases from first line for testing loop
  in >> T;
  for (int i = 0; i < T; i++)
  {
    itemsVec.clear(); //erase previous test...

    //cout << itemsVec.empty();
    //get number of items for product info loop
    in >> N;
    //product info loop getting price and weight from each line
    for (int j = 0; j < N; j++)
    {
      in >> P[j];
      in >> W[j];
    }

    //track total value of products carried by family
    int totalValue = 0;

    //get number of family members for knapsack loop
    in >> F;
    for (int j = 0; j < F; j++)
    {
      //get weight that can be carried by current family member
      in >> M;
      //knapsack + vector of current family member
      totalValue = totalValue + knapsack(W, P, N, M, itemsVec[j]);
    }

    out << "Test Case " << i+1 << endl;
    out << "Total Price: " << totalValue << endl;
    out << "Member Items" << endl;

    for (int j = 0; j < F; j++)                 //loop for each family member
    {
      sort(itemsVec[j].begin(), itemsVec[j].end());   //sort items for member
      out << '\t' << j + 1 << ": ";                   //member number
      int isize = itemsVec[j].size();                 //for comparison to k
      for (int k = 0; k < isize; k++)                 //loop for items
      {
        out << itemsVec[j][k] << " ";
      }
      out << endl;
    }
  }

  in.close();
  out.close();
  cout << "Input from shopping.txt calculated and printed to results.txt" << endl;
  return 0;
}

//returns max value of items that can be carried by a family member
//Weight[] of items, Price[] of items, Number of items, Max weight to carry, items vector
int knapsack(int W[], int P[], int N, int M, vector<int> &vecItems)
{
  //2d array, number of items x max weight for family member
  //+1 to get directory to match with item number/weight
  //must do -1 in W[] and P[] calls to compensate
  int sack[N+1][M+1];
  vecItems.clear(); //clear here! why didn't this work in the higher test loop?

  for (int i = 0; i <= N; i++) //for all items
  {
    for (int w = 0; w <= M; w++) //for all weights
    {
      if (i == 0 || w == 0) //fill first row and column with 0
        {sack[i][w] = 0;}
      else if (W[i-1] <= w) //if weight of item is less than weight available
      {
        int temp1 = P[i-1] + sack[i - 1][w - W[i-1]]; //this price + max lower
        int temp2 = sack[i - 1][w]; //lower item with current weight
        sack[i][w] = max(temp1, temp2);
      }
      else //same as lower solution
        {sack[i][w] = sack[i - 1][w];}
    }//end weight loop
  }//end item loop

  //add items to vector for member to print
  int results = sack[N][M];
  int weight = M;
  for (int i = N; i > 0 && results > 0; i--) //start at the end
  {
    if (weight > 0)
    {
      if (results == sack[i - 1][weight]) //same as last item, not included
        continue;
      else //is included
      {
        vecItems.push_back(i);  //save item number in member vector
        results = results - P[i - 1];    //deduct current value from total
        weight = weight - W[i - 1];     //deduct current weight from remaining weight
      }
    }
  }
  return sack[N][M]; //maximum value for weight carried by member
}

//returns larger value for sack
int max(int a, int b)
{
  if (a > b)
    {return a;}
  else //even if they're identical
    {return b;}
}
