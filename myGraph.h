#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class EdgeNode{ // 边节点类
private:
    int dest; // 边的终点下标（从0开始）
    EdgeNode* link; // 指向下一个边节点
    //int which; // 边的下标（从0开始）

public:
    char destData; // 边的终点值
    EdgeNode();
    EdgeNode(int, EdgeNode*);
    ~EdgeNode();

    int getDest();
    EdgeNode* getNext();

    void setDest(int);
    void setNext(EdgeNode*);
};

class VertexNode{ // 顶点节点类
private:
    char data; // 顶点节点值
    

public:
    //自己加的
    EdgeNode* firstEdge; // 边节点链表表头
    int serial; // 顶点的序列号（从0开始）
    int cnt = 0;

    VertexNode();
    VertexNode(char, EdgeNode*);
    ~VertexNode();

    char getData();
    EdgeNode* getFirstEdge();

    void setData(char);
    void setFirstEdge(EdgeNode*);
};

class MyGraph{ // 图类
private:
    int nodeNum; // 顶点数目
    int edgeNum; // 边数目
    VertexNode* VexList; // 邻接表

    int* src;
    int *dest;

public:
    MyGraph();
    MyGraph(int, int, char*, int*, int*);
    ~MyGraph();
    int getNodeNum();
    int getEdgeNum();
    string printGraph(); // 打印图

    // 辅助函数
    void DFS(int, int*, string&);
    void BFS(int, int*, string&);
    int getFirstNeighbor(int, int*);
    int getNextNeighbor(int, int, int*);

    //我加的
    char int2char(int n);
    int char2int(char c);

    // DFS、BFS函数
    string graph_BFS_Traverse();
    string graph_DFS_Traverse();
};


#endif // MYGRAPH_H_INCLUDED#ifndef MYGRAPH_H_INCLUDED
