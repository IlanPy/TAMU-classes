//lines 5

#include <iostream>

using namespace std;
double pathLength(double** distance, int n, int* path, int m){
    double sum = 0;
    for(int i = 0; i < m-1; i++){
        sum += distance[path[i]][path[i+1]];
    }
    return sum;
}
int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    int m;
    cin >> m;
    double** distance = new double*[n]; //rows

    for (unsigned int i=0; i < n; i++){
        distance[i] = new double[n];  //columns
    }
    int* path = new int[m];
    distance[0][0] = 0.0;
    distance[0][1] = 30.0;
    distance[0][2] = 10.0;
    distance[0][3] = 70.0;
    distance[0][4] = 10.0;
    distance[1][0] = 30.0;
    distance[1][1] = 0.0;
    distance[1][2] = 45.0;
    distance[1][3] = 100.0;
    distance[1][4] = 50.0;
    distance[2][0] = 10.0;
    distance[2][1] = 45.0;
    distance[2][2] = 0.0;
    distance[2][3] = 85.0;
    distance[2][4] = 20.0;
    distance[3][0] = 70.0;
    distance[3][1] = 100.0;
    distance[3][2] = 85.0;
    distance[3][3] = 0.0;
    distance[3][4] = 100.0;
    distance[4][0] = 10.0;
    distance[4][1] = 50.0;
    distance[4][2] = 20.0;
    distance[4][3] = 100.0;
    distance[4][4] = 0.0;
    path[0] = 0;
    path[1] = 1;
    path[2] = 0;
    path[3] = 3;
    path[4] = 2;
    path[5] = 0;
    cout << "Sum: " << pathLength(distance, n, path, m) << endl;
    for(int i = 0; i < n; i++){
        delete[] distance[i];
    } delete[] distance;
    distance = nullptr;
    delete[] path;
    path = nullptr;

    return 0;
}
