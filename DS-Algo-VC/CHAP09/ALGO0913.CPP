void ShowBTNode(BTree p) { //display the BTnode
  printf("(");
  for(int i=1; i<=p->keynum; i++)
    printf("%3d", p->key[i]);
  printf(" )");
}

int Search(BTree p, KeyType K) {
   for(int i=0;  i < p->keynum && p->key[i+1] <= K;  i++);
   return i;
}

Result SearchBTree(BTree T, KeyType K, int f) {  // �㷨9.13
   // ��m��B��T�ϲ��ҹؼ���K�����ؽ��(pt,i,tag)
   BTree p, q;
   int found, i, j=0;
   Result R;
   p = T;  q = NULL;  found = FALSE;  i = 0; 
                  // ��ʼ����pָ������㣬qָ��p��˫��
   while (p && !found) {
      if (f) {
         if (j) printf(" --> ");  
         ShowBTNode(p);           
      }
      i = Search(p, K);  // ��p->key[1..keynum]�в���i��
                         // ʹ�ã�p->key[i]<=K<p->key[i+1]
      if (i>0 && p->key[i]==K) found = TRUE;    // �ҵ�����ؼ���
      else { q = p;  p = p->ptr[i]; }
      j++;
   }
   if (found) {  // ���ҳɹ�
     R.pt = p;  R.i = i;  R.tag = 1;  
   } else {      // ���Ҳ��ɹ�
     R.pt = q;  R.i = i;  R.tag = 0; 
   }
   return R;              // ���ؽ����Ϣ: K��λ��(�����λ��)
} // SearchBTree