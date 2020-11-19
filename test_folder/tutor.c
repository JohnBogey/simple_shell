#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
char **_strtok(char *str, char *delim)
{
        char **doubl;
        char *s = str;
        char *string;
        int i = 0;

        while (*s)
        {
                if (*s == *delim)
                        i++;
                s++;
        }
        doubl = malloc(sizeof(char *) * (i + 1));
        i = 0;
        string = strtok(str, delim);
        while (1)
        {
                if (string == NULL)
                  break;
                doubl[i] = malloc(sizeof(char) * strlen(string) + 1);
                strcpy(doubl[i], string);
                i++;
                string = strtok(NULL, delim);
        }
        return (doubl);
}

char **cmd_to_arg(char **cmd, char **env)
{

        /* FREE PATH BEFORE END */
        char *path = get_path(env);
        char *slash = "/";
        char **args = NULL, **check = _strtok(path, ":"), **checkStart = check, **cmdStart = cmd;
        int status = -1, i = 0, j;

        while (*checkStart)
        {
                strcat(*checkStart, slash);
                strcat(*checkStart, cmd[0]);
                status = access(*checkStart, F_OK | X_OK);
                printf("%s\n", *checkStart);
                if (status == 0)
                        break;
                checkStart++;
        }
        for(;*cmdStart; i++, cmdStart++)
                printf("%d\n", i);
        args = malloc(sizeof(char *) * i);
        args[0] = malloc(strlen(*checkStart));
        strcpy(args[0], *checkStart);
        puts(args[0]);
        for (j = 1; j < i && cmd[j] != NULL; j++)
        {
                //printf("%d\n", j);
                args[j] = malloc(strlen(cmd[j]) * sizeof(char));
                strcpy(args[j], cmd[j]);
                puts(args[j]);
        }
        return (args);
}

int main(int ac, char **av, char **env)
{
        (void)ac, (void)av, (void)env;
        char line[] = "ls -la -R";
        //size_t size = 0;
        char **cmd; //**cmdStart;
        //int i = 0, j = 0;

        cmd = _strtok(line, " ");
        cmd = cmd_to_arg(cmd, env);
        return (0);
}
