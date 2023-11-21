#include <stdio.h>
#include <assert.h>

#define arr_size 3

struct sigrecord{
    int res;
	char oppon[arr_size];
    char me[arr_size];
} sigrec;

int part1(const char* in)
{
	FILE* f;

	int sum = 0;

    f = fopen(in, "r");
    if(f == NULL){
		fputs("Cannot open %s file\n", stderr);
        return 1;
    }

    do{
        int n = fscanf(f, "%c %c%*[\n\r]", sigrec.oppon, sigrec.me);
        if(n == 2){
            switch(*sigrec.me){
                //paper
            case 'Y':{
                if(*sigrec.oppon == 'A'){
                	sum += 2 + 6;
                } else if(*sigrec.oppon == 'B'){
					sum += 2 + 3;
                } else {
					sum += 2 + 0;
                }
                break;
            }
                //rock
			case 'X':{
                if(*sigrec.oppon == 'A'){
                	sum += 1 + 3;
                } else if(*sigrec.oppon == 'B'){
					sum += 1 + 0;
                } else {
					sum += 1 + 6;
                }
                break;
            }
                //scissors
            case 'Z':{
        		if(*sigrec.oppon == 'A'){
                	sum += 3 + 0;
                } else if(*sigrec.oppon == 'B'){
					sum += 3 + 6;
                } else {
					sum += 3 + 3;
                }
                break;
            }
        	}
        }
        else if(n != EOF){
			fputs("Failed to match oppon and me\n", stderr);
            break;
        }
        else{
            printf("all done successfuly\n");
            break;
        }
    } while(1);

	fclose(f);
  	return sum;
}


int part2(const char* in)
{
    FILE* f;

	int sum = 0;

    f = fopen(in, "r");
    if(f == NULL){
		fputs("Cannot open %s file\n", stderr);
        return 1;
    }
	do{
		int n = fscanf(f, "%c %c%*[\n\r]", sigrec.oppon, sigrec.me);
        if(n == 2){
            switch(*sigrec.oppon){
            case 'A':{
                if(*sigrec.me == 'Y'){
 					sum +=  1 + 3;
                } else if(*sigrec.me == 'X'){
					sum += 3 + 0;
                } else {
					sum += 2 + 6;
                }
                break;
            }
            case 'B':{
 				 if(*sigrec.me == 'Y'){
                     sum +=  2 + 3;
                } else if(*sigrec.me == 'X'){
                     sum += 1 + 0;
                } else {
                     sum += 3 + 6;
                }
                break;
            }
            case 'C':{
  			     if(*sigrec.me == 'Y'){
                     sum +=  3 + 3;
                } else if(*sigrec.me == 'X'){
                     sum += 2 + 0 ;
                } else {
					sum += 1 + 6;
                }
                break;
            }
            }
        }
        else if(n != EOF){
			fputs("Failed to match oppon and me\n", stderr);
            break;
        }
        else{
            printf("all done successfuly\n");
            break;
        }
    } while(1);

	fclose(f);

	return sum;
}

int main()
{
    printf("Part1 answer: %d\n", part1("../day2/input.txt"));
    printf("Part2 answer: %d\n", part2("../day2/input.txt"));
    return 0;
}
