#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *rear);
struct node *create_node(int key);
void insert_front(struct node **rear,int key);
void insert_rear(struct node **rear, int key);
void insert_pos(struct node **rear,int key,int pos);

int main(){
	int ch,key,pos;
	struct node *rear=NULL;
	while(1){
		display(rear);
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert at pos\n4.Delete at front\n5.Delete rear\n6.Delete ele\n7.Ordered Insertion\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the element\n");
				scanf("%d",&key);
				insert_front(&rear,key);
				break;
			case 2:
				printf("\nEnter element\n");
				scanf("%d",&key);
				insert_rear(&rear,key);
				break;
			case 3:
				printf("\nEnter element and pos\n");
				scanf("%d %d",&key,&pos);
				insert_pos(&rear,key,pos);
				break;
			case 4:
				//delete_front(&rear);
				break;
			case 5:
				//delete_rear(&rear);
				break;
			case 6:
				printf("\nEnter element to be deleted\n");
				scanf("%d",&key);
				//delete_ele(&rear,key);
				break;
			case 7:
				printf("\nEnter the key\n");
				scanf("%d",&key);
				//insert_ordered(&rear,key);
				break;
		}
	}
}

void display(struct node *rear){
	if(rear==NULL){
		printf("\nEmpty List\n");
		return;
	}
	struct node *p=rear->next;
	printf("\n");
	while(p!=rear){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("%d",p->data);
	printf("\n");
}

struct node *create_node(int key){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=temp;
	return temp;
}

void insert_front(struct node **rear,int key){
	struct node *temp=create_node(key);
	if(*rear==NULL){
		*rear=temp;
	}
	else{
		temp->next=(*rear)->next;
		(*rear)->next=temp;		
	}
}

void insert_rear(struct node **rear, int key){
	struct node *temp = create_node(key);
	if(*rear==NULL){
		*rear=temp;
	}
	else{
		temp->next=(*rear)->next;
		(*rear)->next=temp;
		(*rear)=temp;
	}
}

void insert_pos(struct node **rear,int key,int pos){
	struct node *temp=create_node(key);
	if(*rear==NULL&&pos==1){
		*rear=temp;
	}
	else{
		int count = 1;
		struct node *p = (*rear)->next;
		struct node *prev=NULL;
		while(count<pos&&p!=(*rear)->next){
			p=p->next;
			count++;
		}
		if(count<(pos-1)){
			printf("\nInvalid position\n");
			return;
		}
		if(prev==NULL){
			(*rear)->next=temp;
			temp->next=p;
		}
		else{
			prev->next=temp;
			temp->next=p;
		}
	}
}