int find_mfset(MFSet S, int i) {  // �㷨6.8
   // �Ҽ���S��i�����Ӽ��ĸ�
   int j;
   if (i<0 || i>S.n) return -1;   // i����S����һ�Ӽ��ĳ�Ա
   if (i==0)  
      printf("\t%d(%d%3d)\n",i,S.nodes[0].data,S.nodes[0].parent);
   for (j=i; S.nodes[j].parent>=0; j=S.nodes[j].parent)
      printf("\t%d(%d%3d)\n",j,S.nodes[j].data,S.nodes[j].parent);
   return 1;
}// find_mfset