#include <stdio.h>
#define OFFSET 10*1024
#include <stdlib.h>

int main() {
	FILE *fp;

	char File_fread[OFFSET];

	fp = fopen("dest_file.txt", "r");

	// ��ȡλ�ö�λ�������ļ�ĩβ�����ڶ���10KB����ʼλ��
	fseek( fp, -OFFSET * 2, SEEK_END );
	//	д��10KB����
	fread(File_fread, OFFSET, 1, fp);
	fp = fopen("dest_file_writ.txt", "w");
	fwrite(File_fread, sizeof(File_fread), 1, fp);


	fclose(fp);
	return 0;
}
