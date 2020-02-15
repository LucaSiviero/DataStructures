#include "pch.h"
#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

class List {
private:
	Node* head;
	Node* tail;
	int length;
public:
	List() {
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void createList(Node* node) {
		//Node* temp = new Node;
		head = node;
		tail = node;
		length = 1;
		cout << "List created with 1 node with value: " << node->data << " and address:" << node << endl;
	}

	Node* createNode(int value) {
		Node* temp = new Node;
		temp->data = value;
		temp->next = NULL;
		cout << "Node created! " << endl;
		return temp;
	}

	void addNodeAtEnd(Node* node) {
		tail->next = node;
		tail = node;
		cout << "Node added at the end of the list " << node << endl;
		length++;
	}

	void addNodeAtStart(Node* node) {
		node->next = head;
		head = node;
		length++;
		cout << "Node added at the start of the list." << node << " The next node is: " <<node->next << endl;
	}

	void printList() {
		Node* cur = new Node;
		Node* pre = new Node;
		int c = 1;
		cur = head;
		cout << c << "-The head is " << cur << " with value: " << cur->data << endl;
		while (cur->next != NULL) {
			pre = cur;
			cur = cur->next;
			c++;
			cout << c << "-" << cur << " with value: " << cur->data << endl;
		}
	}

	void deleteHead() {
		head = head->next;
		length--;
		cout << "Head removed; " << "New head is: " << head << " with value " << head->data << endl;
	}

	void removeTail() {			//rifai
		/*before tail = tail*/
		Node* cur = new Node;
		Node* pre = new Node;
		cur = head;
		while (cur->next != NULL) {
			pre = cur;
			cur = cur->next;
		}//il precedente alla coda = nuova coda;	Il corrente = NULL;
		tail = pre;
		pre->next = NULL;
		length--;
		cout << "Tail removed\n";
	}

	void addAtPosition(int pos, Node* node) {
		/*Raggiungo la posizione richiesta. Il prossimo diventa il nodo parametro. 
		Il prossimo al nodo parametro è il prossimo del nodo nella posizione.*/
		Node* cur = new Node;
		Node* pre = new Node;

		cur = head;
		if (pos == 1) {
			addNodeAtStart(node);
			return;
		}
		for (int i = 2; i <= pos; i++) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = node;
		node->next = cur;
		length++;
		cout << "Node " << node << " added at position " << pos << endl;
	}

	void removeAtPosition(int pos) {
		/*raggiungo la posizione. il precedente->next = pos+1*/
		Node* pre = new Node;
		Node* cur = new Node;
		cur = head;
		//Dalla testa: pre = cur. cur = cur->next. Arriverò alla posizione pos.
		for (int i = 1; i <= pos; i++) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		length--;
		cout << "Node " << cur << " removed from the list." << " At the position " << pos << endl;
	}

	void changeValue(int pos, int newData) {
		Node* cur = new Node;
		cur = head;
		if (pos == 1) {
			cur->data = newData;
		}
		else {
			for (int i = 2; i <= pos; i++) {
				cur = cur->next;
			}
			cur->data = newData;
		}

		cout << "Node " << cur << " changed with value: " << newData << endl;
	}

	void bubbleSort() {
		//Gli elementi vengono confrontati a due a due. j = i+1. se i > j, il j-esimo diventa l'i-esimo.
		Node* cur = new Node;
		Node* pre = new Node;
		int major = 0;
		int minor = 0;
		int data = 0;
		//if pre > cur => NodoMaggiore = pre, NodoMinore = cur. cur->next = pre.
		cur = head;
		if (cur->next == NULL) {
			cout << "C'è un solo elemento" << endl;
		}
		else {
			for (int i = 0; i < length-1; i++) {
				cur = head;
				while (cur->next != NULL) {
					pre = cur;
					cur = cur->next;
					if (pre->data > cur->data) {
						major = pre->data;
						minor = cur->data;
						cur->data = major;
						pre->data = minor;
						cout << "Scambiati!!\n";
					}
				}
			}
		}
	}

	int getLength() {
		cout << "List has " << length << " elements\n";
		return length;
	}
};

int main()
{
	List* lista = new List();
	Node* startNode = lista->createNode(50);
	lista->createList(startNode);
	Node* newNode = lista->createNode(56);
	lista->addNodeAtStart(newNode);

	Node* endNode = lista->createNode(67);
	lista->addNodeAtEnd(endNode);
	Node* node1 = lista->createNode(32);
	lista->addNodeAtEnd(node1);
	//Node* nodeAtPos = lista->createNode(3);
	//lista->addAtPosition(1, nodeAtPos);
	lista->printList();
	int length = lista->getLength();
	
	//lista->changeValue(1, 250);
	//lista->removeAtPosition(1);
	lista->bubbleSort();
	lista->printList();
	
	/*
	lista->deleteHead();
	lista->removeTail();
	lista->printList();
	*/
	return 0;
}
