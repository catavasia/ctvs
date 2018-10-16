//created by Dana

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double tol = 1e-3;
int ReadFile();
int Num_of_str();
void PrintDekrem();
void PrintFile();
int CalculateDekrem();
double Average();
double Deviation();
int main()
{
    int NPoints = Num_of_str();
    //printf("%d\n", NPoints);
    double *A1 = (double *) calloc(NPoints, sizeof(double));
    double *A2 = (double *) calloc(NPoints, sizeof(double));
    double *Dekrem = (double *) calloc(NPoints, sizeof(double));
    double *n = (double *) calloc(NPoints, sizeof(double));
    int a = ReadFile(n, A1, A2, NPoints);
     //printf("%d\n", a);
    int d = CalculateDekrem(n, A1, A2, NPoints, Dekrem);
    //printf("%d", d);
    double ave = Average(Dekrem, NPoints);
    //printf("%lf\n", ave);
    double error = Deviation(Dekrem, ave, NPoints);
    //printf("%lf\n", error);
    //PrintFile( n, A1, A2, NPoints);
   // printf("%.2lf\n", ave);
    PrintDekrem(Dekrem, NPoints, ave, error);
    free(A1);
    free(A2);
    free(n);
    free(Dekrem);
    return 0;
}

int Num_of_str()
{
    int NStr = 1;
    char s = 0;
    FILE* f1 = fopen("data.txt", "r");
    if ( f1 == NULL )
    {
        printf("could not open data\n");
    }
    while( fscanf(f1,"%c", &s) != EOF )
    {
        if ( s == '\n')
        NStr++;
    }
    fclose(f1);
    return NStr;
}

int ReadFile(double *n, double *A1, double *A2, int num)
{
    int i = 0;
    FILE* f1 = fopen("data.txt", "r");
    if ( f1 == NULL )
    {
        printf("could not open data\n");
    }
    for( i = 0; !feof(f1) ; i++)
    {
            fscanf(f1, "%lf%lf%lf", &A1[i], &A2[i], &n[i]);
    }
    fclose(f1);
    return 6;
}

void PrintDekrem( double *Dekrem, int num, double ave, double error)
{
    FILE* f2 = fopen("result.txt", "w");
    if ( f2 == NULL)
    {
        printf("could not open result\n");
    }
    for ( int i = 0; i < num; i++)
    {
        if ( fabs(Dekrem[i] - ave) <= error )
            fprintf(f2, "Dekrement =  %.2lf +- (%.2lf) \n GOOD\n ", Dekrem[i], error);
        else
            fprintf(f2, "Dekrement =  %.2lf +- (%.2lf) \n BAD\n ", Dekrem[i], error);
    }
    fclose(f2);
}

/*void PrintFile( double *n, double *A1, double *A2, int num)
{
    FILE* f2 = fopen("data_2.txt", "w");
    if ( f2 == NULL)
    {
        printf("could not open data_2\n");
    }
    for ( int i = 0; i < num; i++)
    {
        fprintf(f2, "%.2lf %.2lf %.2lf\n", n[i], A1[i], A2[i]);
    }
    fclose(f2);
}
*/
int CalculateDekrem( double *n, double *A1, double *A2, int num, double *Dekrem)
{
    for ( int i = 0; i < num; i++)
    {
        if ( A2[i] < tol)
        {
            printf("Value %.2lf is out of range", A2[i]);
            return 33;
        }
        if ( (A1[i]/A2[i]) <= 0.0 )
        {
            printf("Calculation the log is impossible");
            return 42;
        }
        if ( n[i] < tol )
        {
            printf("Something wrong with %.2lf", n[i] );
        }
        Dekrem[i] = 1/n[i] * log(A1[i]/A2[i]);
        printf("%lf\n", Dekrem[i]);
    }
    return 3;
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

double Deviation( double *D, double ave, int num)
{
    double res = 0;
    for ( int i = 0; i < num; i++)
     {
         res = res + (D[i]- ave) * (D[i]- ave);
     }
    double fres = sqrt(res / num );
    return fres;
}


