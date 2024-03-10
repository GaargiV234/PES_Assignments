#include<stdio.h>
#include<stdlib.h>

int a[100][100];
int q[100];
int visit[100];
int visitdfs[100];
int f,r,n;

int isempty();
int qdelete();
void qinsert(int val);
void bfs(int src);
void dfs(int src);
void creategraph();

int main(){
	f=r=-1;
	int src;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	creategraph();
	printf("\nEnter the source vertex\n");
	scanf("%d",&src);
	printf("\nBFS:\n");
	bfs(src);
	printf("\nDFS:\n");
	dfs(src);
	printf("\n");
}

void creategraph(){
	int src,dest;
	printf("\nEnter the source and destination of every edge\n");
	while(1){
		scanf("%d %d",&src,&dest);
		if(src==0&&dest==0){
			break;
		}
		a[src][dest]=1;
	}
}


int isempty(){
	if(f==-1){
		return 1;
	}
	return 0;
}

int qdelete(){
	if(f==-1){
		return -1;
	}
	int ret=q[f];
	if(r==f){
		r=f=-1;
		return ret;
	}	
	f++;
	return ret;
}

void qinsert(int val){
	if(f==-1){
		f=r=0;
		q[0]=val;
	}
	else{
		r++;
		q[r]=val;
	}
}

void bfs(int src){
	int i=0;
	qinsert(src);
	visit[src]=1;
	printf("%d ",src);
	while(!isempty()){
		src=qdelete();
		for(i=1;i<=n;i++){
			if(a[src][i]==1&&visit[i]==0){
				visit[i]=1;
				qinsert(i);
				printf("%d ",i);
			}
		}
	}
}

void dfs(int src){	
	visitdfs[src]=1;
	printf("%d ",src);	
		
	for(int i=1;i<n;i++){
		if(a[src][i]==1&&visitdfs[i]==0){
			dfs(i);
		}
	}
	
}