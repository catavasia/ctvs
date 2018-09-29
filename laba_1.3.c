//created by Dana

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int N = 100;
int ReadData();
void CalculateDekrem();
double Average();
void Error();

int main()
{
    double A1[N] = {0}, A2[N] = {0}, n[N] = {0}, Dekrem[N] = {0}, Tol[N] = {0};
    int line = ReadData(n, A1, A2);
    CalculateDekrem(n, A1, A2, line);
    double Ave = Average(Dekrem, line);
    double Tolerance = Ave * 0.1;
    void Error( Dekrem, Ave, Tolerance, line );
    FILE* f2 = fopen("values.txt", "w");
    if ( f2 == NULL )
    {
        printf("could not open Results\n");
        return 0;
    }
    for( int m = 0; m < line; m++)
    {
       fprintf(f2, "Dekrement = %.2lf\n", Dekrem[m]);
       if (Tol[m])
            fprintf ( f2, " Ok ");
        else
            fprintf ( f2, " Bad ");
    }
    fclose(f2);
    return 0;
}
int ReadData( double n, double A1, double A2 )
{
    int line  = 0;
    FILE* f1 = fopen("data.txt", "r");
    if ( f1 == NULL )
    {
        printf("could not open Data\n");
        break;
    }
    while(!feof(f1))
    {
        fscanf(f1, "%lf%lf%lf", &n[line], &A1[line], &A2[line]);
        line++;
    }
    fclose(f1);
    return line;
}
void CalculateDekrem( double  n, double A1, double A2, int line )
{
    int i = 0;
    while(i < line)
    {
        if ( A2[i] == 0 || n[i] == 0)
            {
                printf("Division by zero in result %lf is impossible", n[i]);
                i++;
            }
        if ( (A1/A2) <= 0 )
            {
                printf("Calculation the log in result %lf is impossible", n[i]);
                i++
            }
        Dekrem[i] = 1/n[i] * log(A1[i]/A2[i]);
    }
}
double Average( double Dekrem[], int line )
{
    double Average = 0, Summ = 0;
    int k = 0;
    while( k != line)
    {
        Summ = Summ + Dekrem[k];
        k++;
    }
    Average = Summ / k;
    return Average;
}
void Error( double Dekrem[], double Ave, double Tolerance, int line )
{
    int k = 0;
    while( k != line)
    {
        if ( Ave - Tolerance < Dekrem[k] < Ave + Tolerance )
            Tol[k] = 1; // входит в пределы погрещности
        else
            Tol[k] = 2; // выходит за пределы погрещности
        k++;
    }
}
