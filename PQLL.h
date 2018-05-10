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

typedef struct nodeL {
    string data;
    int priority;
    int treat;
    struct nodeL* next;

} NodeL;

class PQLL
{
public:
    PQLL();
    ~PQLL();
    NodeL* newNode(string d, int p, int t);
    void pop(NodeL** head);
    void push(NodeL** head, string d, int p, int t);
    int isEmpty(NodeL** head);

private:
    
};
