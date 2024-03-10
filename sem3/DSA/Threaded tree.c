#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int rthread;
	struct node *right;
	struct node *left;
};

void setLeft(struct node *q,int e);
void setRight(struct node *q,int e);
struct node *insert(struct node *root);
void inorder(struct node *root);
struct node *createnode(int val);

int main(){
	struct node *root=NULL;
	root=insert(root);
	inorder(root);
}

void setLeft(struct node *q,int e){
	struct node *temp = createnode(e);
	q->left=temp;
	temp->right=q;
}

void setRight(struct node *q,int e){
	struct node *temp = createnode(e);
	temp->right=q->right;
	q->right=temp;
	q->rthread=0;
}

struct node *insert(struct node *root){
	int info;
	int wish;
	struct node *p;
	struct node *q;
	printf("\nEnter root\n");
	scanf("%d",&info);
	root=createnode(info);
	printf("\nEnter more? 1=yes 0=no\n");
	scanf("%d",&wish);
	while(wish){
		printf("\nEnter value\n");
		scanf("%d",&info);
		p=root;
		q=NULL;
		while(p!=NULL){
			q=p;
			if(info<p->data){
				p=p->left;
			}
			else{
				if(p->rthread){
					p=NULL;
				}
				else{
					p=p->right;
				}
			}
		}
		
		if(info<q->data){
			setLeft(q,info);
		}
		else{
			setRight(q,info);
		}
		printf("\nEnter more? 1=yes 0=no\n");
		scanf("%d",&wish);			
	}
	return root;
}

void inorder(struct node *root){
	struct node *p=root;
	struct node *q=NULL;
	do{
		q=NULL;
		while(p!=NULL){
			q=p;
			p=p->left;
		}
		if(q!=NULL){
			printf("%d ",q->data);
			p=q->right;
			while(q->rthread&&p!=NULL){
				q=p;
				printf("%d ",p->data);
				p=p->right;
			}
		}
	}while(q!=NULL);
}

struct node *createnode(int val){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->rthread=1;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}