#ifndef PROMPT_
#define PROMPT_ 1

void prompt_str_to_lower(char str[]);
int prompt_check_answer(char str[]);
char* prompt_getstr(int maxCountOfChar);
int prompt_confirn(char message[]);
int prompt_choose(char message[], char* list[], int numOfElem);
char* prompt_request(char message[]);

#endif // PROMT_
