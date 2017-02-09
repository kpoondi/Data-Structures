#include<iostream>
using namespace std;

class LinkedList {
public:
	struct Node {
		int data;
		Node* next;
	};
	void print_recursive(Node*& head); //recursive  print 
	void print(Node*& head);
	void print_recursive_backwards(Node*& head); //backwards recursive print
	Node* insert(Node*& head, int n, int place);
	Node* remove(Node*& head, int place);
	LinkedList::Node* reverseList(Node* head);
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

	Node* temp_insert = head;
	for(int i = 0; i < place - 2; i++) {
		temp_insert = temp_insert->next;
	}
	temp->next = temp_insert->next;
	temp_insert->next = temp;

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
	Node* temp_remove = temp->next;
	temp->next = temp_remove->next;
	delete temp_remove;
	return head;
}

void LinkedList::print_recursive(Node*& head) {
	if (head == NULL) {
		cout << endl;
		return;
	}
	cout << head->data << " ";
	LinkedList::print_recursive(head->next);
}

void LinkedList::print_recursive_backwards(Node*& head) {
	if (head == NULL) 
		return;
	LinkedList::print_recursive_backwards(head->next);
	cout << head->data << " ";
}


void LinkedList::print(Node*& head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

LinkedList::Node* LinkedList::reverseList(Node* head) {
    Node *current, *prev, *next;
    prev = NULL;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


int main() {
	LinkedList list = LinkedList();
	list.head = list.insert(list.head, 3, 1);
	list.head = list.insert(list.head, 5, 2);
	list.head = list.insert(list.head, 4, 3);
	list.head = list.insert(list.head, 1, 4);
	list.head = list.insert(list.head, 12, 4);
	list.print_recursive(list.head);
	list.head = list.remove(list.head, 4);
	list.print_recursive(list.head);
	list.print_recursive_backwards(list.head);
	list.head = list.reverseList(list.head);
	cout << endl;
	list.print(list.head);
	cout << endl;
}





