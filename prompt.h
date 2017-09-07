/*
    Copyright (c) <2017> <Andrey Varfolomeev>

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgement in the product documentation would be
    appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#ifndef PROMPT_
#define PROMPT_ 1
#include <stdio.h>      // printf
#include <ctype.h>      // tolower
#include <string.h>     // strcmp
#include <stdlib.h>     // malloc

#define PROMPT_CONFIRM  3 
#define PROMPT_CHOOSE   20
#define PROMPT_REQUEST  512

/*
 *  Переводит все символы строки к нижниму регистру
 */
void prompt_str_to_lower(char str[])
{
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/*
 *  Проверяет введённые пользователем данные
 */
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

/*
 *  
 */
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


/*
 *  Принимает:
 *      Строку для вывода сообщение на экран.
 *
 *  Описание:
 *      Считывает символы с клавиатуры до тех пор, пока 
 *      пользователь не введет хоть одну из нужных строк.
 *      ("yes", "y", "no", "n")
 *
 *  Возвращает:
 *      Пользователь ввёл "yes" или "y" - возвращает 1
 *      Пользователь ввёл "no" или "n"  - возвращает 0
 */
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

/*
 *  Принимает:
 *      Строку для вывода сообщение на экран.
 *      Массив строк для вывода на экран
 *      Колличество элементов в массиве
 *
 *  Описание:
 *      Считывает число с клавиатуры, пока введенное
 *      число не будет находится в промежутке [0, numOfElem)
 *
 *  Возвращает:
 *      Индекс выбранного элемента
 */
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
    
    // Если число не находится в промежутке [0, numOfElem), 
    // то возвращаемся к метке repeat
    if(answer < 0 || answer > numOfElem - 1) {
        printf("It's not correct! Enter index: ");
        goto repeat;
    }

    return answer;
}

/*
 *  Принимает:
 *      Строку для вывода сообщение на экран.
 *
 *  Возвращает:
 *      Данные введенные пользователем   
 */
char* prompt_request(char message[])
{    
    printf("%s: ", message);
    char *answer = prompt_getstr(PROMPT_REQUEST);

    return answer;
}

#endif // PROMT_