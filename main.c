#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int same_key(char *a, char *b)
{
    while (*a && (*a == *b))
    {
        a++;
        b++;l
    }
    return *(unsigned char *) a - *(unsigned char *) b;
}

int main(int argc, char *argv[])
{
    printf("Basic Console Language\n");
    char *inputs[12288];
    char *strs[4096];
    char *scts[4096];
    char *ints[4096];
    int *icts[4096];
    char *flts[4096];
    float *fcts[4096];
    char *sin = "sin";
    char *iin = "iin";
    char *fin = "fin";
    char *none = "";
    char *type = "";
    char *line = "";
    /*
    char *mode = "debug";
    char *debug = "debug";
    char *release = "release";
    char *ex0 = "sin a";
    char *ex1 = "sin b";
    char *ex2 = "a Hello";
    char *ex3 = "b World";
    char *ex4 = "sout a";
    char *ex5 = "sout b";
    size_t len = 0;
    ssize_t read;
    if (false)
    {
        FILE *file = fopen(argv[2], "r");
        if (file == NULL)
        {
            printf("Invalid file: %s", argv[2]);
            return 1;
        }
        while ((read = getline(&line, &len, file)) != -1)
        {
            for (int i = 0; i < (12288 + 1); i++)
            {
                inputs[i] = line;
            }
        }
        fclose(file);
        if (line)
        {
            free(line);
        }
    }
    else
    {
        inputs[0] = ex0;
        inputs[1] = ex1;
        inputs[2] = ex2;
        inputs[3] = ex3;
        inputs[4] = ex4;
        inputs[5] = ex5;
    }*/
    for (int i = 0; i < (12288 + 1); i++)
    {
        printf("%s", inputs[i]);
        char *token;
        if (inputs[i] != NULL)
        {
            token = strtok(inputs[i], " ");
        }
        else
        {
            break;
        }
        while (token != NULL)
        {
            if (type == none)
            {
                if (same_key(token, sin) == 0)
                {
                    type = token;
                    token = strtok(NULL, " ");
                }
                else
                {
                    type = token;
                    token = strtok(NULL, " ");
                }
            }
            else
            {
                if (same_key(type, sin) == 0)
                {
                    for (int i = 0; i < (4096 + 1); i++)
                    {
                        if (strs[i] == none)
                        {
                            strs[i] = token;
                        }
                    }
                    printf("Created Variable: %s", token);
                    break;
                }
                else
                {
                    for (int i = 0; i < (4096 + 1); i++)
                    {
                        if (same_key(type, strs[i]) == 0)
                        {
                            scts[i] = token;
                            printf("Set %s's Value to: %s", type, token);
                            break;
                        }
                    }
                }
            }
        }
    }
}