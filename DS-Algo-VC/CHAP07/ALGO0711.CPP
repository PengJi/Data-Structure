void  DFSArticul(ALGraph G, int v0 ) {  // �㷨7.11
  // �ӵ�v0���������������ȱ���ͼG�����Ҳ�����ؽڵ�
  int min,w;
  struct ArcNode *p;
  visited[v0] = min = ++count;  // v0�ǵ�count�����ʵĶ���
  for (p=G.vertices[v0].firstarc; p!=NULL; p=p->nextarc) { 
    // ���v0��ÿ���ڽӶ���
    w = p->adjvex;              // wΪv0���ڽӶ���
    if (visited[w] == 0) {      // wδ�������ʣ���v0�ĺ���
      DFSArticul(G, w);         // ����ǰ���low[w]
      if (low[w] < min)  min = low[w];
      if (low[w] >= visited[v0]) 
        printf(v0, G.vertices[v0].data);  // ����ؽڵ�
    } 
    else if (visited[w] < min)  min = visited[w];  
        // w�ѱ����ʣ�w��v0���������ϵ�����   
  }//for
  low[v0] = min;
} // DFSArticul