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
	vector<double>  *m1LmLm		= 0;
	vector<double>  *m1LmLmBar	= 0;
	vector<double>  *m1LmBarLmBar	= 0;

	vector<double>  *v2LmLm		= 0;
	vector<double>  *v2LmLmBar	= 0;
	vector<double>  *v2LmBarLmBar	= 0;
	vector<double>  *m2LmLm		= 0;
	vector<double>  *m2LmLmBar	= 0;
	vector<double>  *m2LmBarLmBar	= 0;

	int	Noff;
	int	NV0;


	chV->SetBranchAddress("v1LmLm",		&v1LmLm);
	chV->SetBranchAddress("v1LmLmBar",	&v1LmLmBar);
	chV->SetBranchAddress("v1LmBarLmBar",	&v1LmBarLmBar);
	chV->SetBranchAddress("m1LmLm",		&m1LmLm);
	chV->SetBranchAddress("m1LmLmBar",	&m1LmLmBar);
	chV->SetBranchAddress("m1LmBarLmBar",	&m1LmBarLmBar);

	chV->SetBranchAddress("v2LmLm",		&v2LmLm);
	chV->SetBranchAddress("v2LmLmBar",	&v2LmLmBar);
	chV->SetBranchAddress("v2LmBarLmBar",	&v2LmBarLmBar);
	chV->SetBranchAddress("m2LmLm",		&m2LmLm);
	chV->SetBranchAddress("m2LmLmBar",	&m2LmLmBar);
	chV->SetBranchAddress("m2LmBarLmBar",	&m2LmBarLmBar);

	chV->SetBranchAddress("Noff",		&Noff);
	chV->SetBranchAddress("NV0",		&NV0);

	TH1D * hPLmLm		= new TH1D("hPLmLm",        "hPLmLm", 600, 0, 600);
	TH1D * hPLmLmBar	= new TH1D("hPLmLmBar",     "hPLmLmBar", 600, 0, 600);
	TH1D * hPLmBarLmBar	= new TH1D("hPLmBarLmBar",  "hPLmBarLmBar", 600, 0, 600);
	TH1D * hMPLmLm		= new TH1D("hMPLmLm",       "hMPLmLm", 600, 0, 600);
	TH1D * hMPLmLmBar	= new TH1D("hMPLmLmBar",    "hMPLmLmBar", 600, 0, 600);
	TH1D * hMPLmBarLmBar	= new TH1D("hMPLmBarLmBar", "hMPLmBarLmBar", 600, 0, 600);

	TH1D * h1LmLm		= new TH1D("h1LmLm",        "h1LmLm", 600, 0, 600);
	TH1D * h1LmLmBar	= new TH1D("h1LmLmBar",     "h1LmLmBar", 600, 0, 600);
	TH1D * h1LmBarLmBar	= new TH1D("h1LmBarLmBar",  "h1LmBarLmBar", 600, 0, 600);
	TH1D * hm1LmLm		= new TH1D("hm1LmLm",       "hm1LmLm", 600, 0, 600);
	TH1D * hm1LmLmBar	= new TH1D("hm1LmLmBar",    "hm1LmLmBar", 600, 0, 600);
	TH1D * hm1LmBarLmBar	= new TH1D("hm1LmBarLmBar", "hm1LmBarLmBar", 600, 0, 600);

	TH1D * h2LmLm		= new TH1D("h2LmLm",        "h2LmLm", 600, 0, 600);
	TH1D * h2LmLmBar	= new TH1D("h2LmLmBar",     "h2LmLmBar", 600, 0, 600);
	TH1D * h2LmBarLmBar	= new TH1D("h2LmBarLmBar",  "h2LmBarLmBar", 600, 0, 600);
	TH1D * hm2LmLm		= new TH1D("hm2LmLm",       "hm2LmLm", 600, 0, 600);
	TH1D * hm2LmLmBar	= new TH1D("hm2LmLmBar",    "hm2LmLmBar", 600, 0, 600);
	TH1D * hm2LmBarLmBar	= new TH1D("hm2LmBarLmBar", "hm2LmBarLmBar", 600, 0, 600);


	TH1D * hNoff = new TH1D("hNoff", "hNoff", 600, 0, 600);
	TH1D * hNV0  = new TH1D("hNV0",  "hNV0",  20,  0, 20);

	unsigned int ievt = 0;
        if ( s2 != s3 ) ievt = s2;

	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;

		for ( auto&& d : *v1LmLm ) {
			h1LmLm->Fill(Noff, d);
			hPLmLm->Fill(Noff);
		}
		for ( auto&& d : *v1LmLmBar ) {
			h1LmLmBar->Fill(Noff, d);
			hPLmLmBar->Fill(Noff);
		}
		for ( auto&& d : *v1LmBarLmBar ) {
			h1LmBarLmBar->Fill(Noff, d);
			hPLmBarLmBar->Fill(Noff);
		}
		for ( auto&& d : *m1LmLm ) {
			hm1LmLm->Fill(Noff, d);
			hMPLmLm->Fill(Noff);
		}
		for ( auto&& d : *m1LmLmBar ) {
			hm1LmLmBar->Fill(Noff, d);
			hMPLmLmBar->Fill(Noff);
		}
		for ( auto&& d : *m1LmBarLmBar ) {
			hm1LmBarLmBar->Fill(Noff, d);
			hMPLmBarLmBar->Fill(Noff);
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
		for ( auto&& d : *m2LmLm ) {
			hm2LmLm->Fill(Noff, d);
		}
		for ( auto&& d : *m2LmLmBar ) {
			hm2LmLmBar->Fill(Noff, d);
		}
		for ( auto&& d : *m2LmBarLmBar ) {
			hm2LmBarLmBar->Fill(Noff, d);
		}

		hNoff->Fill(Noff);
		hNV0->Fill(NV0);
	}


	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	hNoff->Write();
	hNV0->Write();

	hPLmLm->Write();
	hPLmLmBar->Write();
	hPLmBarLmBar->Write();

	h1LmLm->Write();
	h1LmLmBar->Write();
	h1LmBarLmBar->Write();

	h2LmLm->Write();
	h2LmLmBar->Write();
	h2LmBarLmBar->Write();

}
