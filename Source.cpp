#include<iostream>
#include<string>

using namespace std;

struct Node
{
	int data;
	Node* lptr;
	Node* rptr;
};



void createDB(Node*& hh, Node*& cc, Node*& pp, Node*& tt)
{
	char ch;
	while (true)
	{
		cc = new Node;
		cc->rptr = NULL;
		cc->lptr = NULL;

		cout << " Enter Data: ";
		cin >> cc->data;

		if (hh == NULL)
			hh = pp = tt = cc;
		else {
			tt = cc;
			pp->rptr = cc;
			cc->lptr = pp;
			pp = cc;
		}

		cout << "\n Do you Want Another Node: ";
		cin >> ch;

		if (toupper(ch) != 'Y')
			break;
	}
}
void myGetter(Node* hh, Node* cc, Node* tt)
{
	char ch;
	while (true)
	{
		cout << "\n -----------(SUB MENU)------------\n";
		cout << " 1) FORWARD TRAVERSE \n";
		cout << " 2) BACKWARD TRAVERSE \n";
		cout << " 3) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "\n Elements in Forward Direction: ";
			cc = hh;
			while (cc != NULL)
			{
				cout << cc->data << "  ";
				cc = cc->rptr;
			}
			break;
		case '2':
			cout << "\n Elements in Backward Direction: ";
			cc = tt;
			while (cc != NULL)
			{
				cout << cc->data << "  ";
				cc = cc->lptr;
			}
			break;
		case '3':
			ch = 'Y';
			break;
		default:
			cout << " Invalid Input...!!!\n";
		}

		if (toupper(ch) == 'Y')
			break;
	}
	cout << endl;
}


void myUpdate(Node* hh, Node* cc)
{
	int data;
	cout << "\n Enter Data You Want To Update: ";
	cin >> data;

	cc = hh;
	while (cc != NULL)
	{
		if (cc->data != data)
			cc = cc->rptr;
		else
		{
			cout << " Enter Update Data: ";
			cin >> cc->data;
			break;
		}
	}
	if (cc == NULL)
	{
		cout << " Data Not Found ...!!!\n";
	}
}
/* Sorting Without Addressing */
/*void mySort(Node* hh, Node* cc, Node* pp)
{
	cc = pp = hh;
	while (pp->rptr != NULL)
	{
		cc = pp->rptr;
		while (cc != NULL)
		{
			if (pp->data > cc->data)
			{
				swap(pp->data, cc->data);
			}
			else
			{
				cc = cc->rptr;
			}
		}
		pp = pp->rptr;
	}
	cout << "\n Sort The Record Successfully ..!!!\n";
}
*/
void myInsertion(Node*& hh, Node* cc, Node*& tt, Node* newNode)
{
	if (hh == NULL)
	{
		hh = cc = tt = newNode;
	}
	else if (newNode->data <= hh->data)
	{
		newNode->rptr = hh;
		hh->lptr = newNode;
		hh = newNode;
	}
	else
	{
		cc = hh;
		while (cc != NULL)
		{
			if (newNode->data > cc->data)
			{
				cc = cc->rptr;
			}
			else
			{
				newNode->lptr = cc->lptr;
				cc->lptr->rptr = newNode;

				newNode->rptr = cc;
				cc->lptr = newNode;

				break;
			}
		}
		if (cc == NULL)
		{
			tt->rptr = newNode;
			newNode->lptr = tt;
			tt = newNode;
		}
	}
	cout << "\n Insert The Record Successfully ... !!!\n";
}

void myDeletion(Node*& hh, Node* cc, Node*& tt, int data)
{

	cc = hh;
	if (hh->data == data)
	{
		if (hh->rptr != NULL)
		{
			hh = hh->rptr;
			hh->lptr = NULL;

			delete cc;
		}
		else
		{
			delete cc;
			hh = tt = cc = NULL;
		}
		cout << "\n Record Deleted Successfully ... !!! ulu\n";
	}
	else
	{
		while (cc != NULL)
		{
			if (cc->data != data)
			{
				cc = cc->rptr;
			}
			else
			{
				if (cc->rptr == NULL)
				{
					cc->lptr->rptr = cc->rptr;
					tt = cc->lptr;
				}
				else
				{
					cc->rptr->lptr = cc->lptr;
					cc->lptr->rptr = cc->rptr;
				}
				delete cc;
				cout << "\n Record Deleted Successfully ... !!!\n";
				break;
			}
		}
		if (cc == NULL)
		{
			cout << "\n Data Not Found ... !!!\n";
		}
	}
}
/* Sorting By Addressing */
void mySort(Node*& hh, Node* cc, Node*& tt)
{
	cc = hh;
	while (cc->rptr != NULL)
	{
		if (cc->data > cc->rptr->data)
		{
			Node* temp = new Node;
			temp->data = cc->rptr->data;
			temp->rptr = NULL;
			temp->lptr = NULL;

			myDeletion(hh, cc, tt, cc->rptr->data);
			myInsertion(hh, cc, tt, temp);
		}
		else
		{
			cc = cc->rptr;
		}
	}
	cout << "\n Sort The Record Successfully ..!!!\n";
}
int main()
{
	Node* head = NULL;
	Node* cur = NULL;
	Node* prev = NULL;
	Node* tail = NULL;

	Node* newNode = new Node;
	newNode->lptr = NULL;
	newNode->rptr = NULL;

	char ch;
	while (true) {
		cout << "\n ------------(MAIN MENU)-----------\n";
		cout << " 1) CREATE DATABASE \n";
		cout << " 2) GETTER \n";
		cout << " 3) INSERTION \n";
		cout << " 4) DELETION \n";
		cout << " 5) UPDATION \n";
		cout << " 6) SORTING \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			if (head != NULL)
				cout << "\n Database Is Already Created.\n Kindly Go To The Insert Opperation ....\n";
			else
				createDB(head, cur, prev, tail);
			break;
		case '2':
			if (head == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Getter Operation ....\n";
			else
				myGetter(head, cur, tail);
			break;
		case '3':
			cout << "\n Enter Data You Want to Insert: ";
			cin >> newNode->data;

			myInsertion(head, cur, tail, newNode);
			break;
		case '4':
			if (head == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Delete Operation ....\n";
			else
			{
				int data;
				cout << "\n Enter Data You Want to Delete: ";
				cin >> data;

				myDeletion(head, cur, tail, data);
			}
			break;
		case '5':
			if (head == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Update Operation ....\n";
			else
				myUpdate(head, cur);
			break;
		case '6':
			if (head == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Sort Operation ....\n";
			else
				mySort(head, cur, tail);
			break;
		case '7':
			exit(-1);
		default:
			cout << "\n Invalid Input ... !!!\n";
		}

	}


}