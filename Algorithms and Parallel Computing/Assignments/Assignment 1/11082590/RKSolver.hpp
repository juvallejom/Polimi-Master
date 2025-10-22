#ifndef RKSOLVER_HPP
#define RKSOLVER_HPP

#include <algorithm>
#include <cassert>
#include <fstream>

#include "BaseEquation.hpp"


class RKSolver
{
    private:
        //! Integration step (starting value in adaptive methods)
        double h;

        //! Equation to be solved
        BaseEquation equation;

        //! {u_n}_n -- solution (to be filled by solve())
        SolutionType solution;

        //! {t_n}_n -- time instants (to be filled by solve())
        std::vector<double> times;

        // Butcher tableau
        // (the vectors are of size s, the first element of c is zero;
        // the matrix is s-by-s)
        //! a coefficients of the Butcher tableau
        std::vector<std::vector<double>> a;
        //! b coefficients of the Butcher tableau
        std::vector<double> b;
        //! c coefficients of the Butcher tableau
        std::vector<double> c;

        //! Number of stages
        unsigned n_stages;

        //! Name of the RK method
        std::string method_name;

        //! Tolerance for fixed point iterations (in case of implicit method)
        double fixed_point_tol = 0.001;

        //! epsilon -- error tolerance to select the step size (adaptive)
        double tol = 0.0;

        //! Minimum step size (adaptive)
        double hmin = 0.0;

        //! One step of time integration, called by solve()
        Rnvector single_step(const double tn, const Rnvector &un,
                             const double h) const;

        //! Computes the K-th coefficient for an implicit method
        Rnvector fixed_point(const EquationFunction &f, const double tn,
                             const Rnvector &un, const double h,
                             const Rnvector &sum_aij_Kj,
                             const size_t i) const;

        //! Computes the error at a set iteration of the fixed point algorithm
        double compute_error(const Rnvector &K0, const Rnvector &K1) const;

        //! Checks if the K-th coefficient computation is implicit looking at A
        bool is_implicit(const size_t K_index) const;

    public:
        // Constructors
        RKSolver(double step, const BaseEquation &eq,
                 const std::vector<std::vector<double>> &a_,
                 const std::vector<double> &b_,
                 const std::vector<double> &c_,
                 double tolerance = 0.0, double min_step = 0.0);

        RKSolver(double step, const BaseEquation &eq,
                 const std::string name,
                 double tolerance = 0.0, double min_step = 0.0);

        //! Main solver based on Runge-Kutta methods
        void solve();

        // Getters
        double get_h() const { return h; };
        BaseEquation get_equation() const { return equation; };
        SolutionType get_solution() const { return solution; };

        //! Prints the equation and calls print_solver_spec()
        void print() const;

        //! Saves solution and time instants in a .txt file
        void save_sol_to_file( const std::string &file_name ) const;

        //! Prints the characteristics of the Runge-Kutta solver
        void print_solver_spec() const;
};

#endif // RKSOLVER_HPP
