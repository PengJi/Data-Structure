Status SubString(SString &Sub, SString S, int pos, int len) { 
   // �㷨4.3
   // ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
   // ���У�1��pos��StrLength(S)��0��len��StrLength(S)-pos+1��
   int i;
   if (pos < 1 || pos > S[0] || len < 0 || len > S[0]-pos+1)
      return ERROR;
   for(i=1; i<=len; i++)
      Sub[i] = S[pos+i-1];
   Sub[0] = len;
   return OK;
} // SubString