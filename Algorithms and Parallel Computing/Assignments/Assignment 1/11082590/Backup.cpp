#include <cmath>
#include <iostream>

#include "RKSolver.hpp"


RKSolver::RKSolver(double step, const BaseEquation &eq,
                   const std::vector<std::vector<double>> &a_,
                   const std::vector<double> &b_,
                   const std::vector<double> &c_,
                   double tolerance, double min_step)
    : h(step), equation(eq), a(a_), b(b_), c(c_), tol(tolerance), hmin(min_step)
{
    assert(b.size() == c.size() && a.size() == a[0].size() && b.size() == a.size());
    n_stages = b.size();
    method_name = "User defined";
    // The solution at t=0 coincides with the initial condition
    solution.push_back( equation.get_x0() );
    times.push_back( equation.get_tin() );
}

Rnvector RKSolver::fixed_point(const EquationFunction &f, const double tn,
                               const Rnvector &un, const double h_local,
                               const Rnvector &sum_aij_Kj, const size_t i) const
{
    unsigned n_iter = 0;
    unsigned Max_iter = 10000;

    Rnvector K0 = un;
    Rnvector K1 = f.eval(tn + c[i] * h_local,
                    un + h_local * sum_aij_Kj + h_local * a[i][i] * K0);
    double error = compute_error(K0, K1);
    K0 = K1;

    while (error > fixed_point_tol && n_iter < Max_iter)
    {
        K1 = f.eval(tn + c[i] * h_local,
               un + h_local * sum_aij_Kj + h_local * a[i][i] * K0);
        error = compute_error(K0, K1);
        K0 = K1;
        n_iter++;
    }

    if (n_iter == Max_iter)
    {
        std::cerr << "Fixed point algorithm cannot converge. Try with a smaller step size."
                  << std::endl;
        exit(1);
    }

    return K0;
}

double RKSolver::compute_error(const Rnvector &K0, const Rnvector &K1) const
{
    double error = 0;
    for (size_t k = 0; k < K0.size(); k++)
        error += std::abs(K0[k] - K1[k]);
    return error;
}

bool RKSolver::is_implicit(const size_t K_index) const
{
    return (a[K_index][K_index] != 0);
}

void RKSolver::print() const
{
    // Print the equation
    std::cout << "Equation:" << std::endl;
    std::cout << equation.get_f().f_string << "\t in [" <<
    equation.get_tin() << "," << equation.get_tfin() << "]" << std::endl;
    std::cout << "y(" << equation.get_tin() << ") = ";
    for( auto i : equation.get_x0() )
        std::cout << i << " ";
    std::cout << std::endl << std::endl;
    //Print the solver specifications
    print_solver_spec();
}

void RKSolver::save_sol_to_file( const std::string &file_name ) const
{
    std::ofstream output_stream{ file_name };
    if( !output_stream )
    {
        std::cerr << "Cannot open input file: \"" << file_name << "\"" <<
            std::endl;
        return;
    }

    // Save the computed solution
    output_stream << "Solution:" << std::endl;
    for( auto un : solution )
    {
        for( auto val : un )
            output_stream << val << " ";
        output_stream << std::endl;
    }

    // Save time instants
    output_stream << "Time instants:" << std::endl;
    for( auto tn : times )
        output_stream << tn << " ";
    output_stream << std::endl;
}

void RKSolver::print_solver_spec() const
{
    std::cout << "Solved using: Adaptive Runge-Kutta (" << method_name << ")" << std::endl;
    std::cout << "Starting h = " << h << std::endl;
    std::cout << "Minimum h  = " << hmin << std::endl;
    std::cout << "Tolerance  = " << tol << std::endl;
    std::cout << std::endl;
}

