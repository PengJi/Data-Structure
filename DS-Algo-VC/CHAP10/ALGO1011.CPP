void HeapSort(HeapType &H) {  // �㷨10.11
   // ��˳���H���ж�����
   int i;
   RedType temp;
   for (i=H.length/2; i>0; --i)  // ��H.r[1..H.length]���ɴ󶥶�
      HeapAdjust ( H, i, H.length );
      for (i=H.length; i>1; --i) {
         temp=H.r[i];
         H.r[i]=H.r[1];
         H.r[1]=temp;  // ���Ѷ���¼�͵�ǰδ������������Hr[1..i]��
                       // ���һ����¼�໥����
         HeapAdjust(H, 1, i-1);  // ��H.r[1..i-1] ���µ���Ϊ�󶥶�
      }
} // HeapSort