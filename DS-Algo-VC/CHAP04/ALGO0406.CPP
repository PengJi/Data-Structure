void get_next(SString T, int *next) {  // �㷨4.7
  int i=1;
  next[1]=0;
  int j=0;
  while (i<T[0]) {
    if(j==0 || T[i]== T[j]) {
      ++i;  ++j;  next[i] = j;
    } else j= next[j];
  }
}

int Index_KMP(SString S, SString T, int pos) {  // �㷨4.6
  // ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�
  // KMP�㷨�����У�T�ǿգ�1��pos��StrLength(S)��
  int next[255];
  int i = pos;
  int j = 1;
  get_next(T, next);
  while (i <= S[0] && j <= T[0]) {
    if (j == 0 || S[i] == T[j]) {  // �����ȽϺ���ַ�
      ++i;  ++j;
    } else j = next[j]; // ģʽ�������ƶ�
  }
  if (j > T[0]) return  i-T[0];   // ƥ��ɹ�
  else return 0;
} // Index_KMP
