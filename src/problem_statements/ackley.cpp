#include "../../include/problem_statements/ackley.hpp"

// Integer to assign unique IDs to solutions
int Solution::solution_counter;

Solution::Solution(void) {
    // Give the solution a unique ID and increment the counter
    solution_id = solution_counter;
    solution_counter++;

    // Create the x vector based on upper and lower bounds from problem statement
    x = random_vector(static_cast <unsigned long> (number_of_move_ops/2), upper_bound, lower_bound);

    // Compute the quality.
    compute_quality();
}

void Solution::compute_quality(void) {
    // Initialize a couple variable for sums
    long double fx1 = 0;
    long double fx2 = 0;
    int D = static_cast <int> (x.size());

    // Step through every dimensions and do a thing
    for(int i=0; i < D; i++){
        fx1 += x[i]*x[i];
        fx2 += cos(2.0*M_PI*x[i]);
    }

    // Return a sum of sums
    quality = abs(-20.0*exp(-0.2*sqrt(fx1/D)) - exp(fx2/D) + 20.0 + exp(1.0));
}

void Solution::apply_move_operator(int n, long double size) {
    size *= tan(uniform(M_PI/2, 0.0));
    int plus_or_minus = 2*(n % 2) - 1;
    int dimension = n/2;
    x[dimension] += static_cast<long double>(plus_or_minus)*size;

    compute_quality();
}