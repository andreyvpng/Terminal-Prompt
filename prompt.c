#include <stdio.h>      // printf
#include <ctype.h>      // tolower
#include <string.h>     // strcmp
#include <stdlib.h>     // malloc

#define PROMPT_CONFIRM  3 
#define PROMPT_CHOOSE   20
#define PROMPT_REQUEST  512

void prompt_str_to_lower(char str[])
{
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int prompt_check_answer(char str[])
{
    prompt_str_to_lower(str);

    if(strcmp(str, "y") == 0 || strcmp(str, "yes") == 0) {
        return 1;
    } else if(strcmp(str, "n") == 0 || strcmp(str, "no") == 0) {
        return 0;
    } else {
        return -1;
    }
}

char* prompt_getstr(int maxCountOfChar)
{
    char* str = malloc(sizeof(char) * maxCountOfChar);
    int c, countOfChar = 0;

    for(; (c = getchar()) != '\n' && c != EOF && c != ' ' && countOfChar < maxCountOfChar; ++countOfChar) {
        str[countOfChar] = c;
    }
    str[countOfChar] = '\0';

    return str;
}

int prompt_confirn(char message[])
{
    int ans;
    char *str;

    repeat:    
    printf("%s [Y/n] ", message);
    str = prompt_getstr(PROMPT_CONFIRM);
    ans = prompt_check_answer(str);

    if(ans == -1) {
        goto repeat;
    }

    return ans;
}

int prompt_choose(char message[], char* list[], int numOfElem)
{
    printf("%s\n", message);

    for(int i = 0; i < numOfElem; ++i) {
        printf("%d) %s\n", i, list[i]);        
    }

    int answer; 
    char *str;
    printf("Enter index: ");

    repeat:
    str = prompt_getstr(PROMPT_CHOOSE);
    answer = atoi(str);
    
    if(answer < 0 || answer > numOfElem - 1) {
        printf("It's not correct! Enter index: ");
        goto repeat;
    }

    return answer;
}

char* prompt_request(char message[])
{    
    printf("%s: ", message);
    char *answer = prompt_getstr(PROMPT_REQUEST);

    return answer;
}
