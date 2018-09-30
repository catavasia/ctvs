//created by Dana

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int N = 100;
const double ERROR = 0.2;
int ReadFile();
void PrintDekrem();
//void PrintFile();
double CalculateDekrem();
double Average();
int main()
{
    double n[100] = {}, A1[100] = {}, A2[100] = {}, Dekrem[100] = {};
    int nPoints = ReadFile(n, A1, A2, N);
    *Dekrem = CalculateDekrem(n, A1, A2, nPoints, Dekrem);
    double ave = Average(Dekrem, nPoints);
    //PrintFile( n, A1, A2, nPoints-1);
    printf("%d\n", nPoints);
    printf("%.2lf\n", ave);
    PrintDekrem( Dekrem, nPoints);
    return 0;
}

int ReadFile(double *n, double *A1, double *A2, int num)
{
    int i = 0;
    FILE* f1 = fopen("data.txt", "r");
    if ( f1 == NULL )
    {
        printf("could not open file\n");
    }
    for( i = 0; !feof(f1) ; i++)
    {
            fscanf(f1, "%lf%lf%lf", &A1[i], &A2[i], &n[i]);
    }
    fclose(f1);
    return i-1;
}

void PrintDekrem( double *Dekrem, int num, double ave)
{
    FILE* f2 = fopen("result.txt", "w");
    if ( f2 == NULL)
    {
        printf("could not open file\n");
    }
    for ( int i = 0; i < num; i++)
    {
        if ( (Dekrem[i] <= (ave + ERROR)) && (Dekrem[i] >= (ave - ERROR)))
        {
            fprintf(f2, "Dekrement =  %.2lf \n GOOD\n", Dekrem[i]);
        }
        else
            fprintf(f2, "Dekrement = %.2lf \n BAD\n", Dekrem[i]);
    }
    fclose(f2);
}

/*void PrintFile( double *n, double *A1, double *A2, int num)
{
    FILE* f2 = fopen("result.txt", "w");
    if ( f2 == NULL)
    {
        printf("could not open file\n");
    }
    for ( int i = 0; i < num; i++)
    {
        fprintf(f2, "%.2lf %.2lf %.2lf\n", n[i], A1[i], A2[i]);
    }
    fclose(f2);
}*/

double CalculateDekrem( double *n, double *A1, double *A2, int num, double *Dekrem)
{
    for ( int i = 0; i < num; i++)
    {
        if ( A2[i] == 0.0 || n[i] == 0.0)
            {
                printf("Division by zero in result %lf is impossible", n[i]);
                return 33;
            }
        if ( (A1[i]/A2[i]) <= 0.0 )
            {
                printf("Calculation the log in result %lf is impossible", n[i] );
                return 42;
            }
        Dekrem[i] = 1/n[i] * log(A1[i]/A2[i]);
    }
        return *Dekrem;
}
double Average( double *A, int n)
{
    double Sum = 0;
    for ( int i = 0; i < n; i++ )
    {
      Sum = Sum + A[i];
    }
    double ave = Sum / n;
    return ave;
}
