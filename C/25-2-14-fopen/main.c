#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **agrv)
{
    FILE *fp;
    fp = fopen("b.txt", "r");
    if (fp == NULL)
    {
        //printf("Error opening file\n");
        //fprintf(stderr, "error %s\n", strerror(errno));
        //perror("fopen()");
        int errnumber = errno;
        printf("%s\n",strerror(errnumber));
        exit(1);
    }
    else
    {
        printf("File opened successfully\n");
        fclose(fp);
    }
    return 0;
}