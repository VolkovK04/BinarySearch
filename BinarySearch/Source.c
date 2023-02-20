#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int search(int* nums, int numsSize, int target) {
    int a = 0;
    int b = numsSize - 1;
    while (a != b) {
        int c = (a + b) / 2;
        if (target > nums[c])
            a = c + 1;
        else
            b = c;
    }
    if (nums[a] == target)
        return a;
    return -1;
}

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

void fileCheck(FILE* file) {
    if (file == NULL) {
        printf("Can not open the file");
        exit(0);
    }
}

int readInt(FILE* file) {
    char str[64] = "";
    char c = 0;
    while (1) {
        c = fgetc(file);
        if (c == '\n' || c == EOF)
            break;
        strncat(str, &c, 1);
    }
    return atoi(str);
}

int main() {
    //new commit
    //test
    int flag = 1;
    for (int k = 1; k <= 2; k++) {
        char nameIn[64];
        sprintf(nameIn, "tests/input%d", k);
        FILE* input = fopen(nameIn, "r");
        fileCheck(input);
        int numsSize = readInt(input);
        int* nums = (int*)malloc(numsSize * sizeof(int));
        nullCheck(nums);
        for (int i = 0; i < numsSize; i++)
            nums[i] = readInt(input);
        int target = readInt(input);
        fclose(input);
        int result = search(nums, numsSize, target);
        free(nums);
        ERRORERRORERRORERRORERRORERRORERRORERRORERROR
        char nameOut[64];
        sprintf(nameOut, "tests/output%d", k);
        FILE* output = fopen(nameOut, "r");
        fileCheck(output);
        int expected = readInt(output);
        if (result != expected)
            flag == 0;          
    }
    if (flag)
        printf("Tests passed");
    else
        printf("Tests failed");
    return 0;
}