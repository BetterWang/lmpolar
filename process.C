#include "label.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TMath.h>
#include <TProfile.h>
using namespace std;
void process(int s1 = 0, int s2 = 10, int s3 = 10)
{
        cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
        TH1::SetDefaultSumw2();
        addchain(s1);

	vector<double>  *v1LmLm		= 0;
	vector<double>  *v1LmLmBar	= 0;
	vector<double>  *v1LmBarLmBar	= 0;

	vector<double>  *v2LmLm		= 0;
	vector<double>  *v2LmLmBar	= 0;
	vector<double>  *v2LmBarLmBar	= 0;

	int	Noff;
	int	NV0;


	chV->SetBranchAddress("v1LmLm",		&v1LmLm);
	chV->SetBranchAddress("v1LmLmBar",	&v1LmLmBar);
	chV->SetBranchAddress("v1LmBarLmBar",	&v1LmBarLmBar);

	chV->SetBranchAddress("v2LmLm",		&v2LmLm);
	chV->SetBranchAddress("v2LmLmBar",	&v2LmLmBar);
	chV->SetBranchAddress("v2LmBarLmBar",	&v2LmBarLmBar);

	chV->SetBranchAddress("Noff",		&Noff);
	chV->SetBranchAddress("NV0",		&NV0);

	TH1D * h1LmLm		= new TH1D("h1LmLm",       "h1LmLm", 600, 0, 600);
	TH1D * h1LmLmBar	= new TH1D("h1LmLmBar",    "h1LmLmBar", 600, 0, 600);
	TH1D * h1LmBarLmBar	= new TH1D("h1LmBarLmBar", "h1LmBarLmBar", 600, 0, 600);

	TH1D * h2LmLm		= new TH1D("h2LmLm",       "h2LmLm", 600, 0, 600);
	TH1D * h2LmLmBar	= new TH1D("h2LmLmBar",    "h2LmLmBar", 600, 0, 600);
	TH1D * h2LmBarLmBar	= new TH1D("h2LmBarLmBar", "h2LmBarLmBar", 600, 0, 600);


	TH1D * hNoff = new TH1D("hNoff", "hNoff", 200, 0, 200);
	TH1D * hNV0  = new TH1D("hNV0",  "hNV0",  20,  0, 20);

//	for ( int c = 0; c < 200; c++ ) {
//		h1LmLm[c]	= new TH1D(Form("h1LmLm_%i", c),	Form("h1LmLm_%i", c),		200, -1., 1.);
//		h1LmLmBar[c]	= new TH1D(Form("h1LmLmBar_%i", c),	Form("h1LmLmBar_%i", c),	200, -1., 1.);
//		h1LmBarLmBar[c]	= new TH1D(Form("h1LmBarLmBar_%i", c),	Form("h1LmBarLmBar_%i", c),	200, -1., 1.);
//
//		h2LmLm[c]	= new TH1D(Form("h2LmLm_%i", c),	Form("h2LmLm_%i", c),		200, -1., 1.);
//		h2LmLmBar[c]	= new TH1D(Form("h2LmLmBar_%i", c),	Form("h2LmLmBar_%i", c),	200, -1., 1.);
//		h2LmBarLmBar[c]	= new TH1D(Form("h2LmBarLmBar_%i", c),	Form("h2LmBarLmBar_%i", c),	200, -1., 1.);
//	}

	unsigned int ievt = 0;
        if ( s2 != s3 ) ievt = s2;

	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;

		for ( auto&& d : *v1LmLm ) {
			h1LmLm->Fill(Noff, d);
		}
		for ( auto&& d : *v1LmLmBar ) {
			h1LmLmBar->Fill(Noff, d);
		}
		for ( auto&& d : *v1LmBarLmBar ) {
			h1LmBarLmBar->Fill(Noff, d);
		}

		for ( auto&& d : *v2LmLm ) {
			h2LmLm->Fill(Noff, d);
		}
		for ( auto&& d : *v2LmLmBar ) {
			h2LmLmBar->Fill(Noff, d);
		}
		for ( auto&& d : *v2LmBarLmBar ) {
			h2LmBarLmBar->Fill(Noff, d);
		}

		hNoff->Fill(Noff);
		hNV0->Fill(NV0);
	}


	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	hNoff->Write();
	hNV0->Write();

	h1LmLm->Write();
	h1LmLmBar->Write();
	h1LmBarLmBar->Write();
	h2LmLm->Write();
	h2LmLmBar->Write();
	h2LmBarLmBar->Write();

}
