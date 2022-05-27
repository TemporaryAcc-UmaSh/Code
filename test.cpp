#include <iostream>
#define neul 0
using namespace std;

struct Demo{
	int data;
	struct Demo* next;
};
typedef struct Demo demo;

demo* createnode(){
	demo *js;
	js=(demo*)malloc(sizeof(demo));
	cout<<"Enter an element: ";
	cin>>js->data;
	js->next=neul;
	return js;
}

demo * deletenode(demo *x){
	x=x->next;
	return x;
}

void display_queue(demo *x){
	if (x==neul) cout<<"\nQueue is empty.\n";
	while (x!=neul){
			cout<<x->data<<"\t";
			x=x->next;
	}
	cout<<"\n";
}

int main(){
	int choice,count;
	demo *front, *rear, *temp;
	front=neul;
	char ch;
	do{
		cout<<"1. Enqueue\n2. Dequeue\n3. Display\nYour choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				rear=createnode();
				if (front==neul){
					front=rear;
					temp=rear;
				}
				else{
					temp->next=rear;
					temp=rear;
				}
				count++;
				cout<<"\nNo. of nodes in tree: "<<count<<endl;
				break;
		
			case 2:
				if (front==neul) cout<<"\nQueue is empty.\n";
				else {
						demo *y;
						y=front;
						front=deletenode(front);
						cout<<"Dequeued element: "<<y->data<<endl;
				}
				break;

			case 3:
				if (front==neul) cout<<"\nQueue is empty.\n";
				else display_queue(front);
				break;

			default: cout<<"Enter valid choice -_-'";
		}
		cout<<"Do you want to continue?(y/n): ";
		cin>>ch;
	}
	while (ch=='y'||ch=='Y');
}