void Select_MiniMax (LoserTree &ls, WorkArea wa, int q) { // �㷨11.6
  //��wa[q]�𵽰������ĸ��Ƚ�ѡ��MINIMAX��¼������qָʾ�����ڵĹ鲢��
  int t, p, temp;
  for (t=(w+q)/2, p=ls[t];  t>0;  t/=2, p=ls[t])
    if (wa[p].rnum<wa[q].rnum ||
        (wa[p].rnum==wa[q].rnum && wa[p].key<wa[q].key)) {
      temp=q;  q=ls[t];  ls[t]=temp;   // qָʾ�µ�ʤ����
    }
  ls[0] = q;
} // Select_MiniMax