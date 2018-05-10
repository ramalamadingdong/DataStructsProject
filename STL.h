#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class Node
{
private:
  int value;
  int sec;
  string dat;

public:
  Node(string d, int p, int s )    {value = p; sec = s; dat = d;}
  int Val() const { return value; }
  int Sec() const {return sec;}
  string f() const {return dat;}

};

struct CompareNode : public std::binary_function<Node*, Node*, bool>
{
  bool operator()(const Node* lhs, const Node* rhs) const
  {
    if (lhs -> Val() == rhs->Val()){
      return lhs->Sec() > rhs->Sec();
    }

    return lhs->Val() > rhs->Val();
  }
};