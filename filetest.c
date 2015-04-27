#include <stdio.h>
#include <mysql.h>


void get_data(MYSQL * con)
{
	char SQLString[500];
	sprintf(SQLString,"SELECT * from mixer_temp INTO OUTFILE '/tmp/data4.csv'FIELDS TERMINATED BY ',');
	printf("%s\n",SQLString);
	if(mysql_query(con,SQLString))
	{
		printf("%s\n",mysql_error(con));
	}
}
int main()
{

	MYSQL *con=mysql_init(NULL);
	if (con==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		return(1);
		
	}
	if (mysql_real_connect(con,"localhost","root","","process_control",0,NULL,0)==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		return(2);
	}
	get_data(con);
}
