#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void write_stderr(char text[])
{
	write(STDERR_FILENO, text, strlen(text));
}

void write_stdout(char text[])
{
	if (write(STDOUT_FILENO, text, strlen(text)) != strlen(text)) {
		write(STDERR_FILENO, "There was an error writing to standard out\n", 44);
		return;
    }
}

void display_err_wrr(char filename[], int status)
{
	if(status == 1)
	{
		return;
	}
	if(status == 0)
	{
		write_stderr("tail: cannot open ‘");
		write_stderr(filename);
		write_stderr("’ for reading: No such file or directory\n");
	}
	if(status == -1)
	{
		write_stderr("tail: cannot open ‘");
		write_stderr(filename);
		write_stderr("’ for reading: Permission denied\n");
	}
}

int check_file(char filename[])
{
	if( access(filename, F_OK ) != -1 ) 
	{
		if(access(filename, R_OK)!=-1)
		{
			display_err_wrr(filename, 1);
			//we can read it
			return 1;
		}
		else
		{
			display_err_wrr(filename, -1);
			//we cant read it
			return -1;
		}
    // file exists
	} 
	else 
	{
		display_err_wrr(filename, 0);
    	// file doesn't exist
    	return 0;
	}
}

int lines_in_file(char filename[])
{
	int filedesc = open(filename, O_RDONLY);
	int n;
	char buf;
	int lines = 1;
	if(filedesc < 0)
	{  
		//write_stderr("Problem opening the file.");
		check_file(filename);
		return;
	}
	while ((n=read(filedesc ,&buf,1))!=0)
	{
		if(buf == '\n')
		{
			lines++;
		}
	}
	close(filedesc);
	return lines;	
}

void read_file(char filename[])
{
	int filedesc = open(filename, O_RDONLY);
	if(filedesc < 0)
	{
		check_file(filename);
		return;
	}
	display_filename(filename);
	int n;
	char buf;
	int lines = lines_in_file(filename);
	int from_line = 0;
	int curr_line = 1;
	from_line = lines - 10;
	while ((n=read(filedesc ,&buf,1))!=0)
	{
		if(buf == '\n')
		{
			curr_line++;
		}
		if(curr_line >from_line)
		{
			write(STDOUT_FILENO ,&buf,1);
		}
	}

	close(filedesc);
}

void display_filename(char filename[])
{
	write_stdout("==> ");
	write_stdout(filename);
	write_stdout(" <==\n");
}

int main(int argc, char*argv[])
{
	for(int i = 1;i<argc;++i)	
	{
		read_file(argv[i]);
	}
}
