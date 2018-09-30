
//created by Dana

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const double ERROR = 0.2;
const double Ex = 0.15;
double CalculateDekrem();
double Average();
double Error();
int main()
{
    FILE* f1 = fopen("data.txt", "r");
    FILE* f2 = fopen("result.txt", "w");
    if ( f1 == NULL || f2 == NULL)
    {
        printf("could not open file\n");
    }
    double A1 = 0, A2 = 0, n = 0, Sum = 0;
    int nPoints = 0;
    while(!feof(f1))
        {
            fscanf(f1, "%lf%lf%lf", &A1, &A2, &n);
            nPoints++;
            double Dekrem = CalculateDekrem( n, A1, A2);
            Sum = Sum + Dekrem;
            fprintf(f2, "Dekrement = %.2lf\n", Dekrem);
            if ( Dekrem < Ex + ERROR && Dekrem > Ex - ERROR )
            {
                fprintf(f2, "OK\n");
            }
            else
                fprintf(f2, "BAD\n");
        }
    //double ave = Average(Sum, nPoints);
//    fprintf(f2, "Average = %.2lf\n", ave);
    fclose(f1);
    fclose(f2);
    return 0;
}
double CalculateDekrem( double n, double A1, double A2)
{
        if ( A2 == 0 || n == 0)
            {
                printf("Division by zero in result %lf is impossible", n);
                return 33;
            }
        if ( (A1/A2) <= 0 )
            {
                printf("Calculation the log in result %lf is impossible", n );
                return 42;
            }
        double Dekrem = 1/n * log(A1/A2);
        return Dekrem;
}
/*double Average( double A, int n)
{
    double ave = A / n;
    return ave;
}
*/

