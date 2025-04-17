#include "Car.h"

#include <iostream>
#include <vector>

Car::Car(const int& m, const int& b, const int& N, const std::vector<double>& x0)
    : _m(m), _b(b), _N(N), _x_traj(N+1, std::vector<double>(2,0.0)) {
        _x_traj[0][0] = x0[0];
        _x_traj[0][1] = x0[1];
    std::cout << "Constructing the) simplified car model with " << m << "kg, "
        << b << "Nsec/m as car properties and " << _x_traj[0][0] << "," << _x_traj[0][1] << " as initial position and velocity\n";
}

void Car::forward_euler(const int& i, double& controller_input, double& h) {
    _x_traj[i+1][0] = _x_traj[i][0] + _x_traj[i][1] * h;
    _x_traj[i+1][1] = _x_traj[i][1] + (-_b * _x_traj[i][1] + controller_input) / _m * h;
}

const double Car::get_current_velo(const int& k) {
    return _x_traj[k][1];
}

void Car::print_vector(const std::vector<double>& vec){
    std::cout << "[ ";
    for (const auto& elem : vec){
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

void Car::print_matrix() {
    std::cout << "[ \n";
    for(const auto & row : Car::_x_traj) {
        std::cout << " ";
        print_vector(row);
    }
    std::cout << "]\n";
}
