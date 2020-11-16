#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_NUM		100

typedef struct list_node {
	struct list_node *link;
	int data;
} NODE;


int headInsert(NODE **, NODE **, int);
int headDelete(NODE **, NODE **, int *);
int tailInsert(NODE **, NODE **, int);
void deleteList(NODE **, NODE **);
static void printList(NODE *);


int main()
{
	NODE *head = 0;
	NODE *tail = 0;
	int  data0[] = { 99, 89, 76, 65, 51, 43, 23, 18, 9, -1 };
	int  data1[] = { 512, 415, 328, 256, 128, -1 };
	int  *data_used;
	int  i, num, i_data, phase;

	for(phase = 0 ; phase < 2 ; phase++) {
		if(phase)
			data_used = data1;
		else
			data_used = data0;

		cout << endl << "Perform headInsert at phase " << phase;
		for(i = 0 ; i < MAX_NUM ; i++) {
			if(data_used[i] < 0)
				break;
			if(!headInsert(&head, &tail, data_used[i])) {
				cerr << "Head insertion failed." << endl;
				exit(1);
			}
		}
		num = i;
		cout << endl << "  headInsert expected  :";
		for(i = num-1 ; i >= 0 ; i--)
			cout << " " << data_used[i];
		cout << endl;
		cout << "  headInsert performed :";
		printList(head);
		cout << endl;

		cout << endl << "Perform headDelete at phase " << phase << endl;
		for(i = num-1 ; i >= 0 ; i--) {
			cout << "  deleting a head node :";
			printList(head);
			cout << endl;
			if(!headDelete(&head, &tail, &i_data)) {
				cerr << "Head deletion failed (1)." << endl;
				exit(1);
			}
			if(i_data != data_used[i]) {
				cerr << "Head deletion failed (2)." << endl;
				exit(1);
			}
		}
		if(headDelete(&head, &tail, &i_data)) {
			cerr << "Head deletion failed (3)." << endl;
			exit(1);
		}
		cout << "  headDelete performed okay." << endl;

		cout << endl << "Perform tailInsert at phase " << phase << endl;
		for(i = 0 ; i < MAX_NUM ; i++) {
			if(data_used[i] < 0)
				break;
			if(!tailInsert(&head, &tail, data_used[i])) {
				cerr << "Tail insertion failed." << endl;
				exit(1);
			}
		}
		num = i;
		cout << "  tailInsert expected  :";
		for(i = 0 ; i < num ; i++)
			cerr << " " << data_used[i];
		cout << endl;
		cout << "  tailInsert performed :";
		printList(head);
		cout << endl;

		cout << endl << "Deleting current list at phase " << phase << endl;
		deleteList(&head, &tail);
		if(head || tail) {
			cerr << "List is not deleted." << endl;
			exit(1);
		}
		cout << "  deleteList perfomed okay" << endl;
	}
}

int headInsert(NODE **head, NODE **tail, int data_used)
{
	/* Write Here */
	NODE *new_node=(NODE *)malloc(sizeof(NODE));
	new_node->data=data_used;
	new_node->link=*head;
	*head=new_node;
	if(!*tail)
		*tail=new_node;
	return 1;
}

int headDelete(NODE **head, NODE **tail, int *i_data)
{
	/* Write Here */
	NODE *delete_node=(NODE *)malloc(sizeof(NODE));
	delete_node=*head;
	*head=delete_node->link;
	&head->data=*i_data;
	free(delete_node);
	return 1;	
}

int tailInsert(NODE **head, NODE **tail, int data_used)
{
	/* Write Here */
	
}

void deleteList(NODE **head, NODE **tail)
{
	/* Write Here */

}

static void printList (NODE *head)
{	
	/* Write Here */
	while(head){
	cout<<head->data<<" ";
	head=head->link;
	}
}

