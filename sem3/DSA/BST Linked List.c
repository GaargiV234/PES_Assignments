#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create_node(int key);
void insert(struct node **root,int key);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
void delete_node(struct node **rt,int key);

int main(){
	int ch,key;
	struct node *root=NULL;
	while(1){
		printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the element\n");
				scanf("%d",&key);
				insert(&root,key);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;	
			case 4:
				postorder(root);
				break;	
			case 5:
				printf("\nEnter node to be deleted\n");
				scanf("%d",&key);
				delete_node(&root,key);
				break;	
		}
	}
}

struct node *create_node(int key){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(struct node **root,int key){
	struct node *temp = create_node(key);
	struct node *p=*root;
	struct node *prev=NULL;
	if(*root==NULL){
		*root=temp;
		return;
	}
	while(p!=NULL){
		prev=p;
		if(key>=p->data)
			p=p->right;
		else
			p=p->left;
	} 
	if(key>=prev->data){
		prev->right=temp;
	}
	else{
		prev->left=temp;
	}
}

void preorder(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);	
	inorder(root->right);
}

void postorder(struct node *root){
	if(root==NULL){
		return;
	}	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void delete_node(struct node **rt,int key){
	//First find the node
	struct node *pres=*rt;
	struct node *parent=NULL;
	while(pres->data!=key&&pres!=NULL){
		parent=pres;
		if(key>pres->data){
			pres=pres->right;
		}
		else if(key<pres->data){
			pres=pres->left;
		}
	}
	
	//Now check if the node exists
	if(pres==NULL){
		printf("\nNode does not exist\n");
		return;
	}
	printf("\nFound node and it exists\n");
	//OK now we have the node. pres is the node and parent is its parent
	//Case 1: deletion of leaf node
	if(pres->right==NULL&&pres->left==NULL){
		//Is leaf also root?
		if(parent==NULL){
			*rt=NULL;
			free(pres);
			return;
		}
		if(pres->data>parent->data){
			parent->right=NULL;
		}
		else{
			parent->left=NULL;
		}
		free(pres);
		return;
	}
	//Case 2: node with one child
	else if(pres->right==NULL||pres->left==NULL){
		//Is pres also root?
		if(parent==NULL){
			if(pres->right!=NULL){
				*rt=pres->right;
			}
			else{
				*rt=pres->left;
			}
			free(pres);
			return;
		}
		//OK pres is not root:
		struct node *q=NULL;
		if(pres->right!=NULL){
			q=pres->right;
		}
		else{
			q=pres->left;
		}
		if(pres==parent->right){
			parent->right=q;
		}
		else{
			parent->left=q;
		}
		free(pres);
		return;
	}
	//Case 3: node with two children
	else{
		printf("\nNode has two children\n");
		//Find inorder successor:
		struct node *cur=pres->right;
		struct node *prev=NULL;
		while(cur->left!=NULL){
			prev=cur;
			cur=cur->left;
		}
		printf("\nFound inorder successor\n");
		//replace pres with inorder successor
		pres->data=cur->data;
		if(prev!=NULL){
			prev->left=cur->right;
		}
		else{
			pres->right=cur->right;
		}
		free(cur);
		return;
	}
}