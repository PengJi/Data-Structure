Status MergeFile (FILE *f, FILE *g, FILE *h) {  // �㷨12.1
  // �ɰ��ؼ��ֵ�������ķǿ�˳���ļ�f��g�鲢�õ����ļ�h�������ļ���
  // �Ѵ򿪣����У�f��gΪֻ���ļ����ļ��и�����һ�����ؼ��ּ�¼��
  // ��g�ļ��жԸü�¼�Ĳ���Ϊ���롣hΪֻд�ļ�
  RcdType fr, gr;
  fread(&fr, sizeof(RcdType), 1, f);
  fread(&gr, sizeof(RcdType), 1, g);
  while (!feof(f) || !feof(g)) {
    if (fr.key < gr.key) {                   // ����"��"���ļ��м�¼
      fwrite(&fr, sizeof(RcdType), 1, h);
      /*if (!feof(f))*/ fread(&fr, sizeof(RcdType), 1, f);
    } else if (gr.code=='D' && fr.key==gr.key) {  
      // ɾ��"��"���ļ��м�¼����������
      /*if (!feof(f))*/ fread(&fr, sizeof(RcdType), 1, f);
      /*if (!feof(g))*/ fread(&gr, sizeof(RcdType), 1, g);
    } else if (gr.code=='I' && fr.key>gr.key) {   
      // ���룬����P��gr�ӹ�Ϊh�Ľṹ
      fwrite(P(gr), sizeof(RcdType), 1, h);
      /*if (!feof(g))*/ fread(&gr, sizeof(RcdType), 1, g);
    } else if (gr.code=='U' && fr.key==gr.key) {  
      // ����"��"���ļ��м�¼
      fwrite(Q(fr, gr), sizeof(RcdType), 1, h);  
          // ����Q��fr��gr�鲢��һ��h�ṹ�ļ�¼
      /*if (!feof(f))*/ fread(&fr, sizeof(RcdType), 1, f);
      /*if (!feof(g))*/ fread(&gr, sizeof(RcdType), 1, g);
    } else return ERROR;    // ������Ϊ�������
  }  // while 
  return OK;
} // MergeFile