/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file main.cpp
 * @author nifeng01(com@baidu.com)
 * @date 2015/01/08 12:33:57
 * @brief 
 *  
 **/

#include <cstdio>
#include <cstring>

//delete the char  "b" in str
void del_one_char(char* str) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'b') {
            continue;
        }
        str[j++] = str[i];
    } 
    str[j] = '\0';
}

//delete two char "b" and "ac" in str
void del_two_char(char* str) {
    int j = 0;

    for (int i =0; str[i] != '\0'; i++) {
        if (str[i] == 'a' && str[i+1] == 'c') {
            i++;
            continue;
        }
        if (str[i] == 'b') {
            continue;
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}

//delete two char "b" and "ac" in str recursively
/**
 *  'b'
 *
 *  'a'
 *      'a' aacc
 *      'b' abbbbc
 *      'c' ac
 *
 */
void del_two_char_rec(char* str) {
    int j = 0;

    for (int i =0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            char next = str[i + 1];
            if (next == 'c') {
                i++;
                continue;
            } else if (next == 'b') {
                int k = i + 1;
                while (str[++k] == 'b');
                if (str[k] == 'c') {
                    i = k + 1;
                    continue;
                }
            } else if (next == 'a') {
                int k = i + 1;
                while (str[++k] == 'a');
                int cnt = k - i;
                int c_first = k;
                while (str[++k] == 'c');
                if (cnt == k - c_first) {
                    i = k;
                    continue;
                }
            } else {
                ;
            }
        } else if (str[i] == 'b') {
            continue;
        } else {
            ;
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return -1;
    }
    char* str = argv[1];
    char copy[128];
    strncpy(copy, str, 128);
    printf("%s\n", argv[0]);
    printf("%s\n", str);
    printf("%s\n", copy);

    printf("before : %s\n", str);
    //del_one_char(str);
    del_two_char(str);
    printf("situation 1 after : %s\n", str);
    del_two_char_rec(copy);
    printf("situation 2 after : %s\n", copy);
    return 0;
}
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
