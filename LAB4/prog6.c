#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char arr[1000];
	mode_t mode= S_IRWXU;
	int fp = creat("mytextfile2.txt",mode);
	if(-1 == fp) exit(2);
	int fp2 = open("mytextfile.txt",O_RDONLY);
	if(-1 == fp2) exit(2);
	int rd = read(fp2,arr,1000);
	if(-1 == rd) exit(5);
	int wr = write(fp,arr,rd);
	if(-1 == wr) exit(3);
	int cl = close(fp);
	int cl2 = close(fp2);
	if(-1 == cl) exit(4);
}