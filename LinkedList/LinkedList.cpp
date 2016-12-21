#include<iostream>
using namespace std;

class LinkedList {
public:
	struct Node {
		int data;
		Node* next;
	};
	void print(Node*& head);
	Node* insert(Node*& head, int n, int place);
	Node* remove(Node*& head, int place);
	LinkedList();

	//Member variables
	Node* head;

};

LinkedList::LinkedList() {
	head = NULL; 
}

LinkedList::Node* LinkedList::insert(Node*& head, int n, int place) {
	Node* temp = new Node();
	temp->data = n;
	temp->next = NULL;

	if (place == 1) {
		temp->next = head;
		head = temp;
		return head;
	}

	Node* temp2 = head;
	for(int i = 0; i < place - 2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;

	return head;
}

LinkedList::Node* LinkedList::remove(Node*& head, int place) {
	Node* temp = head;

	if (place == 1) {
		head = temp->next;
		delete temp;
		return head;
	}

	for(int i = 0; i < place - 2; i++) {
		temp = temp->next;
	}
	Node* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
	return head;
}

void LinkedList::print(Node*& head) {
	Node* temp = head;
	cout << "Elements are: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	LinkedList list = LinkedList();
	list.head = list.insert(list.head, 3, 1);
	list.head = list.insert(list.head, 5, 2);
	list.head = list.insert(list.head, 4, 3);
	list.head = list.insert(list.head, 1, 4);
	list.head = list.insert(list.head, 12, 4);
	list.print(list.head);
	list.head = list.remove(list.head, 4);
	list.print(list.head);
}