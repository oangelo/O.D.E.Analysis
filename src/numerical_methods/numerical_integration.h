#ifndef _NUMERICLA_INTEGRATION_
#define _NUMERICLA_INTEGRATION_

#include <vector>
#include <string>
#include <memory>
#include <iomanip>

#include "exceptions.h"
#include "../functions/functions.h"


class NumericalIntegration {
    public:
        NumericalIntegration(FunctionCapsule& function, labels_values initial_condition, value dt);
        NumericalIntegration(NumericalIntegration const& other);
        virtual ~NumericalIntegration(){};
        virtual NumericalIntegration* Clone() const = 0;
        virtual NumericalIntegration* Create(FunctionCapsule& function, labels_values initial_condition, value dt) const = 0;

        value get_dt() const;
        value get_t() const;
        const container & get_variable() const {return(variable);};
        const std::string & get_method_name() const {return(method);};
        labels_values get_labels_values() ;

        unsigned size() const;

        virtual NumericalIntegration& operator++() = 0; 

        //return the variables
        const value operator[] (std::string index) const;
        const value operator[] (size_t index) const;
        //return the variable ready to print
        friend std::ostream& operator<< (std::ostream &out, NumericalIntegration &object);

    protected:
        std::unique_ptr<FunctionCapsule> function;
        container variable;
        value dt, time;
        std::string method;

        //Prohibiting assignment because it makes no sense here
        NumericalIntegration & operator= (NumericalIntegration const & other); 
};

std::string Labels(NumericalIntegration &object);
#endif //_NUMERICLA_INTEGRATION_
