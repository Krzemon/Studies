#ifndef LEGENDRE
#define LEGENDRE

#include <cmath>
#include <utility>

class Legendre : public Polynomial{

public:
  Legendre(int n) : Polynomial(n){
    if(n%2 == 0){
      for(int i = 0; i<=n; i+=2){
        coefs_[i] = ( pow(-1, (n-i)/2) * (double)std::tgamma(n+i+1) ) / (pow(2,n) * (double)std::tgamma((n-i)/2 + 1) * std::tgamma((n+i)/2 + 1) * std::tgamma(i+1) );
      }
    }else{
      for(int i = 1; i<=n; i+=2){
        coefs_[i] = (pow(-1, (n-i)/2) * (double)std::tgamma(n+i+1) ) / (pow(2,n) * (double)std::tgamma((n-i)/2 + 1) * std::tgamma((n+i)/2 + 1) * std::tgamma(i+1) );
      }
    }
  }

  Legendre(const Legendre &p) : Polynomial(p.n_){
    for(int i = 0; i<n_; i++){
      coefs_[i] = p.coefs_[i];
    }
  }

  Legendre(Legendre &&p) : Polynomial(p.n_){
    n_ = std::move(p.n_);
    coefs_ = std::exchange(p.coefs_, nullptr);
  }

  Legendre operator =(Legendre &p){
    n_ = p.n_;
    if(coefs_ != nullptr)
      delete[] coefs_;
    coefs_ = new double[n_];
    for(int i = 0; i<n_; i++){
      coefs_[i] = p.coefs_[i];
    }
    return *this;
  }

  Legendre operator =(Legendre &&p){
    n_ = std::move(p.n_);
    coefs_ = std::exchange(p.coefs_, nullptr);
    return *this;
  }

};

#endif
