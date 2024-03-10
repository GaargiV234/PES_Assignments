#include<stdio.h>
#include<stdlib.h>

struct trienode{
	int eow;
	struct trienode *child[256];	
};

int length=0;
char word[100];

struct trienode *getnode();
void insert(struct trienode *root, char *key);
void display(struct trienode *cur);
int search(struct trienode *root,char *key);
struct trienode *delete_word(struct trienode *root,char *key,int level,int length);
int isempty(struct trienode *root);

int main(){
	char key[100];
	int ch,len;
	struct trienode *root=getnode();
	while(1){
		display(root);
		printf("\n1.Insert\n2.Search\n3.Delete\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the word\n");
				scanf("%s",&key);
				insert(root,key);
				break;
			case 2:
				printf("\nEnter word to be searched\n");
				scanf("%s",&key);
				if(search(root,key)){
					printf("\nSearch successful\n");
				}
				else{
					printf("\nWord not found\n");
				}
				break;
			case 3:
				printf("\nEnter length and word to be deleted\n");
				scanf("%d %s",&len,&key);
				root=delete_word(root,key,0,len);
				break;
		}
	}
}

struct trienode *getnode(){
	struct trienode *temp = (struct trienode *)malloc(sizeof(struct trienode));
	temp->eow=0;
	for(int i=0;i<256;i++){
		temp->child[i]=NULL;
	}
	return temp;
}

void insert(struct trienode *root, char *key){
	int i,index;
	struct trienode *cur=root;
	for(i=0;key[i]!='\0';i++){
		index=key[i];
		//printf("\n%d is index %c is key[i]\n",index,key[i]);
		if(cur->child[index]==NULL){
			cur->child[index]=getnode();
		}
		cur=cur->child[index];
	}
	cur->eow=1;
}

void display(struct trienode *cur){
	int i,j;
	for(i=0;i<256;i++){
		if(length==-1){
			length=0;
		}
		if(cur->child[i]!=NULL){
			//printf("\n%c is cur->child[i]\n",i);
			
			word[length]=i;
			++length;
			//printf("\n%s is word and word[length] is %c and length is %d\n",word,word[length],length);
			if(cur->child[i]->eow==1){
				printf("\n");
				for(j=0;j<=length;j++){
					printf("%c",word[j]);
				}
				printf("\n");
			}
			display(cur->child[i]);
		}		
	}
	word[length]='\0';
	--length;
	return;
}

int search(struct trienode *root,char *key){
	int i,index;
	struct trienode *cur=root;
	for(i=0;key[i]!='\0';i++){
		index=key[i];
		if(cur->child[index]==NULL){
			return 0;
		}
		cur=cur->child[index];
	}
	if(cur->eow==1){
		return 1;
	}
	else{
		return 0;
	}
}

int isempty(struct trienode *root){
	int i;
	for(i=0;i<256;i++){
		if(root->child[i]!=NULL){
			return 0;
		}
	}
	return 1;
}

struct trienode *delete_word(struct trienode *root,char *key,int level,int length){
	if(root==NULL){
		return NULL;
	}
	if(level==length){
		if(root->eow){
			root->eow=0;
		}
		if(isempty(root)){
			free(root);
			root=NULL;
		}		
		return root;
	}
	int index=key[level];
	root->child[index]=delete_word(root->child[index],key,level+1,length);
	if(root->eow==0&&isempty(root)){
		free(root);
		root=NULL;
	}
	return root;
	
}

