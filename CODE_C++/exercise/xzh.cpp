#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXVNUM 50


int getLength(int Graph[][MAXVNUM], int n);

int main()
{
    int numV; // number of vertex
    int numE; // numver of edge
    int Graph[MAXVNUM][MAXVNUM];
    int i, j;
    int a, b, c;
    int length;

    scanf("%d%d", &numV, &numE);

    //��ʼ��,-1��ʾ��������֮��û�б�����
    for (i = 0; i < numV; i++)
        for (j = 0; j < numV; j++) {
            Graph[i][j] = INT_MAX;
        }

    //����ͼ���ڽӾ���
    for (i = 0; i < numE; i++) {

        scanf("%d%d%d", &a, &b, &c);
        Graph[a - 1][b - 1] = c;
        Graph[b - 1][a - 1] = c;

    }

    length = getLength(Graph, numV);
    printf("%d", length);

    return 0;
}

//����С�������Ĵ�Ȩ·������
int getLength(int Graph[][MAXVNUM], int n) {

    int lowcost[n];
    int teend[n];
    int mincost;
    int length = 0;//��Ȩ·������
    int i, j, k;
    int temp;

    lowcost[0] = 0;

    for (i = 0; i < n; i++) {
        teend[i] = 0;
        lowcost[i] = Graph[0][i];
    }

    for (i = 1; i < n; i++) {

        mincost = INT_MAX;

        j = 1;

        while (j < n) {

            if (lowcost[j] > 0 && mincost > lowcost[j]) {

                mincost = lowcost[j];
                k = j;
            }

            j++;
        }

        temp = teend[k];
        length += Graph[k][temp];
        lowcost[k] = 0;

        for (j = 0; j < n; j++) {

            if (Graph[k][j] < lowcost[j]) {
                lowcost[j] = Graph[k][j];
                teend[j] = k;
            }

        }

    }

    return length;

}


