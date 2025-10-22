#include <cstring>
#include <iostream>

#include "BaseEquation.hpp"
#include "RKSolver.hpp"
// #include "equations_test.hpp"


void run_test(char const * method_name, char const * test_number)
{
    // =========================================================================
    // INITIALIZATION OF TEST DEPENDENT DATA
    // =========================================================================

    EquationFunction* fun_ptr = nullptr;
    double initial_time;
    double final_time;
    Rnvector initial_condition;

    // Test 1
    if ( strcmp(test_number, "1") == 0 )
    {
        std::cout << std::endl << "Running Test 1" << std::endl << std::endl;
        fun_ptr = new EquationFunction;
        initial_time = 0;
        final_time = 1;
        initial_condition.push_back( 0 );
    }

    // Test 2
    else if ( strcmp(test_number, "2") == 0  )
    {
        std::cout << std::endl << "Running Test 2" << std::endl << std::endl;
        fun_ptr = new EquationFunction;
        initial_time = 0;
        final_time = 1;
        initial_condition.push_back( 0 );
        initial_condition.push_back( 0 );
    }

    else
    {
        std::cerr << "Unknown test function. Aborting..." << std::endl;
        exit(1);
    }


    // Equation initialization using test dependent data
    BaseEquation equation( initial_time, final_time, *fun_ptr,
        initial_condition );


    // =========================================================================
    // INITIALIZATION OF THE SOLVER
    // =========================================================================

    double initial_step = 0.1; // Changes mid-solving only in adaptive methods
    double tolerance = 0.01; // Used only in adaptive methods
    double min_step = 0.005; // Used only in adaptive methods
    std::vector<std::vector<double>> a;
    std::vector<double> b, c;

    if ( strcmp(method_name, "Heun") == 0 )
    {
        // Heun method (Runge-Kutta with 2 stages)
        std::vector<double> a1{ 0,  0 };
        std::vector<double> a2{ 1,  0 };
        a.push_back( a1 );
        a.push_back( a2 );
        b = { 0.5, 0.5 };
        c = {   0,  1  };
    }

    else if ( strcmp(method_name, "RK4") == 0 )
    {
        // Adaptive Runge-Kutta method with 4 stages
        a = {
            {0, 0, 0, 0},
            {0.5, 0, 0, 0},
            {0, 0.5, 0, 0},
            {0, 0, 1, 0}
        };
        b = {1 / 6., 1 / 3., 1 / 3., 1 / 6.};
        c = {0, 0.5, 0.5, 1};
    }

    else
    {
        std::cerr << "Unknown RK method. Aborting..." << std::endl;
        exit(1);
    }

    RKSolver problem = RKSolver( initial_step, equation, a, b, c,
        tolerance, min_step );

    // =========================================================================
    // SOLUTION
    // =========================================================================

    // Chrono starts
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // Solution
    problem.solve();

    // Chrono ends

    high_resolution_clock::time_point t2 = high_resolution_clock::now();


    // =========================================================================s
    // POSTPROCESSING
    // =========================================================================

    // Compute duration of the solution process
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    // Prints problem characteristics on screen
    problem.print();

    // Prints duration of the solution process
    std::cout << "Solution time: " << duration << " μs" << std::endl;

    // Saves solution to file_name
    std::string file_name = "solution_" + std::string(test_number) + "_"
                                        + std::string(method_name) + ".txt";
    problem.save_sol_to_file( file_name );
    std::cout << "Saved solution to file " << file_name << std::endl
        << std::endl << std::endl;

    // Releases dynamically allocated resources
    delete fun_ptr;
}


int main()
{
    run_test("Heun", "2");  // "2"
    run_test("RK4", "2");  // "2"
    return 0;
}
