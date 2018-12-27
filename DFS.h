/*
�ļ�����DFS.h
����: �����������
ʱ�䣺2018.12.25
*/

#pragma once
#include"AdjacencyList.h"	//ͼ���ڽӱ�洢

_Bool visited[MAX_VERTEX_NUM];	//���ʱ�־����


void VisitFunc(ALGraph G, int v)
{
	//���ʶ���v
	printf("%d ", G.vretices[v].data);		
}


int FirstAdjVex(ALGraph G, int v)
{
	//���ȷ��ʵĶ���
	if (G.vretices[v].firstarc == NULL) return -1;
	return G.vretices[v].firstarc->adjvex;
}

int NextAdjVex(ALGraph G, int v, int w)
{
	//��һ����Ҫ���ʵĶ���
	ArcNode *p=G.vretices[v].firstarc;
	while (w != p->adjvex)
		p = p->nextarc;
	if (p->nextarc != NULL) return p->nextarc->adjvex;
	else return -1;
}

void DFS(ALGraph G, int v)
{
	//�ӵ�v���������������ȱ���ͼG
	int w;
	visited[v] = 1;
	VisitFunc(G, v);	//���ʵ�v������
	for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w))
		if (!visited[w])	DFS(G, w);	//��δ�����ʵ��ڽӶ���ݹ����DFS
}

void DFSTraverse(ALGraph G)
{
	//��ͼG��������ȱ���
	int v;
	for (v = 0; v < G.vexnum; v++)	//���ʱ�־�����ʼ����ʹ��ȫ��Ϊfalse��
		visited[v] = 0;
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) DFS(G, v);
}




