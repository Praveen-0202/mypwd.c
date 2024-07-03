#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


#define max_len 4096

char* my_getcwd(char *buffer,size_t size)
{
	const char* self_cmd="/proc/self/cwd";

	ssize_t len = readlink(self_cmd,buffer,size-1);

	if(len!=-1)
	{
		buffer[len]='\0';
	        return buffer;
	}
	else{
		return NULL;
	}
}
int main()
{
	char buffer[max_len];

	if(my_getcwd(buffer,sizeof(buffer))!=NULL)
	{
             printf("%s\n",buffer);
	     
	}
	else
	{
		perror("my_getcwd error");
		return 1;
	}
	return 0;
}

