#include <stdio.h>
#include <stdlib.h> //head file for malloc 
#include <string.h>//head file for strcmp
#define ERORR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int status;
#define MaxInt 32767 //最大权值
#define MVNum 100 //定义最大最大顶点数
typedef char VerTexType[10];//只用作保留顶点名称
typedef int ArcType;//只是保留权值

typedef struct AdjMatrix{ 
	//包含权的邻接矩阵的的定义
    VerTexType* Vertices;  //顶点信息的数组
    ArcType** arcs; //边信息的数组
    int vexnum; //顶点数
    int arcnum; //边数
}AMGraph;

int LocateVex (AMGraph &G,char* vex) {  
    int i,t;  
    for (i=0; i<G.vexnum; i++) {  
        if((strcmp(G.Vertices[i], vex))==0) { //compare vexname
            t=i;  
            break;  
        }  
 
    }  
    if (t == G.vexnum){
	printf("vextice not exist!");
		exit(ERORR);} 
    return t;//t = G.vexnumt作为值返回时，表示定位失败  
}


status createUDN(AMGraph &g){
//开辟内存
	g.Vertices=(VerTexType*)malloc(sizeof(VerTexType)*MVNum);
	g.arcs=( ArcType**)malloc(sizeof(ArcType*)*MVNum);
	for(int i=0;i<MVNum;i++){
	g.arcs[i]=(ArcType*)malloc(sizeof(ArcType)*MVNum);
	}
	g.vexnum=(int)malloc(sizeof(int));
	g.arcnum=(int)malloc(sizeof(int));
 printf ("请输入总顶点数:\n");  
    scanf ("%d",&g.vexnum);
	printf ("请输入总边数:\n");  
	scanf ("%d",&g.arcnum); 
	for(i=0;i<g.vexnum;i++){
		   printf ("请给顶点赋值\n");
		scanf("%s",&g.Vertices[i]);
	}
	for(i=0;i<g.vexnum;i++)
	for(int j=0;j<g.vexnum;j++){
		g.arcs[i][j]=MaxInt;
	}
	for(int k=0;k<g.arcnum;k++){
	 printf ("输入要第%d条边的第一个端点的名称:\n",k+1);
		 char v1[10];
		 char v2[10];
		 int w;
		 int v1locate;int v2locate;
		scanf ("%s",&v1);
	 printf ("输入要第%d条边的第二个端点的名称:\n",k+1);
		scanf("%s",&v2);
		printf("输入权值");
		scanf("%d",&w);
		v1locate=LocateVex(g,v1);
		printf("v1locate:%d\n",LocateVex(g,v1));
		v2locate=LocateVex(g,v2);
		printf("v2locate:%d\n",LocateVex(g,v2));
		g.arcs[v1locate][v2locate]=w;
		g.arcs[v2locate][v1locate]=g.arcs[v1locate][v2locate];
		}
   

	return OK;
}

status showAMGraph(AMGraph &g){
	int i,j;
    printf("\n输出顶点的信息:\n");
    for(i=0;i<g.vexnum;i++)
        printf("%s\t",g.Vertices[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t");
    for(i=0;i<g.vexnum;i++)
        printf("%s\t",g.Vertices[i]);

    for(i=0;i<g.vexnum;i++)
    { 
        printf("\n%8s",g.Vertices[i]);
        for(j=0;j<g.vexnum;j++)
        { 
        if(g.arcs[i][j]==32767) 
        //两点之间无连接时权值为默认的32767，
        //在无向图中一般用"0"表示，在有向图中一般用"∞",
        //这里为了方便统一输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",g.arcs[i][j]);
        }
        printf("\n");   
    }
return OK;
}

status destroyedAMGraph(AMGraph &g){
	free(g.Vertices);
	for(int i=0;i<MVNum;i++)
	free(g.arcs[i]);
	free(g.arcs);
	free((int*)g.arcnum);
	free((int*)g.vexnum);
	return OK;
}

void main(int argc,char* argv[]){
	AMGraph g;
	createUDN(g);
	showAMGraph(g);
	destroyedAMGraph(g);

}