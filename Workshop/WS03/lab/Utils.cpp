#include "cstring.h"
namespace seneca {
    void strCpy(char* des, const char* src) {
        int srcLen = 0;
        while (src[srcLen] != '\0') {
            srcLen++;
        }
        for (int i = 0; i <= srcLen; i++) {
            des[i] = src[i];
        }
    }

    void strnCpy(char* des, const char* src, int len) {
        int desLen = 0;
        for (int i = 0; i < len; i++) {
            des[i] = src[i];
        }
        while (des[desLen] != '\0') {
            desLen++;
        }
        if (desLen < len) {
            des[desLen] = '\0';
        }
    }

    int strCmp(const char* s1, const char* s2) {
        int x = 0;
        for (int i = 0; x == 0 && (s1[i] != '\0' || s1[2] != '\0'); i++) {
            if (s1[i] < s2[i]) {
                x = -1;
            }
            else if (s1[i] > s2[i]) {
                x = 1;
            }
        }
        return x;

    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int x = 0;
        for (int i = 0; x == 0 && i < len; i++) {
            if (s1[i] < s2[i]) {
                x = -1;
            }
            else if (s1[i] > s2[i]) {
                x = 1;
            }
        }
        return x;

    }

    int strLen(const char* s) {

        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;

    }

    const char* strStr(const char* str1, const char* str2) {
        const char* x = nullptr;
        for (int i = 0; str1[i] != '\0'; ++i) {
            int j = 0;
            while (str1[i + j] != '\0' && str2[j] != '\0' && str1[i + j] == str2[j]) {
                j++;
            }
            if (str2[j] == '\0') {
                x = &str1[i];
            }
        }
        return x;
    }



    void strCat(char* des, const char* src) {

        int sizeOfDes = strLen(des);
        int sizeOfSrc = strLen(src);

        for (int i = 0; i < sizeOfSrc; i++) {
            des[sizeOfDes + i] = src[i];
        }
        des[sizeOfDes + sizeOfSrc] = '\0';

    }

}