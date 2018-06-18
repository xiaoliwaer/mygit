#include <stdio.h>
#include <stdlib.h> //head file for malloc 
#include <string.h>//head file for strcmp
#define ERORR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int status;
#define MaxInt 32767 //���Ȩֵ
#define MVNum 100 //���������󶥵���
typedef char VerTexType[10];//ֻ����������������
typedef int ArcType;//ֻ�Ǳ���Ȩֵ

typedef struct AdjMatrix{ 
	//����Ȩ���ڽӾ���ĵĶ���
    VerTexType* Vertices;  //������Ϣ������
    ArcType** arcs; //����Ϣ������
    int vexnum; //������
    int arcnum; //����
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
    return t;//t = G.vexnumt��Ϊֵ����ʱ����ʾ��λʧ��  
}


status createUDN(AMGraph &g){
//�����ڴ�
	g.Vertices=(VerTexType*)malloc(sizeof(VerTexType)*MVNum);
	g.arcs=( ArcType**)malloc(sizeof(ArcType*)*MVNum);
	for(int i=0;i<MVNum;i++){
	g.arcs[i]=(ArcType*)malloc(sizeof(ArcType)*MVNum);
	}
	g.vexnum=(int)malloc(sizeof(int));
	g.arcnum=(int)malloc(sizeof(int));
 printf ("�������ܶ�����:\n");  
    scanf ("%d",&g.vexnum);
	printf ("�������ܱ���:\n");  
	scanf ("%d",&g.arcnum); 
	for(i=0;i<g.vexnum;i++){
		   printf ("������㸳ֵ\n");
		scanf("%s",&g.Vertices[i]);
	}
	for(i=0;i<g.vexnum;i++)
	for(int j=0;j<g.vexnum;j++){
		g.arcs[i][j]=MaxInt;
	}
	for(int k=0;k<g.arcnum;k++){
	 printf ("����Ҫ��%d���ߵĵ�һ���˵������:\n",k+1);
		 char v1[10];
		 char v2[10];
		 int w;
		 int v1locate;int v2locate;
		scanf ("%s",&v1);
	 printf ("����Ҫ��%d���ߵĵڶ����˵������:\n",k+1);
		scanf("%s",&v2);
		printf("����Ȩֵ");
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
    printf("\n����������Ϣ:\n");
    for(i=0;i<g.vexnum;i++)
        printf("%s\t",g.Vertices[i]);

    printf("\n����ڽӾ���:\n");
    printf("\t");
    for(i=0;i<g.vexnum;i++)
        printf("%s\t",g.Vertices[i]);

    for(i=0;i<g.vexnum;i++)
    { 
        printf("\n%8s",g.Vertices[i]);
        for(j=0;j<g.vexnum;j++)
        { 
        if(g.arcs[i][j]==32767) 
        //����֮��������ʱȨֵΪĬ�ϵ�32767��
        //������ͼ��һ����"0"��ʾ��������ͼ��һ����"��",
        //����Ϊ�˷���ͳһ��� "��"
            printf("%8s", "��");
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