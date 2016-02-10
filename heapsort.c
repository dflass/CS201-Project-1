//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// heapsort.c				 	 					//
// Main file. Processes formal	args. 				//
// Gets ints from file into heap. Heapify. Print. 	//
//////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "heap.h"


int description = 0;    		// option -v  to display name and other   
int direction = 0;     			// option -d to sort in decreasing order	
char *f = NULL;					// filename

int ProcessOptions(int,char **);
void Fatal(char *,...);
heap *intExtraction(char *);

int main(int argc,char **argv)
    {
//	printf("error");
    int argIndex;
//	printf("error");
    argIndex = ProcessOptions(argc,argv);
//	printf("error");								//WHY IS THIS AN ERROR

	if (argIndex == argc)							//if the only command line arguements are options
	{
		if(description == 1)						//prints description if -v is arguement
		{
		printf("David Lass, CS201, Project 1");
		printf("This design runs in O(nlog(n)) time. \nThe program was timed using the gcc compiler \"time ./heapsort integers\"\n");
		printf("The following table shows the input size and the time for 5 trials along with the average time\n");
		printf("N \t | Trial 1 \t | Trial 2 \t | Trial 3 \t | Trial 4 \t | Trial 5 \t | Average \n");
		printf("50000\t | 3.827 \t | 4.078 \t | 3.155 \t | 3.358 \t | 3.232 \t | 3.53 \n");
		printf("100000\t | 3.108 \t | 3.983 \t | 3.968 \t | 3.624 \t | 3.936 \t | 3.7238 \n");
		printf("200000\t | 3.452 \t | 4.154 \t | 4.514 \t | 4.706 \t | 4.342 \t | 4.2336 \n");
		printf("400000\t | 6.92 \t | 5.874 \t | 6.482 \t | 5.42 \t | 4.498 \t | 5.8388 \n");
		printf("800000\t | 7.42 \t | 8.639 \t | 9.78 \t | 8.421 \t | 8.593 \t | 8.5706 \n");
		}
		return 0;
	}
    else											//if there are additional command line arguements
        {											//set the filename to the first arguement that is not an option.
        f = argv[argIndex];
        }

	heap *h = intExtraction(f);						//makes heap from integers in file
	
	if(description == 1)
	{
		printf("David Lass, CS201, Project 1");
		printf("This design runs in O(nlog(n)) time. \nThe program was timed using the gcc compiler \"time ./heapsort integers\"\n");
		printf("The following table shows the input size and the time for 5 trials along with the average time\n");
		printf("N \t | Trial 1 \t | Trial 2 \t | Trial 3 \t | Trial 4 \t | Trial 5 \t | Average \n");
		printf("50000\t | 3.827 \t | 4.078 \t | 3.155 \t | 3.358 \t | 3.232 \t | 3.53 \n");
		printf("100000\t | 3.108 \t | 3.983 \t | 3.968 \t | 3.624 \t | 3.936 \t | 3.7238 \n");
		printf("200000\t | 3.452 \t | 4.154 \t | 4.514 \t | 4.706 \t | 4.342 \t | 4.2336 \n");
		printf("400000\t | 6.92 \t | 5.874 \t | 6.482 \t | 5.42 \t | 4.498 \t | 5.8388 \n");
		printf("800000\t | 7.42 \t | 8.639 \t | 9.78 \t | 8.421 \t | 8.593 \t | 8.5706 \n");
	}
	if (h==0)
	{
		return 0;
	}
	heapifys(h, direction);							//min-heapify or max-heapify based on direction
	
	while(!isEmptyH(h)){							//extracts root to print numbers in order
		printf("%d ", extract(h, direction));
	}
	
    return 0;
    }
	
heap *intExtraction(char *fileName)			//A funtion to scan a file for numbers and add those numbers to a heap. Returns that heap
{
//	printf("Error?");						//WHY IS THIS AN ERROR, I DONT UNDERSTAND???
  FILE* file = fopen (fileName, "r");
//	printf("not an error");					//This is not an error unless the first printf happens.
  
  int i = 0;
  if(fscanf (file, "%d", &i)==EOF)
  {
	  return 0;
  }
  else{
//	printf("does it reach this?");
	  node *s = newTreeNode(i);	  
	  heap *h = newHeap(s);
	    
	  while (fscanf (file, "%d", &i)!=EOF)	//loops until file is empty and all integers are added to heap
	{  
		node *temp = newTreeNode(i);
		add(h, temp);
    }
	
	return h;					
	
  }
  
  fclose (file);        
}


int ProcessOptions(int argc, char **argv)	//Obtained from "options.c" file on Beastie site
{											//takes the input command line arguements and 
    int argIndex;							//processes the arguements

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-')		//loops arguements
        {
        if (argv[argIndex][1] == '\0') return argIndex;

        switch (argv[argIndex][1])			//switch over possible arguements
            {
            case 'v':
                description = 1;
                break;
			case 'd':
                direction = 1;
                break;
            default:
                Fatal("option %s not understood\n",argv[argIndex]);
            }

        ++argIndex;
        }

    return argIndex;
}

//////////////////////
//	Error handling	//
//////////////////////
void Fatal(char *fmt, ...)		
    {
    va_list ap;												

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
    }