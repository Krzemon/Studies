#include <iostream>
#include "TMath.h"
#include "TLorentzVector.h"
#include "TRandom3.h"

void Decay_3(){
	//zadanie 4 - 1,2
	TLorentzVector Ks(.0,.0,.0,0.892);
	Double_t masses[2] = { 0.494, 0.135};		
	TGenPhaseSpace event;
	
	TRandom3 randGen;
	
	TH1F *Beta_Km  = new TH1F("Beta_Km","#beta K^{-}",100,0.0,1);
	TH1F *Beta_Pi0 = new TH1F("Beta_Pi0","#beta #Pi_{0}",100,0.0,1);
	TH1F *Gamma_Km  = new TH1F("Gamma_Km","#gamma K^{-}",100,1.0,3);
	TH1F *Gamma_Pi0 = new TH1F("Gamma_Pi0","#gamma #Pi_{0}",100,1.0,3);
	
	TH1F *P_Km = new TH1F("P_Km","P K^{-}",100,0.0,0.5);
	TH1F *P_Pi0 = new TH1F("P_Pi0","P #Pi_{0}",100,0.0,0.5);
	TH1F *Pt_Km  = new TH1F("Pt_Km","Pt K^{-}",100,0.0,0.35);
	TH1F *Pt_Pi0 = new TH1F("Pt_Pi0","Pt #Pi_{0}",100,0.0,0.35);
	
	TH1F *Theta_Km  = new TH1F("Theta_Km ","#Theta K^{-}",100,0,3.15);
	TH1F *Theta_Pi0 = new TH1F("Theta_Pi0","#Theta #Pi_{0}",100,0,3.15);
	TH1F *CosTheta_Km  = new TH1F("CosTheta_Km","cos(#Theta) K^{-}",100,-1.0,1.0);
	TH1F *CosTheta_Pi0 = new TH1F("CosTheta_Pi0","cos(#Theta) #Pi_{0}",100,-1.0,1.0);
	
	TH1F *Phi_Km  = new TH1F("Phi_Km","#Phi K^{-}",100,-3.15,3.15);
	TH1F *Phi_Pi0 = new TH1F("Phi_Pi0","#Phi #Pi_{0}",100,-3.15,3.15);
	TH1F *Eta_Km  = new TH1F("Eta_Km","#eta K^{-}",100,-5,5);
	TH1F *Eta_Pi0 = new TH1F("Eta_Pi0","#eta #Pi_{0}",100,-5,5);
	
	
	for(Int_t n=0; n<1e6; ++n){
	
		Double_t x = randGen.Gaus(0,0.025);
		Double_t y = randGen.Gaus(0,0.025);
		Double_t z = randGen.Gaus(0,0.025);
		TLorentzVector KS(x,y,z,sqrt(x*x + y*y + z*z + Ks.E()*Ks.E()));
		event.SetDecay(KS, 2, masses);
		
		Double_t weight = event.Generate();
		TLorentzVector *Km  = event.GetDecay(0);
		TLorentzVector *Pi0 = event.GetDecay(1);
		TLorentzVector sum = *Km + *Pi0;

		Beta_Km->Fill(Km->Beta(),weight);
		Beta_Pi0->Fill(Pi0->Beta(),weight);
		Gamma_Km->Fill(Km->Gamma(),weight);
		Gamma_Pi0->Fill(Pi0->Gamma(),weight);
		
		P_Km->Fill(Km->P(),weight);
		P_Pi0->Fill(Pi0->P(),weight);
		Pt_Km->Fill(Km->Pt(),weight);
		Pt_Pi0->Fill(Pi0->Pt(),weight);
		
		Theta_Km->Fill(Km->Theta(),weight);
		Theta_Pi0->Fill(Pi0->Theta(),weight);
		CosTheta_Km->Fill(TMath::Cos(Km->Theta()),weight);
		CosTheta_Pi0->Fill(TMath::Cos(Pi0->Theta()),weight);

		Phi_Km->Fill(Km->Phi(),weight);
		Phi_Pi0->Fill(Pi0->Phi(),weight);
		Eta_Km->Fill(Km->Eta(),weight);
		Eta_Pi0->Fill(Pi0->Eta(),weight);
	}
	TCanvas *A = new TCanvas("A","",1000,1000);
	A->Divide(2,2);
	A->cd(1);
	Beta_Km->GetXaxis()->SetTitle("#beta");
	Beta_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Beta_Km -> Draw();
	A->cd(2);
	Beta_Pi0->GetXaxis()->SetTitle("#beta");
	Beta_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Beta_Pi0 -> Draw();
	A->cd(3);
	Gamma_Km->GetXaxis()->SetTitle("#gamma");
	Gamma_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Gamma_Km -> Draw();
	A->cd(4);
	Gamma_Pi0->GetXaxis()->SetTitle("#gamma");
	Gamma_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Gamma_Pi0 -> Draw();
	
	TCanvas *B = new TCanvas("B","",1000,1000);
	B->Divide(2,2);
	B->cd(1);
	P_Km->GetXaxis()->SetTitle("P [GeV/c]");
	P_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	P_Km -> Draw();
	B->cd(2);
	P_Pi0->GetXaxis()->SetTitle("P [GeV/c]");
	P_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	P_Pi0 -> Draw();
	B->cd(3);
	Pt_Km->GetXaxis()->SetTitle("Pt [GeV/c]");
	Pt_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Pt_Km -> Draw();
	B->cd(4);
	Pt_Pi0->GetXaxis()->SetTitle("Pt [GeV/c]");
	Pt_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Pt_Pi0 -> Draw(); 	  
       	
	TCanvas *C = new TCanvas("C","",1000,1000);
	C->Divide(2,2);
	C->cd(1);
	Theta_Km->GetXaxis()->SetTitle("#Theta [rad]");
	Theta_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Theta_Km -> Draw();
	C->cd(2);
	Theta_Pi0->GetXaxis()->SetTitle("#Theta [rad]");
	Theta_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Theta_Pi0 -> Draw();
	C->cd(3);
	CosTheta_Km->GetXaxis()->SetTitle("Cos(#Theta)");
	CosTheta_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	CosTheta_Km -> Draw();
	C->cd(4);
	CosTheta_Pi0->GetXaxis()->SetTitle("Cos(#Theta)");
	CosTheta_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	CosTheta_Pi0 -> Draw();    	
       	
	TCanvas *D = new TCanvas("D","",1000,1000);
	D->Divide(2,2);
	D->cd(1);
	Phi_Km->GetXaxis()->SetTitle("#Phi [rad]");
	Phi_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Phi_Km -> Draw();
	D->cd(2);
	Phi_Pi0->GetXaxis()->SetTitle("#Phi [rad]");
	Phi_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Phi_Pi0 -> Draw();
	D->cd(3);
	Eta_Km->GetXaxis()->SetTitle("#eta [rad]");
	Eta_Km->GetYaxis()->SetTitle("Ilosc zliczen");
	Eta_Km -> Draw();
	D->cd(4);
	Eta_Pi0->GetXaxis()->SetTitle("#eta [rad]");
	Eta_Pi0->GetYaxis()->SetTitle("Ilosc zliczen");
	Eta_Pi0 -> Draw(); 
}

