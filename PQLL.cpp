#include "PQLL.h"

PQLL::PQLL(){
}

PQLL::~PQLL(){

}


// Function to Create A New NodeL
NodeL* PQLL::newNode(string d, int p, int t)
{
    NodeL* temp = new NodeL;
    temp->data = d;
    temp->treat = t;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Removes the element with the
// highest priority form the list
void PQLL::pop(NodeL** head)
{
    NodeL* temp = *head;
    (*head) = (*head)->next;
    delete(temp);
}

// Function to push according to priority

void PQLL::push(NodeL** head, string d, int p, int t){

    NodeL* start = (*head);
    // Create new NodeL
    NodeL* temp = newNode(d, p, t);

    if ((*head)->priority >= p){
        if ((*head)->priority == p){
            if ((*head)->treat > t){
                temp->next = (*head);
                (*head) = temp;
            }
            else{
                temp -> next = (*head) -> next;
                (*head)->next = temp;
            }
        }
        else {
            temp->next = *head;
            (*head) = temp;
        }
    }

    else{
        bool end = false;

        while (start->next != NULL && start->next->priority < p && end == false){
            start = start->next;
        }    
        while (start -> next != NULL && start -> next -> priority == p && end == false && start -> next -> treat < t){

            if (start -> next -> priority > p){
                end = true;
                break;           
            }
            start = start -> next;

        }           

        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int PQLL::isEmpty(NodeL** head)
{
    return (*head) == NULL;
}
