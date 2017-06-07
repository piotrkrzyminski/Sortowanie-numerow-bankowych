#ifndef KONTO_H_INCLUDED
#define KONTO_H_INCLUDED

#include <string>
#include <stdexcept>

struct Konto {
    private:
        std::string country;
        std::string bank_account_number;
        std::string IBAN_number;
        std::string bank_code;

        void split();
        void checkData();
    public:
        Konto();
        Konto(std::string _IBAN_number);
        std::string getCountry() const;
        std::string getBankAccuntNumber() const;
        std::string getBankCode() const;
        std::string getIBANNumber() const;
        bool operator<(Konto& k);
        Konto& operator=(Konto& k);
};

#endif // KONTO_H_INCLUDED
