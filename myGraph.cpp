#include "myGraph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;


EdgeNode::EdgeNode(){
    //pass
}

EdgeNode::EdgeNode(int dest, EdgeNode* link){
    this->dest = dest;
    this->link = link;
}

EdgeNode::~EdgeNode(){
    //pass
}

int EdgeNode::getDest(){
    return dest;
}

EdgeNode* EdgeNode::getNext(){
    return link;  //返回下一个节点的指针
}

void EdgeNode::setDest(int dest){
    this->dest = dest;
}

void EdgeNode::setNext(EdgeNode* link){

}

VertexNode::VertexNode(){
    this->firstEdge = NULL;  //初始化为NULL
}

VertexNode::VertexNode(char data, EdgeNode* firstEdge){
    this->data = data;
    this->firstEdge = NULL;
}

VertexNode::~VertexNode(){
    //pass
}

char VertexNode::getData(){
    return data;
}

EdgeNode* VertexNode::getFirstEdge(){
    return firstEdge;
}

void VertexNode::setData(char data){
    this->data = data;
}   

void VertexNode::setFirstEdge(EdgeNode* firstEdge){
    if(this->firstEdge == NULL){
        this->firstEdge = firstEdge;
    }
    else{
        EdgeNode* cur = firstEdge;
        while(cur->getNext() != NULL){
            cur = cur->getNext();
        }
        cur->setNext(firstEdge);  //设置为下一个节点
    }
    cout << "setFirstEdge " << data << endl;  //调试用
    cout << endl << "after setFirstEdge " << firstEdge << endl;  //调试用
}

MyGraph::MyGraph(){
    //pass
}

MyGraph::MyGraph(int nodeNum, int edgeNum, char* nodeList, int* edgeStartList, int* edgeEndList){
    this->nodeNum = nodeNum;
    this->edgeNum = edgeNum;

    //src = edgeStartList;
    //dest = edgeEndList;
    VexList = new VertexNode[nodeNum]; 

    //先设置顶点的data
    for(int i = 0; i < nodeNum; i++){
        VertexNode newNode = VertexNode(nodeList[i], NULL);  //创建节点
        newNode.firstEdge = NULL;  //初始化为NULL
        
        VexList[i] = newNode;  //设置到数组中
        //VexList[i].serial = i;  
        VexList[i].setData (nodeList[i]);
    }
    //再设置边
    for(int i = 0; i < edgeNum; i++){
        cout << "set edge " << i << endl;  //调试用
        //注意到，设置
        int curStart = edgeStartList[i];  //curStart是边的起点结点的序号
        int curEnd = edgeEndList[i];    //curEnd是边的终点结点的序号
        
        //创建了一个新的边
        EdgeNode* newEdge = new EdgeNode();

        //对于这个新的边，我们操作他
        //首先我们应该设置两条边
        //一条是这个方向，一条是反过来的方向
    }
}

MyGraph::~MyGraph(){
    //pass
}

int MyGraph::getNodeNum(){
    return nodeNum;
}

int MyGraph::getEdgeNum(){
    return edgeNum;
}

string MyGraph::printGraph(){
    cout << "printGraph" << endl;  //调试用
    cout << VexList[0].getData() << endl;  //调试用

    for(int i = 0; i < nodeNum; i++){
        cout << VexList[i].getData() << ":";
        EdgeNode* cur = VexList[i].getFirstEdge();
        while(cur != NULL){
            cout << int2char(cur->getDest()) << " ";
            //cur = cur->link;  //获取下一个节点
        }
    }
        cout << endl;
}
    

int MyGraph::getFirstNeighbor(int v, int* visited){
    //pass
}

int MyGraph::getNextNeighbor(int v, int w, int* visited){

}

void MyGraph::DFS(int v, int* visited, string& result){

}

string MyGraph::graph_DFS_Traverse(){

}

void MyGraph::BFS(int v, int* visited, string& result){

}

string MyGraph::graph_BFS_Traverse(){

}


char MyGraph::int2char(int n){
    for(int i = 0; i < this->nodeNum; i++){
        if(i == n){
            return this->VexList[i].getData();  //返回对应的字符
        }
    }
}
