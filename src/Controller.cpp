#include "Controller.h"
#include <iostream>

Controller::Controller(const int K_p, const int K_i)
    : _K_p(K_p), _K_i(K_i) {
        std::cout << "Constructing the PID controller with " << _K_p << " and "
        << _K_i << " as P and I parameters\n";
    }

double Controller::compute_input(double error) {
    _error_sum += error;
    return _K_p * error + _K_i * _error_sum;
}