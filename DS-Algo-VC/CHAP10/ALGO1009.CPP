void SelectSort(SqList &L) {  // �㷨10.9
  // ��˳���L����ѡ������
  int i,j;
  for (i=1; i<L.length; ++i) { // ѡ���iС�ļ�¼����������λ
    j = SelectMinKey(L, i);  // ��L.r[i..L.length]��ѡ��key��С�ļ�¼
    if (i!=j) {                // L.r[i]����L.r[j];   ���i����¼����
      RedType temp;
      temp=L.r[i];
      L.r[i]=L.r[j];
      L.r[j]=temp;    
    } 
  }
} // SelectSort