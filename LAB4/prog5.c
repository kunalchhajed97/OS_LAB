#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	mode_t mode= S_IRWXU;
	int fp = creat("mytextfile.txt",mode);
	if(-1 == fp) exit(2);
	char* str = "Some random bs";
	int wr = write(fp,str,strlen(str));
	if(-1 == wr) exit(3);
	int cl = close(fp);
	if(-1 == cl) exit(4);
}