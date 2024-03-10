#include<stdio.h>
#include<stdlib.h>

struct ele{
	int data;
	int pty;
};

void display(struct ele *h,int count);
void insert(struct ele *h,struct ele key,int *count);
void heapify(struct ele *h,int n);
void delete_ele(struct ele *h,int *count);

int main(){
	struct ele pq[100];
	int ch;
	int count=0;
	struct ele temp;
	while(1){
		display(pq,count);
		printf("\n1.Insert\n2.Delete\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the data and pty\n");
				scanf("%d %d",&temp.data,&temp.pty);
				insert(pq,temp,&count);
				break;
			case 2:
				delete_ele(pq,&count);
				break;
				
		}
	}
}

void insert(struct ele *h,struct ele key,int *count){
	int j,i;
	i=*count;
	h[i]=key;
	++(*count);
	j=(i-1)/2;
	while(i>0&&key.pty>h[j].pty){
		h[i]=h[j];
		i=j;
		j=(i-1)/2;
	}
	h[i]=key;
}

void display(struct ele *h,int count){
	for(int i=0;i<count;i++){
		printf("%d %d\n",h[i].data,h[i].pty);
	}
}

void heapify(struct ele *h,int n){
	int i,j;
	struct ele key;
	j=0;
	key=h[j];
	i=2*j+1;
	while(i<=n){
		if(i+1<=n){
			if(h[i+1].pty>h[i].pty){
				i++;
			}
		}
		if(key.pty<h[i].pty){
			h[j]=h[i];
			j=i;
			i=2*j+1;
		}
		else{
			break;
		}
		h[j]=key;
	}
}

void delete_ele(struct ele *h,int *count){
	h[0]=h[*count-1];
	--(*count);
	heapify(h,*count-1);
}