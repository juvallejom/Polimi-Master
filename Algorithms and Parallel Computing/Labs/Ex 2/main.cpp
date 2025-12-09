// Price deviation evaluation v1

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw; // 


void print(const unsigned &count, const double &sum, const double prices[], const char area){
    if (count!=0){
        double average = sum / count;
        cout << "Area: "<<area<<endl;
        cout<<"Average: "<<average<<endl;
        cout << endl << setw(20) << "Prices C" << setw(40) << "Deviation from the mean" << endl;

        for (unsigned i = 0; i < count; ++i)
        {   
            double dev = prices[i]-average;
            cout<<prices[i]<<"  "<<dev<<endl;
        }
    }
}


int main (void)
{
    const unsigned MAXDIM = 100;
    double pricesS[MAXDIM],pricesC[MAXDIM];
    const char CENTER ='c',SUBURB = 's';
    unsigned countS = 0.0, countC = 0.0;
    double sumS = 0.0, sumC = 0.0;
    bool exit = false;
    double val;
    char area;

    while(!exit){
        cout<<"Input price :"; 
        cin >> val;

        cout << "Area : ";
        cin >> area;
        
        if(!cin || countS>=MAXDIM || countC >= MAXDIM || (area!=CENTER && area!=SUBURB) ){
            exit = true;
        }
        else{
            if(area==CENTER){
                pricesC[countC]=val;
                countC++;
                sumC+=val;
            }
            else{
                pricesS[countS]=val;
                countS++;
                sumS+=val;
            }

        }
    }

    print(countC,sumC,pricesC,CENTER);
    print(countS,sumS,pricesS,SUBURB);

    return 0;
}

