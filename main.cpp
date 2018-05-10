#include "BinaryHeap.cpp"
#include "STL.h"
#include "PQLL.cpp"

int main(int argc, char *argv[]){

	int choice;

	/////////////////////
	////Read CSV File////
	/////////////////////

	ifstream handle;
	handle.open(argv[1]);

	string name[881];
	int Priority[881];
	int Treat[881];
	int counter = 0;

	string line;
	string word;

	getline(handle, line, '\r');

	while(getline(handle, line, '\r')) {

		stringstream sp(line);

		istringstream ss(line);
		string token;
		int cnt = 0;

		while(getline(ss, token, ',')) {
			cnt++;
			if (cnt == 1){
				name[counter] = token;
			}
			else if (cnt == 2){
				int temp = stoi(token);
				Priority[counter] = temp;
			}
			else if (cnt == 3){
				int temp = stoi(token);
				Treat[counter] = temp;
				cnt = 0;
			}
		}
		counter++;
	}

	handle.close();

	while(true){

		cout<<"1. Run Runtime Analysis \n2. Enqueue and Dequeue Binary Heap: \n3. Enqueue and Dequeue STL\n4. Enqueue and Dequeue LL\n5. Quit";

		cout<<"\nEnter your choice: ";

		cin>>choice;

		switch(choice){

			case 1:
			{
				ofstream myfile;
				myfile.open ("dataHeap.csv");

				myfile << "Run Num , Analysis Time, Binary Heap\n";

				PriorityQueue pq;

				clock_t t1, t2;

				for (int NumPat = 100; NumPat < 880; NumPat = NumPat +100){

					myfile << "Run Num , Analysis Time,";
					myfile << to_string(NumPat)+",";
					myfile << "\n";

					for (int k = 0; k < 500; k++){
						t1 = clock();
						for (int i = 0; i < NumPat; i++){
							pq.enqueue(name[i], Priority[i], Treat[i]);
						}

						for(int i = 0; i<=NumPat; i++){
							pq.dequeue();
						}
						t2 = clock();

						myfile << to_string(k)+",";
						myfile << to_string((((float)t2-(float)t1) / CLOCKS_PER_SEC)*1000)+",";
						myfile << "\n";
						cout << k << " | Run time Heap: " << (((float)t2-(float)t1) / CLOCKS_PER_SEC)*1000 << " MillSec"<< endl;	
					}
				}
				myfile.close();

///////////////////
///// STL PQ///////
///////////////////	

				ofstream myfileSTL;
				myfileSTL.open ("dataSTL.csv");

				priority_queue<Node*,vector<Node*>, CompareNode > pq_STL;

				clock_t t3, t4;

				for (int NumPat = 100; NumPat < 880; NumPat = NumPat +100){

					myfileSTL << "Run Num , Analysis Time,";
					myfileSTL << to_string(NumPat)+",";
					myfileSTL << "\n";

					for (int k = 0; k < 500; k++){
						t3 = clock();
						for (int i = 0; i < NumPat; i++){
							pq_STL.push(new Node(name[i], Priority[i], Treat[i]));
						}
						int i =0;
						while (!pq_STL.empty()){
							Node* n = pq_STL.top();
							pq_STL.pop();
							i++;
							delete n;
						}
						t4 = clock();

						myfileSTL << to_string(k)+",";
						myfileSTL << to_string((((float)t4-(float)t3) / CLOCKS_PER_SEC)*1000)+",";
						myfileSTL << "\n";
						cout << k << " | Run time STL: " << (((float)t4-(float)t3) / CLOCKS_PER_SEC)*1000 << " MillSec"<< endl;	
					}
				}

/////////////////////
//////PQLL Runtime Ana///////////
/////////////////////	
				PQLL pq_LL;

				ofstream myfileLL;
				myfileLL.open ("dataLL.csv");

				clock_t t5, t6;

				for (int NumPat = 100; NumPat < 880; NumPat = NumPat +100){

					myfileLL << "Run Num , Analysis Time,";
					myfileLL << to_string(NumPat)+",";
					myfileLL << "\n";

					for (int k = 0; k < 500; k++){
						t5 = clock();
						NodeL* pqL = pq_LL.newNode(name[0], Priority[0], Treat[0]);

						for (int i = 1; i < NumPat; i++){
							pq_LL.push(&pqL, name[i], Priority[i], Treat[i]);
						}
						while (!pq_LL.isEmpty(&pqL)) {
							pq_LL.pop(&pqL);
						}			
						t6 = clock();

						myfileLL << to_string(k)+",";
						myfileLL << to_string((((float)t6-(float)t5) / CLOCKS_PER_SEC)*1000)+",";
						myfileLL << "\n";
						cout << k << " | Run time LL: " << (((float)t6-(float)t5) / CLOCKS_PER_SEC)*1000 << " MillSec"<< endl;	
					}
				}
			}

			break;

			case 2:{
				PriorityQueue pq;

				for (int i = 0; i < 880; i++){
					pq.enqueue(name[i], Priority[i], Treat[i]);
				}
				cout << endl;
				cout << "Rank	patient,  Priority,  Treatment\n";
				pq.printPQ();
			}

			break;

			case 3:{
				priority_queue<Node*,vector<Node*>, CompareNode > pq_STL;

				for (int i = 0; i <= 880; i++){
					pq_STL.push(new Node(name[i], Priority[i], Treat[i]));
				}
				int i =1;
				pq_STL.pop();
				cout << endl;
				cout << "Rank	patient,  Priority,  Treatment\n";
				while (!pq_STL.empty()){
					Node* n = pq_STL.top();
					pq_STL.pop();
					cout<<i<<":\t"<<n->f()<<",  "<<n -> Val() <<",  "<<n->Sec()<<endl;
					delete n;
					i++;
				}

			}
			break;
			case 4:{
				PQLL pq_LL;

				NodeL* pqL = pq_LL.newNode(name[0], Priority[0], Treat[0]);

				for (int i = 1; i <= 880; i++){
					pq_LL.push (&pqL, name[i], Priority[i], Treat[i]);
				}

			pq_LL.pop(&pqL);

			cout << endl;
			cout << "Rank	patient,  Priority,  Treatment\n";

				int i = 1;
				while (!pq_LL.isEmpty(&pqL)){
					cout<<i<<":\t"<<pqL->data<<",  "<<pqL->priority <<",  "<<pqL->treat<<endl;
					pq_LL.pop(&pqL);
					i++;
				}			
			}

			break;
			case 5:

			exit(0);

			break;

			default:

			cout<<"\nInvalid Input. Try again! \n";

			break;
		}
	}

}