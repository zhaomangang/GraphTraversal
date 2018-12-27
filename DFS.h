/*
文件名：DFS.h
描述: 深度优先搜索
时间：2018.12.25
*/

#pragma once
#include"AdjacencyList.h"	//图的邻接表存储

_Bool visited[MAX_VERTEX_NUM];	//访问标志数组


void VisitFunc(ALGraph G, int v)
{
	//访问顶点v
	printf("%d ", G.vretices[v].data);		
}


int FirstAdjVex(ALGraph G, int v)
{
	//首先访问的顶点
	if (G.vretices[v].firstarc == NULL) return -1;
	return G.vretices[v].firstarc->adjvex;
}

int NextAdjVex(ALGraph G, int v, int w)
{
	//下一个需要访问的顶点
	ArcNode *p=G.vretices[v].firstarc;
	while (w != p->adjvex)
		p = p->nextarc;
	if (p->nextarc != NULL) return p->nextarc->adjvex;
	else return -1;
}

void DFS(ALGraph G, int v)
{
	//从第v个顶点出发深度优先遍历图G
	int w;
	visited[v] = 1;
	VisitFunc(G, v);	//访问第v个顶点
	for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w))
		if (!visited[w])	DFS(G, w);	//对未被访问的邻接顶点递归调用DFS
}

void DFSTraverse(ALGraph G)
{
	//对图G做深度优先遍历
	int v;
	for (v = 0; v < G.vexnum; v++)	//访问标志数组初始化（使其全部为false）
		visited[v] = 0;
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) DFS(G, v);
}




