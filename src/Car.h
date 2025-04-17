#ifndef CAR_H
#define CAR_H
#include <vector>
#include <iostream>

class Car {
    private:
        int _m; // mass of the car
        int _b; // simplified driving resistances such as rolling resistance and aerodynamic drag
        int _N; // number of time steps
        std::vector<std::vector<double>> _x_traj;

    public:
        Car(const int& m, const int& b, const int& N, const std::vector<double>& x0);

        void forward_euler(const int& i, double& controller, double& h);

        const double get_current_velo(const int& k); 

        std::vector<std::vector<double>> get_velo_trajectory();

        void print_vector(const std::vector<double>& vec);

        void print_matrix();
};

#endif