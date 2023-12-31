/*
	Double Precision A·X Plus Y
    "A" is a constant.
*/
#include "bits/stdc++.h"
#include "omp.h"
using namespace std;
#define SIZE 65536
#define a 10

void serial(int x[],int y[])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        x[i]=a*x[i]+y[i];
    }
}

void parallel(int x[],int y[],int number_of_threads)
{
    int i;
    omp_set_num_threads(number_of_threads);
    
    #pragma omp parallel for shared(x,y) private(i)
    for(i=0;i<SIZE;i++)
    {
        x[i]=a*x[i]+y[i];
    }   
}

int main()
{
    int x[SIZE],y[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        x[i]=rand()%1000;
    }
    for(i=0;i<SIZE;i++)
    {
        y[i]=rand()%1000;
    }
    
    printf("Threads\tSerial Time\tParallel Time\tSpeedUp\n");

    // Variable Threads
    for(i=2;i<10;i++)
    {
        double serial_start_time, serial_end_time;
        double parallel_start_time, parallel_end_time;
        
        // Serial    
        serial_start_time = omp_get_wtime();
        serial(x,y);
        serial_end_time = omp_get_wtime();

        // Parallel
        parallel_start_time = omp_get_wtime();
        parallel(x,y,i);
        parallel_end_time = omp_get_wtime();

        // Output
        printf("%d\t%lf\t%lf\t%lf\n", i, (serial_end_time - serial_start_time)*1000,(parallel_end_time - parallel_start_time)*1000, (parallel_end_time - parallel_start_time)/(serial_end_time - serial_start_time));
    }
}

//On my current running:
// Threads Serial Time     Parallel Time   SpeedUp
// 2       0.174692        0.213546        1.222414
// 3       0.173314        0.152706        0.881094
// 4       0.176471        0.130117        0.737328
// 5       0.176332        0.109971        0.623659
// 6       0.193116        0.102020        0.528284
// 7       0.187719        0.102129        0.544053
// 8       0.185016        0.087524        0.473062
// 9       0.186792        0.237477        1.271345