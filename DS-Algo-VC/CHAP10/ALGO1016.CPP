void Collect(SLList &L, int i, ArrType f, ArrType e) {  // �㷨10.16
  // ���㷨��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ��������ӳ�
  // һ��������e[0..RADIX-1]Ϊ���ӱ���βָ��
  int j,t;
  for (j=0; !f[j]; j++);  // �ҵ�һ���ǿ��ӱ���succΪ���̺���: ++
  L.r[0].next = f[j];  // L.r[0].nextָ���һ���ǿ��ӱ��е�һ�����
  t = e[j];
  while (j<RADIX) {
    for (j=j+1; j<RADIX && !f[j]; j++);       // ����һ���ǿ��ӱ�
    if (j<RADIX) // ���������ǿ��ӱ�
      { L.r[t].next = f[j];  t = e[j]; }
  }
  L.r[t].next = 0;   // tָ�����һ���ǿ��ӱ��е����һ�����
} // Collect