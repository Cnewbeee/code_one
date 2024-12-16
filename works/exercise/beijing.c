#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 618
#define INF 0x3f3f3f3f

struct Station {
	char name[30];
	int isChange;
};

struct Vertex {
	int weight;
	int lineID;
};

struct Station stationList[M];
struct Vertex graph[M][M];

int lineID, stationNum, lineNum, isChange, verNum;

int prev[M], dist[M], path[M], top;
char start[30], end[30];

void DrawMap(FILE *fp)
{
	int i, j, currID, lastID;
	char name[30];

	fscanf(fp, "%d", &lineNum);	

	for(i = 0; i < lineNum; i++)
	{
		fscanf(fp, "%d %d", &lineID, &stationNum);
		lastID = -1;

		for(j = 0; j < stationNum; j++)
		{
			fscanf(fp, "%s %d", name, &isChange);
			currID = Search(name);
			
			if(currID == -1)
			{
				strcpy(stationList[verNum].name, name);
				stationList[verNum].isChange = isChange;

				if(lastID != -1)
				{
					graph[lastID][verNum].lineID = graph[verNum][lastID].lineID = lineID;
					graph[lastID][verNum].weight = graph[verNum][lastID].weight = 1;
				}
				lastID = verNum;
				verNum++;
			}
			else
			{
				if(lastID != -1)
				{
					graph[lastID][currID].lineID = graph[currID][lastID].lineID = lineID;
					graph[lastID][currID].weight = graph[currID][lastID].weight = 1;
				}
				lastID = currID;
			}
		}
	}
}

int Search(char *s)
{
	int i;
	for(i = 0; i < verNum; i++)
		if(strcmp(s, stationList[i].name) == 0)
			return i;
	return -1;
}

void dijkstra(int src, int dest)
{
	int i, j, k, min, tmp;
	int flag[M];

	for (i = 0; i < verNum; i++)
	{
		flag[i] = 0;
		prev[i] = src;
		dist[i] = graph[src][i].weight;
	}

	dist[src] = 0, flag[src] = 1;

	for (i = 0; i < verNum - 1; i++)
	{
		min = INF;

		for (j = 0; j < verNum; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}

		flag[k] = 1;

		if(k == dest) return;

		for (j = 0; j < verNum; j++)
		{
			tmp = (graph[k][j].weight == INF ? INF : (min + graph[k][j].weight));
			if (flag[j] == 0 && (tmp < dist[j]) && graph[k][j].lineID > 0)
			{
				dist[j] = tmp;
				prev[j] = k;
			}
		}
	}
}

void PrintPath(int start, int end)
{		
	int i, last = start, length = 1, u = path[top - 1];
	int lineId = graph[last][u].lineID;

	printf("%s-%d", stationList[start].name, lineId);
	last = u;

	for(i = top - 2; i >= 0; i--)
	{
		u = path[i];
		if(lineId != graph[last][u].lineID)
		{
			lineId = graph[last][u].lineID;
			printf("(%d)-%s-%d", length, stationList[last].name, lineId);
			length = 0;
		}
		length++;
		last = u;
	}

	printf("(%d)-%s", length, stationList[end].name);
}

int main()
{	
	int i, j, v1, v2, t;
	FILE *fp = fopen("bgstations.txt", "r");

	scanf("%s %s", start, end);

	for(i = 0; i < M; i++)
		for(j = 0; j < M; j++)
		{	
			graph[i][j].weight = graph[j][i].weight = INF;
			graph[i][j].lineID = graph[j][i].lineID = 0;
		}

	DrawMap(fp);
	v1 = Search(start);
	v2 = Search(end);
	dijkstra(v1, v2);

	for(t = v2; t != v1; t = prev[t])
	{
		path[top] = t;
		top++;
	}

	PrintPath(v1, v2);

	return 0;
}
