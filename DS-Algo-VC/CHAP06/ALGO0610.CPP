Status mix_mfset(MFSet &S, int i, int j) {  // �㷨6.10
   // S.nodes[i]��S.nodes[j]�ֱ�ΪS�����������ཻ���Ӽ�Si��Sj�ĸ����
   // �󲢼�Si��Sj��
   if (i<0 || i>S.n || j<0 || j>S.n)  return ERROR;
   if (S.nodes[i].parent>S.nodes[j].parent) {   // Si������Ա����Sj��
      S.nodes[j].parent+=S.nodes[i].parent;
      S.nodes[i].parent=j;
   } else {                                     // Sj��Ԫ�ر�Si��
      S.nodes[i].parent+=S.nodes[j].parent;
      S.nodes[j].parent=i;
   }
   return OK;
} // mix_mfset