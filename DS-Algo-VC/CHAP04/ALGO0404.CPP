Status StrInsert(HString &S, int pos, HString T) {  // �㷨4.4
   // 1��pos��StrLength(S)��1���ڴ�S�ĵ�pos���ַ�֮ǰ���봮T��
   int i;
   if (pos < 1 || pos > S.length+1)  // pos���Ϸ�
      return ERROR;  
   if (T.length) {    // T�ǿ�,�����·���ռ�,����T
      if (!(S.ch = (char *)realloc(S.ch,(S.length+T.length+1)
                                        *sizeof(char))))
         return ERROR;
      for (i=S.length-1; i>=pos-1; --i)  // Ϊ����T���ڳ�λ��
         S.ch[i+T.length] = S.ch[i];
      for (i=0; i<T.length; i++)         // ����T
         S.ch[pos-1+i] = T.ch[i]; 
      S.length += T.length;
   }
   return OK;
} // StrInsert