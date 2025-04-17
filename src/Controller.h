#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
    protected:
        double _input;
        double _error_sum{0};
        const int _K_p; // Parameter for P-controller
        const int _K_i; // Parameter for I-controller
    
    public:
        Controller(const int K_p, const int K_i);

        double compute_input(double error);
         
};

#endif