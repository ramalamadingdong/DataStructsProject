#include "BinaryHeap.h"

PriorityQueue::PriorityQueue()
{
	for(int i = 0; i<maxIndex; i++)
	{
		pQueue[i] = NULL;
	}
}

PriorityQueue::~PriorityQueue()
{
	for(int i = 1; i<lastIndex; i++)
	{
		delete pQueue[i];
	}
}

int PriorityQueue::compare(priorityItem* a, priorityItem* b){
	if(a->primaryPriority < b->primaryPriority){
		return -1;
	}
	if (a->primaryPriority == b->primaryPriority){
		if (a->secondaryPriority < b->secondaryPriority)
			return -1;
	}
return 1;
}

bool PriorityQueue::enqueue(string thingName, int primP, int secP)
{
	//if you wanted to dynamically resize the heap
	if(lastIndex == 0)
	{
		//cout<<"Nothing in queue"<<endl;
	}
	if(lastIndex < maxIndex)
	{
		priorityItem* itemToAdd = new priorityItem;
		itemToAdd->itemName = thingName;
		itemToAdd->primaryPriority = primP;
		itemToAdd->secondaryPriority = secP;
		lastIndex++;
		//put the new thing at last index
		pQueue[lastIndex] = itemToAdd;
		//reheap up
		int currentIndex = lastIndex;
		bool itemSwapped = true;
		while(currentIndex > 1 && itemSwapped)
		{
			//compare thing at current index to parent
			if(compare(pQueue[currentIndex],pQueue[currentIndex/2])== -1){
			//will need to swap
				priorityItem* temp = pQueue[currentIndex/2];
				pQueue[currentIndex/2] = pQueue[currentIndex];
				pQueue[currentIndex] = temp;
				currentIndex = currentIndex/2;
			}

			else
			{
				itemSwapped = false; //binary heap is partially ordered
			}
		}
		return true;
	}
	else
	{	
		//queue is full
		cout<<"Queue is full"<<endl;
		return false;
	}
}

bool PriorityQueue::dequeue()
{
	//check if empty
	if(lastIndex > 0)
	{
		delete pQueue[1];
		//check if priority queue is empty
		if(lastIndex == 1)
		{
			lastIndex = 0;
			pQueue[1] = NULL;

		}
		else
		{
			//set item 1 to thing at end
			pQueue[1] = pQueue[lastIndex];
			//set last thing  = NULL;
			pQueue[lastIndex] = NULL;
			//decrement lastIndex
			lastIndex--;
			//reheap down
			int currentIndex = 1;
			int leftChild, rightChild, largerChild;
			bool itemSwapped = true;
			while(currentIndex < maxIndex && itemSwapped)
			{
				leftChild = currentIndex*2;
				rightChild = currentIndex*2 + 1;
				//check if you're out of bounds
				if(leftChild > lastIndex)
				{
					//no children, so stop
					itemSwapped = false;
				}
				else
				{
					if(rightChild > lastIndex)
					{
						largerChild = leftChild;
					}
					else
					{
						int a = compare(pQueue[leftChild], pQueue[rightChild]);

							if (a == -1)
								largerChild = leftChild;
							if (a == 1)
								largerChild = rightChild;
				
					}
					if(compare(pQueue[currentIndex], pQueue[largerChild]) == 1)
					{
							//swap
						priorityItem* temp = pQueue[largerChild];
						pQueue[largerChild] = pQueue[currentIndex];
						pQueue[currentIndex] = temp;
							//move current index to index of larger child;
						currentIndex = largerChild;
					}
					else
					{
						return false;
					}
				}
				
			}

		}
		return true;
	}
	else
	{
		return false;
	}
}

void PriorityQueue::printPQ()
{
	if(lastIndex == 0)
	{
	}
	else
	{
		for(int i = 1; i<=880; i++)
		{
			cout<<i<<":	"<<pQueue[1]->itemName<<",  "<<pQueue[1]->primaryPriority <<",  "<<pQueue[1]->secondaryPriority<<endl;
			dequeue();
		}
	}
}