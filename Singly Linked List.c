#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *head);
struct node *create_node(int key);
void insert_front(struct node **head,int key);
void insert_rear(struct node **head,int key);
void insert_pos(struct node **head,int key,int pos);
void delete_front(struct node **head);
void delete_rear(struct node **head);
void delete_ele(struct node **head,int key);
void insert_ordered(struct node **head,int key);

int main(){
	int ch,key,pos;
	struct node *head=NULL;
	while(1){
		display(head);
		printf("\n1.Insert at front\n2.Insert at end\n3.Insert at pos\n4.Delete at front\n5.Delete rear\n6.Delete ele\n7.Ordered Insertion\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the element\n");
				scanf("%d",&key);
				insert_front(&head,key);
				break;
			case 2:
				printf("\nEnter element\n");
				scanf("%d",&key);
				insert_rear(&head,key);
				break;
			case 3:
				printf("\nEnter element and pos\n");
				scanf("%d %d",&key,&pos);
				insert_pos(&head,key,pos);
				break;
			case 4:
				delete_front(&head);
				break;
			case 5:
				delete_rear(&head);
				break;
			case 6:
				printf("\nEnter element to be deleted\n");
				scanf("%d",&key);
				delete_ele(&head,key);
				break;
			case 7:
				printf("\nEnter the key\n");
				scanf("%d",&key);
				insert_ordered(&head,key);
				break;
		}
	}
}

void display(struct node *head){
	if(head==NULL){
		printf("\nEmpty list\n");
	}
	else{
		struct node *p=head;
		printf("\n");
		while(p!=NULL){
			printf("%d->",p->data);
			p=p->next;
		}
		printf("\n");
	}
}

struct node *create_node(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

void insert_front(struct node **head,int key){
	struct node *temp=create_node(key);
	if(*head==NULL){
		*head=temp;
	}
	else{
		temp->next=(*head);
		*head=temp;
	}
}

void insert_rear(struct node **head,int key){
	struct node *temp = create_node(key);
	if(*head==NULL){
		*head=temp;
	}
	else{
		struct node *p=*head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
	}
}

void insert_pos(struct node **head,int key,int pos){
	struct node *temp=create_node(key);
	int count=0;
	if(*head==NULL&&pos==1){
		*head=temp;
	}
	else{
		struct node *p=*head;
		struct node *prev=NULL;
		count++;
		while(count<pos){
			prev=p;
			p=p->next;
			count++;
		}
		if(prev==NULL&&count<=pos&&p==NULL){
			printf("\nInvalid position\n");
			return;
		}
		else{
			if(pos==1){
				insert_front(head,key);
			}
			else{
				temp->next=p;
				prev->next=temp;
			}
		}
	}
}

void insert_ordered(struct node **head,int key){
	struct node *temp = create_node(key);
	if(*head==NULL){
		*head=temp;
	}
	else{
		struct node *p = *head;
		struct node *prev=NULL;
		while(p!=NULL&&p->data<key){
			prev=p;
			p=p->next;
		}
		if(p==NULL){
			prev->next=temp;
		}
		else if(prev==NULL){
			temp->next=*head;
			*head=temp;
		}
		else{
			temp->next=prev->next;
			prev->next=temp;
		}
	}
}

void delete_front(struct node **head){
	if(*head==NULL){
		printf("\nEmpty List\n");
		return;
	}
	else{
		struct node *p=*head;
		(*head)=(*head)->next;
		free(p);
	}
}

void delete_rear(struct node **head){
	if(*head==NULL){
		printf("\nEmpty List\n");
		return;
	}
	else{
		struct node*p=*head;
		struct node *prev=NULL;
		while(p->next!=NULL){
			prev=p;
			p=p->next;
		}
		if(prev!=NULL){
			prev->next=NULL;
			free(p);
		}	
		else{
			*head=NULL;
			free(p);
		}	
	}
}

void delete_ele(struct node **head,int key){
	if(*head==NULL){
		printf("\nEmpty List\n");
		return;
	}
	else{
		struct node *p=*head;
		struct node *prev=NULL;
		while(p!=NULL&&p->data!=key){
			prev=p;
			p=p->next;
		}
		if(p==NULL){
			printf("\nElement not found\n");
			return;
		}
		else{
			if(prev==NULL){
				*head=(*head)->next;
				free(p);
			}
			else{
				prev->next=p->next;
				free(p);
			}
		}
	}
}



