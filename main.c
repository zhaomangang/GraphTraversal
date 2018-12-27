#include"DFS.h"
#include"AdjacencyList.h"

int main()
{
	ALGraph G;
	CreateDG(&G);
	DFSTraverse(G);
	system("pause");
	return 0;
}