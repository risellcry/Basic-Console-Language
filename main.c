#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int same_key(char *a, char *b)
{
    while (*a && (*a == *b))
    {
        a++;
        b++;
    }
    return *(unsigned char *) a - *(unsigned char *) b;
}

size_t tokenize(char *a, char *b, char ***c)
{
    size_t size = 0;
    size_t capacity = 4;
    size_t wordlen;
    char *begin = a;
    char *end;
}

int main(int argc, char *argv[])
{
    printf("Basic Console Language\n");
    char *inputs[2048];
    char *strs[4096];
    char *scts[4096];
    char *ints[4096];
    int *icts[4096];
    char *flts[4096];
    double *fcts[4096];
    char *sin = "sin";
    char *iin = "iin";
    char *none = "";
    char *type = "";
    char *line = "";
    char *mode = "debug";
    char *debug = "debug";
    char *release = "release";
    char *ex0 = "sin a";
    char *ex1 = "sin b";
    char *ex2 = "a Hello";
    char *ex3 = "b World";
    char *ex4 = "sout a";
    char *ex5 = "sout b";
    if (same_key(mode, release))
    {
        FILE *file = fopen(argv[1], "r");
        int data = open(argv[1], O_RDWR);
        if (file == NULL)
        {
            printf("Invalid file: %s", argv[1]);
            return 1;
        }
        char buffer[4096];
        char bytes_read = read(data, buffer, sizeof(buffer));
        line = strtok(buffer, "\n");
        while (line != NULL)
        {
            for (int i = 0; i < (2048 + 1); i++)
            {
                inputs[i] = line;
                printf("%s\n", inputs[i]);
                line = strtok(NULL, "\n");
                break;
            }
        }
        fclose(file);
    }
    else
    {
        inputs[0] = ex0;
        inputs[1] = ex1;
        inputs[2] = ex2;
        inputs[3] = ex3;
        inputs[4] = ex4;
        inputs[5] = ex5;
    }
    for (int i = 0; i < (12288 + 1); i++)
    {
        printf("%s\n", inputs[i]);
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
                if (same_key(token, iin) == 0)
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
                if (same_key(type, iin) == 0)
                {
                    for (int i = 0; i < (4096 + 1); i++)
                    {
                        if (ints[i] == none)
                        {
                            ints[i] = token;
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
                        if (same_key(type, ints[i]) == 0)
                        {
                            icts[i] = (int*) atoi(token);
                            printf("Set %s's Value to: %d", type, token);
                            break;
                        }
                    }
                }
            }
        }
    }
}