#include <iostream>
using namespace std;

#define DATA_SIZE 30

/////////////////////////////////////////////////////////////////////////////////////////////

class Node{
friend class LinkedList;
	/* private members */
private:
	int id;
	float data[DATA_SIZE];
	Node *nextNodePtr;
public:
	/* add further methods here */
	Node(void);
	~Node(void);
	void printForTest(void);
};

Node::Node(void){
	cout << "NODE -------- Node has been created ---------" << endl;
//	int index;
//	for(index=0; index<DATA_SIZE; index++)
//		data[index]=0;
	nextNodePtr=NULL;
}

Node::~Node(void){
	cout << "Node has been destroyed" << endl;
}

void Node::printForTest(void){
	cout<<"Just testing if it works" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList{
private:
	Node *nextPtr;
	Node *prevPtr;
	int id;        /* number of nodes added */ 
	//Node *headPtr; /* This will hold the first element address */
public:
	Node *headPtr;
	LinkedList(void);
	~LinkedList(void);
	void printForTest(void);

	int insertNode(void);
	int searchNodeID(int NodeID);
};

LinkedList::LinkedList(void){
	headPtr=NULL;
	id=0;
	cout<<"A list has been created" << endl;
}

LinkedList::~LinkedList(void){
	cout<<"A list has been destroyed" << endl;
}

void LinkedList::printForTest(void){
	cout << "Printing this from a LinkedList object" << endl;
}

int LinkedList::insertNode(void){
	if(headPtr==NULL){
		cout << "LL ------- First node created ------" << endl;
		
		id++;
		headPtr = new Node; //Create the first node
		headPtr->id=id;
		headPtr->nextNodePtr=NULL;

		cout << "           - Node ID is: " << headPtr->id << endl;
		return 1;
	}
	else 
		prevPtr = headPtr;


	while(1){
		if (prevPtr->nextNodePtr==NULL){
			
			cout << "LL ------- Node created -------" << endl;
			
			id++;	
			prevPtr->nextNodePtr = new Node;
			prevPtr->nextNodePtr->id=id;
			prevPtr->nextNodePtr->nextNodePtr=NULL;

			cout << "           - Node ID is: " << prevPtr->id << endl;
			return 1;
		}
		prevPtr=prevPtr->nextNodePtr;
	}

	//headPtr = new Node; //create the node
	//headPtr->nextPtr=NULL;
	return 0;
}

int LinkedList::searchNodeID(int NodeID){
	if(headPtr==NULL){
		cout << "Any node exists" << endl;
		return 0; /* There isn't any node */
		}

	nextPtr=headPtr;
	while(1){
		cout << " Node ID : " << nextPtr->id << endl;
		if(NodeID==nextPtr->id){
			cout << "This node exists" << endl;
			return 1;
		}
		if(nextPtr->nextNodePtr==NULL){
			cout << "This node doesnt exist" << endl;
			return 0;
		}

		prevPtr=nextPtr;
		nextPtr=nextPtr->nextNodePtr;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	LinkedList c1a;
	
	cout << "Criando" << endl;

	int checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();
	checker = c1a.insertNode();

	checker = c1a.searchNodeID(5);
	checker = c1a.searchNodeID(11);
	checker = c1a.searchNodeID(3);


	LinkedList c1b;
	checker = c1b.insertNode();
	checker = c1b.insertNode();
	checker = c1b.insertNode();
	checker = c1b.searchNodeID(11);
	checker = c1b.searchNodeID(3);


/*
	nodePtr = new Node;
	nodePtr->printForTest();

	cout << "Destruindo" << endl;

	
	delete nodePtr;
	nodePtr=NULL;
*/	
	return 0;
	
}