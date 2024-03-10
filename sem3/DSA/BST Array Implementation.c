#include<stdio.h>
#include<stdlib.h>

void insert(int *t,int key);
void preorder(int *t,int pos);
void inorder(int *t,int pos);
void postorder(int *t,int pos);

int main(){
	int tree[100];
	int key,ch;
	for(int i=0;i<100;i++){
		tree[i]=-1;
	}
	while(1){
		printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter key\n");
				scanf("%d",&key);
				insert(tree,key);
				break;
			case 2:
				preorder(tree,0);
				break;
			case 3:
				inorder(tree,0);
				break;
			case 4:
				postorder(tree,0);
				break;
		}
	}
}

void preorder(int *t,int pos){
	if(t[pos]==-1){
		return;
	}
	printf("%d ",t[pos]);
	preorder(t,2*pos+1);
	preorder(t,2*pos+2);
}

void inorder(int *t,int pos){
	if(t[pos]==-1){
		return;
	}
	inorder(t,2*pos+1);
	printf("%d ",t[pos]);	
	inorder(t,2*pos+2);
}

void postorder(int *t,int pos){
	if(t[pos]==-1){
		return;
	}
	
	postorder(t,2*pos+1);
	postorder(t,2*pos+2);
	printf("%d ",t[pos]);
}


void insert(int *t,int key){
	int pos=0;
	while(t[pos]!=-1){
		if(key>=t[pos]){
			pos=2*pos+2;
		}
		else{
			pos=2*pos+1;
		}
	}
	t[pos]=key;
}