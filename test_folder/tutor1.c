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

char **cmd_to_arg(char **cmd)
{

        /* FREE PATH BEFORE END */
        char **path = malloc(sizeof(char *) * 2);
        path[0] = "/bin";
        path[1] = "/usr/bin";
        
        char *slash = "/";
        char **args = NULL, **check = malloc(sizeof(char *) * 2), **cmdStart = cmd;
        check[0] = malloc(strlen(path[0]) + strlen(cmd[0]) + 2);
        check[1] = malloc(strlen(path[1]) + strlen(cmd[0]) + 2);
        int status = -1, i = 0, j = 0;

        while (check[i])
        {
                strcpy(check[i], path[i]);
                strcat(check[i], slash);
                strcat(check[i], cmd[0]);
                status = access(check[i], F_OK | X_OK);
                if (status == 0)
                        break;
                i++;
        }
        args = malloc(sizeof(char *) * 3);
        args[0] = malloc(strlen(check[i]));
        strcpy(args[0], check[i]);
        for (j = 1; j < i && cmd[j] != NULL; j++)
        {
                args[j] = malloc(strlen(cmd[j]) * sizeof(char));
                strcpy(args[j], cmd[j]);
        }
        return (args);
}

int main(int ac, char **av, char **env)
{
        (void)ac, (void)av, (void)env;
        //size_t size = 0;
        char **cmd; //**cmdStart;
        //int i = 0, j = 0;

        cmd = malloc(sizeof(char *) * 2);
	cmd[0] = "ls";
	cmd[1] = "-la";
        cmd = cmd_to_arg(cmd);
        return (0);
}

