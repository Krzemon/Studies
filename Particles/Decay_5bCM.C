#include <iostream>
#include "TMath.h"
#include "TLorentzVector.h"
#include "TRandom3.h"

void Decay_5bCM(){
	//zadanie 5 - 3
	TLorentzVector Ks(.0,.0,.0,0.892);
	Double_t masses[2] = { 0.494, 0.135};		
	TGenPhaseSpace event;
	
	Int_t nPoints = 1e6;
    const Double_t minMomentum = 0.0;
    const Double_t maxMomentum = 1.0;

    TRandom3 randGen;
    TH2F* hist1 = new TH2F("hist1", "#Phi_{1}^{CM}(P) K^{-}", 100, 0, 0.2, 100, 0,3.2);
    TH2F* hist2 = new TH2F("hist2", "#Phi_{2}^{CM}(P) #pi^{0}", 100, 0, 0.2, 100, 0,3.2);
    TH2F* hist3 = new TH2F("hist3", "#Phi_{3}^{CM}(P) = #Phi_{1} - #Phi_{2}", 100, 0, 0.2, 100, 0,3.2);

	for(Int_t n=0; n<nPoints; ++n){
	
		Double_t x = randGen.Gaus(0,0.025);
		Double_t y = randGen.Gaus(0,0.025);
		Double_t z = randGen.Gaus(0,0.025);
		TLorentzVector KS(x,y,z,sqrt(x*x + y*y + z*z + Ks.E()*Ks.E()));
		TLorentzVector KS_CM = KS;
		KS_CM.Boost(-KS.BoostVector());
		
		event.SetDecay(KS_CM, 2, masses);
		Double_t weight = event.Generate();
		TLorentzVector *Km  = event.GetDecay(0);
		TLorentzVector *Pi0 = event.GetDecay(1);
		TLorentzVector sum = *Km + *Pi0;
 		if(Km->Pt()>0.25){
        	hist1->Fill(KS_CM.P(), Km->Phi(), weight);
 		}
 		if(Km->Pt()>0.25){
			hist2->Fill(KS_CM.P(), Pi0->Phi(), weight);	
 		}
 		if(Km->Pt()>0.25 && Km->Pt()>0.25 && (Km->Phi()-Pi0->Phi())<TMath::Pi()){
			hist3->Fill(KS_CM.P(), Km->Phi()-Pi0->Phi(), weight);	
 		}
	}
	TCanvas *A = new TCanvas("A","histograms",1800,600);
	A->Divide(3,1);
	A->cd(1);
    hist1->GetXaxis()->SetTitle("P [Gev/c]");
    hist1->GetYaxis()->SetTitle("#Phi_{1} [rad]");
    hist1->Draw("COLZ");
    A->cd(2);
    hist2->GetXaxis()->SetTitle("P [Gev/c]");
    hist2->GetYaxis()->SetTitle("#Phi_{2} [rad]");
    hist2->Draw("COLZ");
    A->cd(3);
    hist3->GetXaxis()->SetTitle("P [Gev/c]");
    hist3->GetYaxis()->SetTitle("#Phi_{3} [rad]");
    hist3->Draw("COLZ");
    
}
