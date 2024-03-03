#ifndef polynomial_h
#define polynomial_h
#include <iostream>
using namespace std;
#include<utility>

class Polynomial
{
protected:
    double *coefs_;
    int n_;

public:
    Polynomial(const int n, double *coefs)
        : coefs_(new double[n+1]{0}),
          n_(n)
    {
      for(int i = 0; i<=n; i++){
        coefs_[i] = coefs[i];
      }
    }

    Polynomial(const int n)
        : coefs_(new double[n + 1]{0}),
          n_(n)
    {
    }

    ~Polynomial(){
      if(coefs_ != nullptr){
        delete [] coefs_;
      }
    }

    Polynomial(const Polynomial &other) : Polynomial(other.n_)
    {
        for (int i = 0; i <= other.n_; i++)
        {
            coefs_[i] = other.coefs_[i];
        }
        n_ = other.n_;
    }

    Polynomial &operator=(const Polynomial &other)
    {
        delete[] coefs_;
        coefs_ = new double[other.n_+1];
        for (int i = 0; i <= other.n_; i++)
        {
            coefs_[i] = other.coefs_[i];
        }
        n_ = other.n_;
        return *this;
    }

    Polynomial(Polynomial &&other) : Polynomial(other.n_)
    {
        coefs_ = exchange(other.coefs_, nullptr);
        n_ = move(other.n_);
    }

    Polynomial &operator=(Polynomial &&other)
    {
        coefs_ = exchange(other.coefs_, nullptr);
        n_ = move(other.n_);
        return *this;
    }

    Polynomial &operator+=(Polynomial &prawy)
    {
        int max2 = n_;
        if(prawy.n_ > max2) max2 = prawy.n_;
        double *temp = new double[max2 + 1]{0};
        for (int i = 0; i <=n_; i++)
        {
            temp[i] = coefs_[i];
        }
        for (int i = 0; i <=prawy.n_; i++)
        {
            temp[i] += prawy.coefs_[i];
        }
        delete [] coefs_;
        coefs_ = temp;
        n_ = max(n_, prawy.n_);
        return *this;
    }

    Polynomial &operator*(const double liczba)
    {
        Polynomial *temp = new Polynomial(n_);
        for (int i = 0; i <= n_; i++)
        {
            temp->coefs_[i] = coefs_[i] * liczba;
        }
        return *temp;
    }

    double operator()(const double x)
    {
        double temp = coefs_[0];
        for(int i = 1; i<=n_; i++){
          temp += coefs_[i] * pow(x, i);
        }
        return temp;
    }

    friend ostream &operator<<(ostream &out, Polynomial &poly);
};

/// 0.333 +3.14*x^1 +1.42*x^3 +2.72*x^4

ostream &operator<<(ostream &out, Polynomial &poly)
{
    out << poly.coefs_[0];
    for (int i = 1; i <= poly.n_; i++)
    {
        if (poly.coefs_[i] != 0.)
            out << " +" << poly.coefs_[i] << "*x^" << i;
    }
    return out;
}

#endif
