#include <iostream>
#include <Eigen/Dense>
#include <stdio.h>

using namespace std;
using namespace Eigen;

#include <random>
#include <math.h>

VectorXd comp_coeff(int n, int m, double* data){
    Eigen::VectorXd y = VectorXd(m);
    Eigen::MatrixXd A = MatrixXd(m, n);
    Eigen::MatrixXd invA = MatrixXd(m, n);

    for(int i=0; i<m; i++){
        y[i] = data[i];
        for(int j=0; j<n; j++){
            A(i, j) = pow(y[i], (double)j);
        }
    }
    cout << "matrix A:\n" << A << endl;
    cout << "vector y:\n" << y << endl;

    Eigen::MatrixXd AA = A.transpose()*A;
    Eigen::MatrixXd Ay = A.transpose()*y;
    Eigen::VectorXd res = AA.inverse()*Ay;
    cout << "coefficients are:\n"
        << res << endl; 
    return res;
}

VectorXd coeff_filter(VectorXd coeff, double* data, int n, int m){
    Eigen::VectorXd smooth_data = VectorXd(m);
    for(int i = 0; i<m; i++){
        double datum = 0;
        for(int j = 0; j<n; j++){
            datum = datum + coeff[j]*pow((double)i, (double)j);
        }
        smooth_data[i] = datum;
    }
    return smooth_data;
}

int main(){
    int n = 2;
    int m = 3;
    double data[] = {0.579013, 0.827452, 0.672594, 0.401896, 0.671935, 0.681033, 0.512197, 1.138130, 0.457066, 0.665372, 0.339450, 0.964903, 0.649879, 0.523977, 0.721257, 0.971281, 0.171379, 0.628887, 0.216538, 0.625860, 0.640069, 1.026172, 0.826194, 0.685418, 0.460384, 1.242944, 0.353122, 0.996656, 0.794824, 0.336445, 0.025732, 0.960995, 0.483259, 0.450150, 0.141149, 0.929024, 0.036805};
    Eigen::VectorXd coeff = comp_coeff(n, m, data);
    Eigen::VectorXd filtered = coeff_filter(coeff, data, n, m);
    cout << "smoothed data is:\n"
        << filtered << endl;
    return 0;
}