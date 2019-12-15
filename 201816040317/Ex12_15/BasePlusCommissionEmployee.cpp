#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h" //BasePlusCommissionEmployee class definition
using namespace std;

//constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn, double sales, double rate, double salary )
    :CommissionEmployee( first, last, ssn, sales, rate )
{
    setBaseSalary( salary ); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

//set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
    if ( salary >= 0.0 )
        baseSalary = salary;
    else
        throw invalid_argument( "Salary must be >= 0.0" );
} // end function setBaseSalary

//return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
} // end function getBaseSalary

//calculate earnings
double BasePlusCommissionEmployee::earnings()
{
    return getBaseSalary() + CommissionEmployee::earnings();
} // end function earnings

//print BasePlusCommissionEmployee's information
void BasePlusCommissionEmployee::print()
{
    cout << "base-salaried ";
    CommissionEmployee::print(); // code reuse
    cout << "; base salary: " << getBaseSalary();
} // end function print
