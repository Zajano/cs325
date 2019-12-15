//Author:     Zack Jaffe-Notier
//date:       Nov 11, 2019
//description: compares wrestler rivalries to see if they can all team up without conflicting interests

//resources: All dfs, even though it ended up DFS recursive
//https://www.techiedelight.com/breadth-first-search/
//https://www.techiedelight.com/determine-given-graph-bipartite-graph-using-dfs/
//https://iq.opengenus.org/bipartite-checking-dfs/
//http://www.cplusplus.com/forum/beginner/65834/
//https://www.geeksforgeeks.org/memset-in-cpp/
//https://www.geeksforgeeks.org/bipartite-graph/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

//universal variables
//need to initialize since there are no classes
vector<int> adjacents[999];  //array of vectors for rivalries/adjacencies
int color[999];             //for 'coloring' nodes
bool visited[999];           //to check if wrestler was already visited

//Depth First Search function to check for bipartite graph
bool dfs(int current, int parent)
{
  visited[current] = true; //mark current as visited
  color[current] = 1 - color[parent]; //makes current 0 or 1 'color'

  //go through adjacency vectors
  int neighbor; //for index value of neighbor
  for (int i = 0; i < adjacents[current].size(); i++)
  {
    neighbor = adjacents[current][i]; //get adjacent
    if (visited[neighbor] == 0)      //check if visited
    {
      dfs(neighbor, current);      //run dfs with current as parent
    }
    else //check neighbor color vs current color
    {
      if (color[neighbor] == color[current])
      {
        return false; //same color, not possible
      }
    }
  }
   return true; //no matching values between neighbors
}

int main(int argc, char * args[])
{
  ifstream infile(args[1]);

  //get number of names and store in map with names as keys
  int numNames;
  string wrestlerName;
  map<string, int> wrestlers;
  infile >> numNames;
  string names[numNames];
  for (int i = 0; i < numNames; i++)
  {
    infile >> wrestlerName;       //get name
    wrestlers[wrestlerName] = i;  //assign value
    names[i] = wrestlerName;      //put name at index value
  }

  //get number of rivalries and store in adjacency matrix
  int numRivals;
  string name1, name2;
  int index1, index2;
  infile >> numRivals;
  for (int i = 0; i < numRivals; i++)
  {
    infile >> name1 >> name2;

    //get index values from wrestler names
    index1 = wrestlers[name1];
    index2 = wrestlers[name2];

    //add each index as adjacent to each others' vectors
    adjacents[index1].push_back(index2);
    adjacents[index2].push_back(index1);
  }

  //start all wrestlers as heels (0) and nodes as not visited (0)
  memset(color, 0, sizeof color);
  memset(visited, 0, sizeof visited);


  //perform dfs for each wrestler
  bool possible = 1; //track for dfs return
  for (int i = 0; i < numNames; i++)
  {
    //if wrestler has already been checked, skip
    if (visited[i] == 0)
    {
      possible = dfs(i, 0);
    }
    //check if dfs returned false, end if not possible
    if (possible == false)
    {
      cout << "Not possible." << endl;
      break;
    }
  }

  //print names if it is possible
  if (possible == true)
  {
    cout << "Yes" << endl << "Babyfaces: ";

    //print babyfaces
    for (int i = 0;i < numNames;i++)
    {
      if (color[i] == 1)
        cout << names[i] << " ";
    }
    cout << endl << "Heels: ";

    //print heels
    for (int i = 0;i < numNames;i++)
    {
      if (color[i] == 0)
        cout << names[i] << " ";
    }
    cout << endl;
  }

  infile.close();
  return 0;
}
