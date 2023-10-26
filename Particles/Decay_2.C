#include <iostream>
#include "TMath.h"
#include "TLorentzVector.h"
#include "TRandom3.h"

void Decay_2(){
	//zadanie 3
	TLorentzVector Ks(.0,.0,.0,0.892);
	Double_t masses[2] = { 0.494, 0.135};		
	TGenPhaseSpace event;
	event.SetDecay(Ks, 2, masses);
	
	Int_t nPoints = 100000;
    const Double_t minMomentum = 0.0;
    const Double_t maxMomentum = 1.0;

    TRandom3 randGen;
    TH2F* hist1 = new TH2F("hist1", "#Phi_{1}(P) K^{-}", 100, 0, 1, 100, 0,3.2);
    TH2F* hist2 = new TH2F("hist2", "#Phi_{2}(P) #pi^{0}", 100, 0, 1, 100, 0,3.2);
    TH2F* hist3 = new TH2F("hist3", "#Phi_{3} = #Phi_{1} - #Phi_{2}", 100, 0, 1, 100, 0,3.2);
	for(Int_t n=0; n<nPoints; ++n){
		Double_t weight = event.Generate();
		TLorentzVector *Km  = event.GetDecay(0);
		TLorentzVector *Pi0 = event.GetDecay(1);
		TLorentzVector sum = *Km + *Pi0;

        
		double mom = randGen.Uniform(minMomentum, maxMomentum);
		// lepszy rodzic
        TLorentzVector KS(0.0, 0.0, mom, sqrt(mom*mom + Ks.E()*Ks.E())); 
        hist1->Fill(KS.P(), Km->Phi(), weight);
		hist2->Fill(KS.P(), Pi0->Phi(), weight);
		hist3->Fill(KS.P(), Km->Phi()-Pi0->Phi(), weight);
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
