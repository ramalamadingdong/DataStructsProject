#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <strings.h>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct priorityItem
{
	string itemName;
	int primaryPriority;
	int secondaryPriority;
};

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	int compare(priorityItem*, priorityItem*);
	bool enqueue(string, int, int);
	bool dequeue();
	void printPQ();


private:
	int lastIndex = 0;
	int maxIndex = 880;
	priorityItem* pQueue[880];
};
