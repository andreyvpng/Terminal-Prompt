#include <stdio.h>
#include "prompt.h"

int main(void)
{

    char* list[] = { "c", "b", "c++", "lua", "go", "js", "ruby", "python" };

    int ans = prompt_choose("What's your favorite language?", list, 7);
    printf("%d", ans);
    
    return 0;
}
