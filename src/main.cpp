#include "Controller.h"
#include "Car.h"
#include <iostream>
#include <vector>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;
    const int m = 1000; // mass [kg]
    const int b = 50; // resistance coefficient [N*sec/m]
    int K_p = 800;
    int K_i = 40; 
    
    // Define simulation time in (s)
    int T = 10; // Suggested Testing Value
    std::cout << "Enter simulation time as an integer (none 0 value)\n";
    std::cin>> T;

    // Define number of steps
    std::cout << "Enter number of steps as an integer (none 0 value):\n";
    int N= 10; //Suggested Testing Value
    std::cin >> N;

    // Define desired velocity
    int velocity = 60; //Suggested Testing Value
    std::cout << "Enter desired velocity (none 0 value)\n";
    std::cin >> velocity;
    std::vector<int> velocity_target(N+1, velocity);

    // Define step size
    double h = T / (N + 1.0);
    
    // Define initial value
    std::vector<double> x0{0.0,0.0}; //Suggested Testing Value
    std::cout << "Enter desired initial position \n";
    std::cin >> x0[0];
    std::cout << "Enter desired initial velocity \n";
    std::cin >> x0[1];

    // Create car
    Car car(m,b,N,x0);

    // Create controller
    Controller pid(K_p, K_i);

    // Create vector of error at every timestep
    std::vector<double> e(N+1,0.0);

    std::vector<double> time_discretized(N+1, 0.0);

    std::vector<double> velo_trajectory(N+1,0.0);

    std::vector<double> input(N+1,0.0);

    for (int i{0}; i<N; ++i) {
        time_discretized[i+1] = time_discretized[i] + h;
        velo_trajectory[i] = car.get_current_velo(i);
        e[i] = velocity - velo_trajectory[i];
        input[i] = pid.compute_input(e[i]);
        car.forward_euler(i, input[i], h);
        if (i == (N-1)) {
            velo_trajectory[i+1] = car.get_current_velo(i+1);
            e[i+1] = velocity - velo_trajectory[i+1];
        }
    }

    // Plot
    figure();
    sgtitle("Cruise Control");

    subplot(3, 1, 0);
    stairs(time_discretized,velo_trajectory,time_discretized,velocity_target);
    title("Velocities and Target Velocities");
    xlabel("time [s]"); 
    ylabel("Velocity [m/s]");
    grid(on);
    auto l = ::matplot::legend({ "car velocity","velocity target"});
    l->location(legend::general_alignment::topright);
    l->num_rows(2);

    subplot(3, 1, 1);
    stairs(time_discretized,e);
    title("Error over time");
    xlabel("time [s]");
    ylabel("Error [m/s]");
    grid(on);
    
    subplot(3, 1, 2);
    stairs(time_discretized,input);
    title("Input over time in N");
    xlabel("time [s]");
    ylabel("Input [N]");
    grid(on);

     // Display the plot
    matplot::show();

    // Wait for user input before closing
    std::cin.get();  // Wait for user input
    
    return 0;
}