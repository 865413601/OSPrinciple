#include <stdio.h>
#define OFFSET 10*1024
#include <stdlib.h>

int main() {
	FILE *fp;

	char File_fread[OFFSET];

	fp = fopen("dest_file.txt", "r");

	// 读取位置定位到距离文件末尾倒数第二个10KB的起始位置
	fseek( fp, -OFFSET * 2, SEEK_END );
	//	写入10KB数据
	fread(File_fread, OFFSET, 1, fp);
	fp = fopen("dest_file_writ.txt", "w");
	fwrite(File_fread, sizeof(File_fread), 1, fp);


	fclose(fp);
	return 0;
}
