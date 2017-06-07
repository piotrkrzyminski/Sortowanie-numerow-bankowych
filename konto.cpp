#include "Konto.h"

/**
* Non-parameter constructor
*/
Konto::Konto() {
    country="";
    bank_account_number="";
    IBAN_number="";
    bank_code="";
}

/**
* Constructor with one argument. Line written from file.
* Call "split" function to set other string variables
*/
Konto::Konto(std::string _IBAN_number) {
    IBAN_number=_IBAN_number;
    split();
    checkData();
}

/**
* Method checks if bank account number has 26 digits, and if first two characters is "PL". If not throw excption
*/
void Konto::checkData() {
    if(country.compare("PL")!=0 && bank_account_number.size()!=26) throw std::logic_error("Dane maja niepoprawny format lub sa uszkodzone.\n");
}

/**
* Cut PL from beginning of IBAN number and assign it to variable as well as bank account number
*/
void Konto::split() {
    country=IBAN_number.substr(0, 2);
    bank_account_number=IBAN_number.substr(2, IBAN_number.size());
    bank_code=IBAN_number.substr(4,4);
}

/**
* Return country variable
*/
std::string Konto::getCountry() const {
    return country;
}

/**
* Return bank account number variable
*/
std::string Konto::getBankAccuntNumber() const {
    return bank_account_number;
}

/**
* Return 4 digits bank code
*/
std::string Konto::getBankCode() const {
    return bank_code;
}

/**
* Return IBAN number
*/
std::string Konto::getIBANNumber() const {
    return IBAN_number;
}


/**
* operator used to sort bank account number in sorted list
* returns false if it is not less
*/
bool Konto::operator<(Konto& k) {
    for(int i=0; i<(int)k.bank_account_number.size(); i++) {
        if(bank_account_number[0]>k.bank_account_number[0])
            return false;
    }

    return true;
}

/**
* equal operator
*/
Konto& Konto::operator=(Konto& k) {
    country=k.country;
    bank_account_number=k.bank_account_number;
    IBAN_number=k.IBAN_number;
    return *this;
}
