#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *stack[100];
int top=-1;

struct node *createnode(char ele);
void push(struct node *temp);
struct node *pop();
float evaluate(struct node *root);
struct node *createstack(char *post);
void preorder(struct node *root);

int main(){
	char postfix[100];
	float val;
	printf("\nEnter postfix expression\n");
	scanf("%s",&postfix);
	struct node *root=createstack(postfix);
	val=evaluate(root);
	printf("\nAnswer is: %f\n",val);
	printf("\nPrefix expression:\n");
	preorder(root);
}

struct node *createnode(char ele){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->right=NULL;
	temp->left=NULL;
	temp->data=ele;
	return temp;
}

void push(struct node *temp){
	top++;
	stack[top]=temp;
}

struct node *pop(){
	struct node *temp=stack[top];
	stack[top]=NULL;
	top--;
	return temp;
}

float evaluate(struct node *root){
	char ch=root->data;
	switch(ch){
		case '+': return(evaluate(root->left)+evaluate(root->right));
		case '-': return(evaluate(root->left)-evaluate(root->right));
		case '*': return(evaluate(root->left)*evaluate(root->right));
		case '/': return(evaluate(root->left)/evaluate(root->right));
		default: return root->data-'0';
	}
}

struct node *createstack(char *post){
	int i=0;
	char ele;
	struct node *first=NULL;
	struct node *second=NULL;
	while(post[i]!='\0'){
		ele=post[i];
		struct node *temp = createnode(ele);
		switch(ele){
			case '+':
			case '-':
			case '*':
			case '/':
				first=pop();
				second=pop();
				temp->left=first;
				temp->right=second;
				push(temp);
				printf("\nPushed operator\n");
				break;
			default:
				push(temp);
				printf("\nPushed operand\n");
				break;
		}
		++i;
	}
	printf("\nFinished creating tree\n");
	return pop();
}

void preorder(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%c ",root->data);
	preorder(root->left);
	preorder(root->right);
}