#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int solve_file(const char* file_path)
{
	printf("Input file: %s\n", file_path);
	FILE* f;

    f = fopen(file_path, "r");
    if(f == NULL){
		fputs("Cannot open %s file\n", stderr);
        return 1;
    }

	char line[1024];
    int res = 0;
    
    while(fgets(line, sizeof(line), f)){
	    int32_t edge = (strlen(line) - 1)/2;
        bool matchNotFound = false;
        //printf("%d\n", edge);
        while(!matchNotFound){
        	for (int32_t i = edge; i <= (int32_t)strlen(line) - 1; ++i){
				for (int32_t j = edge - 1; j >= 0; --j){
					if (line[i] == line[j]){
						if (islower(line[i])){
                            int lprior = line[i] - 'a' + 1;
                            //printf("Lower case: %c\n", line[i]);
							//printf("%d\n", lprior);
                            res += lprior;
                            goto exit;
                        } else if (isupper(line[i])){
                            int uprior = (line[i] - 'A' + 1) + ('z' - 'a' + 1);
                            //printf("Upper case: %c\n", line[i]);
							//printf("%d\n", uprior);
                            res += uprior;
                            goto exit;
                        } else {
							goto exit;	
                        }
                        
                    }
               	    	
            	}
           	}
            exit:
            	matchNotFound = true;
              
        }
    }
    
    return res;
    
}

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i){
	    printf("answer: %d\n", solve_file(argv[i]));
        
        
    }
    return 0;
}
