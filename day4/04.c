#include <stdio.h>


struct {
    int start;
    int end;
} ElfOne;

struct {
    int start;
    int end;
} ElfTwo;



int part1(const char* file_path){
    printf("Input file: %s\n", file_path);
    FILE* f;

    f = fopen(file_path, "r");
    if(f == NULL){
        fputs("Cannot open %s file\n", stderr);
        return 1;
    }


    int res = 0;

    do {
        int n = fscanf(f, "%d-%d,%d-%d%*[\n\r]", &ElfOne.start, &ElfOne.end, &ElfTwo.start, &ElfTwo.end);
        if (n == 4){
            if (ElfOne.start <= ElfTwo.start && ElfOne.end >= ElfTwo.end){
                res++;
            } else if (ElfTwo.start <= ElfOne.start && ElfTwo.end >= ElfOne.end){
                res++;
            }
        } else if(n != EOF){
            fputs("Couldnt read properly numbers\n", stderr);
            break;
        }
        else{
            printf("all done successfuly\n");
            break;
        }
    } while(1);

    return res;
}


int part2(const char* file_path){
    printf("Input file: %s\n", file_path);
    FILE* f;

    f = fopen(file_path, "r");
    if(f == NULL){
        fputs("Cannot open %s file\n", stderr);
        return 1;
    }


    int res = 0;

    do {
        int n = fscanf(f, "%d-%d,%d-%d%*[\n\r]", &ElfOne.start, &ElfOne.end, &ElfTwo.start, &ElfTwo.end);
        if (n == 4){
            if (ElfTwo.start <= ElfOne.end && ElfTwo.end >= ElfOne.start) {
                res++;
            } else if (ElfOne.start <= ElfTwo.end && ElfOne.end >= ElfTwo.start) {
                res++;
            }
        } else if(n != EOF){
            fputs("Couldnt read properly numbers\n", stderr);
            break;
        }
        else{
            printf("all done successfuly\n");
            break;
        }
    } while(1);

    return res;
}



int main(int argc, char *argv[]){
    for (int i = 1; i < argc; ++i){
        printf("answer: %d\n", part2(argv[i]));
    }
    return 0;
}
