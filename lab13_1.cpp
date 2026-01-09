#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]) {
    double sum = 0;
    double sumSq = 0;
    double sumLog = 0;
    double sumInv = 0;
    double maxVal = A[0];
    double minVal = A[0];

    for (int i = 0; i < N; i++) {
        sum += A[i];
        sumSq += pow(A[i], 2);
        sumLog += log(A[i]);
        sumInv += 1.0 / A[i];
        
        if (A[i] > maxVal) maxVal = A[i];
        if (A[i] < minVal) minVal = A[i];
    }

    B[0] = sum / N;
    B[1] = sqrt((sumSq / N) - pow(B[0], 2));
    B[2] = exp(sumLog / N);
    B[3] = N / sumInv;
    B[4] = maxVal;
    B[5] = minVal;
}