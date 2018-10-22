//created by Dana
#include <stdio.h>
#include <stdlib.h>
//int ReadFile();

int main()
{
    int size = 0;
    FILE* f = fopen("pop.txt","r");
    if ( f == NULL )
    {
        printf("could not open pop\n");
        return 44;
    }
    fseek(f, 0L, SEEK_END);
    if(fseek(f, 0L, SEEK_END)!= 0)
    {
        printf(" function fseek didn't work ");
    }
    else
        size = ftell(f);
    printf("%d\n", size);
    char *W = (char*) calloc(size+1, sizeof(char));
    if(fread(W, sizeof(char), size, f)!= size)
       {
        if(feof(f))
            printf(" End of file");
        else
            printf("File read error");
       }
    for ( int i = 0; i < size; i++)
    {
        printf("%c\n", W[i]);
    }
    fclose(f);
}

/*int ReadFile()
{
    int size = 0;
    FILE* f = fopen("pop.txt","r");
    if ( f == NULL )
    {
        printf("could not open pop\n");
    }
    fseek(f, 0L, SEEK_END);
    if(fseek(f, 0L, SEEK_END)!= 0)
    {
        printf(" function fseek didn't work ");
    }
    else
        size = ftell(f);
    fclose(f);
    printf("%d", size);
    return size;
}
*/
