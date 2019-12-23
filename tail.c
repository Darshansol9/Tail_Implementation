#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf [1024];
char buf1 [1024];
void readWWrite(int fd, int line)
{

int i,totalLines,j,n,count;
totalLines = 0;
j = 0;
count = 0;
//Read the contents either from a file or from stdin and store it in a buffer.

while((n = read(fd,buf,sizeof(buf))) > 0 )
{

	for (i = 0; i<n;i++)
	{
		if(buf[i] != '\n')
			buf1[j] = buf[i];

		else{
			buf1[j] = buf[i];
			totalLines++;
			}

		j++;

	} //for

} //while



//count no of lines in a file and print only user input no of lines.

for (i = 0; i< j; i++) 
    {
      if (count >= (totalLines - line))          
      {
        printf(1,"%c",buf1[i]);
      }
      else if (totalLines < line)                
      {
        printf(1,"%c",buf1[i]);
      }
      else if (buf1[i] == '\n')         
      {
        count++;
        
      }
    }


} //function


int 
main(int argc, char *argv[]) {
  int i;
  int fd = 0;	        // default is set to 0 if file not specified it will read from stdin
  int d_count = 10;	// will read the last 10 lines by default
  char *file;	        // check whether file name has been provided or not
  char check_count;     //this check the count of lines to be printed.

  file = "";            //default value
     
  if (argc <= 1) 
  {	
    readWWrite(0,10);	// default case with 10 lines and stdin input
    exit();
  }

  else {
    for (i = 1; i < argc; i++) 
    {
      check_count = *argv[i];	
				
      if (check_count == '-') //checks the num of lines inputed if any
      {             		
        argv[i]++;
        d_count = atoi(argv[i]++); //copy the count in d_count
      }
				
      else 
      {	
        if ((fd = open(argv[i], 0)) < 0) 
        {
          printf(1, "tail: cannot open %s\n", argv[i]);
          exit();
        }
	
	file = argv[i];  //placing the file name to avoid default case
      }
    }
  if(!strcmp(file,"")){
	readWWrite(0,d_count);}  //if no file is provided still if given tail -5 it will print only the given user input lines or CASE 2 tail given, only prints default 10 lines
  else{
	readWWrite(fd,d_count);
  	close(fd);
	}

exit(); 
} //else


}//main
