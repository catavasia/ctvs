
//created by Dana

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE* f1 = fopen("data_wrong.txt", "r");
    FILE* f2 = fopen("result2.txt", "w");
    if ( f1 == NULL )
    {
        printf("could not open Data\n");
        break;
    }
    if ( f2 == NULL )
    {
        printf("could not open Result\n");
        break;
    }
    double A1 = 0, A2 = 0, n = 0;
    while(!feof(f1))
        {
            fscanf(f1, "%lf%lf%lf", &A1, &A2, &n);
            if ( A2 == 0 || n == 0)
            {
                printf("Division by zero is impossible");
                break;
            }
             if ( (A1/A2) <= 0 )
             {
                printf("Calculation the log is impossible");
                break;
             }
            double Dekrem = 1/n * log(A1/A2);
            fprintf(f2, "Dekrement = %.2lf\n", Dekrem);
        }
    fclose(f1);
    fclose(f2);
    return 0;
}
