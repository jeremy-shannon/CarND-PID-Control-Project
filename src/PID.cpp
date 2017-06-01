#include "PID.h"
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = d_error = i_error = total_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = p_error - cte;
    p_error = cte;
    i_error += cte;
    total_error += pow(cte,2);
}

double PID::TotalError() {
    return total_error;
}

