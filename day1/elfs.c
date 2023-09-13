#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool line_is_empty(const char *str){
    while(*str){
	if(!isspace((unsigned char) *str)){
	    return false;
	}

	str++;
    }

    return true;
}

void shifting(int arr[], int t, int index){
    int temp;
    if(t > arr[index]){
	for(int j = sizeof(arr) - 2; j >= index; j--){
	    arr[j+1] = arr[j];
	}
        arr[index] = t;
    }
    
}

void part1(){
    FILE *in;
    
    in = fopen("input.txt", "r");
    if(in == NULL){
        fputs("Cannot open calories.txt file\n", stderr);
    }

    char line[1024];
    int total = 0;
    int answ = 0;
    int line_number = 0;
    while(fgets(line, sizeof(line), in)){
	line_number++;
	int temp = atoi(line);
	total += temp;
	if(line_is_empty(line)){
	    if(total > answ){
		answ = total;
	    }
	    total = 0;
	}
    }

    printf("answer: %d\n", answ);
    fclose(in);
}

void part2(){
    FILE *in;
    
    in = fopen("input.txt", "r");
    if(in == NULL){
        fputs("Cannot open calories.txt file\n", stderr);
    }

    char line[1024];
    int tops_arr[4] = {0};
    int total = 0;
    int answ = 0;
    int line_number = 0;
    
    while(fgets(line, sizeof(line), in)){
	line_number++;
	int temp = atoi(line);
	total += temp;
	if(line_is_empty(line)){
	    if(total >tops_arr[0]){
	        shifting(tops_arr, total, 0);
	    } else if (total > tops_arr[1]){
	        shifting(tops_arr, total, 1);
	    } else if (total > tops_arr[2]){
	        shifting(tops_arr, total, 2);
	    }
	    total = 0;
	}
    }
    
    answ = tops_arr[0] + tops_arr[1]+tops_arr[2];
    printf("answer: %d\n", answ);
    fclose(in);
}


int main(void){
    part1();
    part2();
    return 0;
}