Rnvector RKSolver::single_step(const double tn, const Rnvector &un,
    const double hn) const
{   
    // =========================================================================
    // MY CODE
    // =========================================================================

    std::vector<std::vector<double>> k;      // Matrix k that stores each stage vector ki
    std::vector<double> kn;                  // stage vector kn for stage i
    std::vector<double> un1;                 // un+1
    std::vector<double> sum(un.size(),0.0);  // Sum(bi*ki)
    EquationFunction &f = equation.get_f();  // ODE
    for (size_t i=0;i<n_stages;++i){
        std::cout<<"Iteration "<<i<<" - tn: "<<tn<<"- hn :"<<hn<<std::endl;
        size_t j=0;
        std::vector<double> s(un.size(),0.0); // si - Sum of aij*ki
        while(j<i){
            std::cout<<j<<"--"<<i<<std::endl;
            std::vector<double> k_col;
            for(size_t m=0;m<k.size();m++){
                k_col.push_back(k[m][j]);
            }
            std::cout << "s " << s.size() << ", kcol: " << k_col.size() << std::endl;
            std::cout << k_col[0] << std::endl;
            s=s+a[i][j]*k[j];
            j++;
        }
        if(a[i][i]!=0){
            std::cout<<"0"<<std::endl;
        }
        else{
            std::cout << "un : " << un.size()<< "[";
                for (size_t p = 0; p < un.size(); ++p) {
                    std::cout << un[p];
                    if (p != un.size() - 1) std::cout << ", ";
                }
                std::cout << "]" ", si(size): " << s.size() << std::endl;
            std::cout<<un[0]<<" - "<<hn<<" - "<<s[0]<<" - "<< un[0]+(hn*s[0]) <<std::endl;
            kn=f.eval(tn+c[i]+hn,un+hn*s);
            std::cout << "kn: " << un.size()<< "[";
                for (size_t p = 0; p < un.size(); ++p) {
                    std::cout << kn[p];
                    if (p != kn.size() - 1) std::cout << ", ";
                }
                std::cout << "]" ", y size: " << s.size() << std::endl;
       
        }

        //assert(k.size()==k_col.size());
        //std::cout << "x size: " << k.size() << ", y size: " << kn.size() << std::endl;
        k.push_back(kn);
        std::cout<<"ksize: "<<k.size()<<std::endl;

    }
    for (size_t i =0;i<n_stages;i++){
        std::vector<double> ksol;

        std::cout << "sum: " << sum.size() << ", ksol: " <<"aa"<<typeid(k).name()<< std::endl;
        sum = sum + b[i]*k[i];
        std::cout << sum[0] << b[i] << k[i].size()<< std::endl;
        
    }
    un1 = un  + h*sum;
    std::cout<<"un+1: "<<un1[0]<<std::endl;

    return un1;
    // Your code goes here
    // N.B.: the initial condition (t_0, u_0) has already been included in the
    // `times` and `solution` vectors by the class constructor (see above)
}

void RKSolver::solve()
{
    int n = 0;
    //double t0 = equation.get_tin();
    double t = equation.get_tin();
    double hn = h;
    //double tf = equation.get_tfin();
    Rnvector u = equation.get_x0();
    std::vector<double> uhn;
    std::vector<double> uhn2;
    std::vector<double> diff_un;
    std::vector<double> un1;
    double *n_diff;
    double *n_un;
    double En;
    //double t1;
    std::vector<double> abs_un;
    uhn = single_step(t,u,hn);
    //while(t+hn<=tf){
    while(0<n){
        uhn = single_step(t,u,hn);
        uhn2 = single_step(t,u,hn/2);
        diff_un = abs(uhn2 -uhn);
        n_diff = std::max_element(diff_un.data(),diff_un.data()+diff_un.size());
        abs_un= abs(uhn);
        n_un = std::max_element(abs_un.data(),abs_un.data()+abs_un.size());
        En= *n_diff/(*n_un);
        if (En<tol/2 || hn<hmin){
            t = t+hn;
            u = uhn2;
            if(En<tol/(pow(2,n_stages+1))){
                hn=2*hn;
            }
            n=n+1;
        }else{
            hn = hn/2;
        }


    }
    /*hn = tf-t;
    if (hn>(tf-t0)/pow(10,3)){
        t1 = tf;
        un1 = single_step(t1,u,hn/2);
    }*/
    
    // Your code goes here
}
