#include <stdio.h>
#include <populate.c>
#include <my_global.h>
#include <mysql.h>
#include <fstream.h>
int main()
{
	FILE * fp;
	fp = fopen("data.csv","w");
	if (fp)
	{	
		fprintf(fp,"hello\n");
		fclose(fp);
	}
}
