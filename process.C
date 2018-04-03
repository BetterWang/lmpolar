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

        int gNoff;
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);

	vector<double>  *phi;
	vector<double>  *eta;
	vector<double>  *rapidity;
	vector<double>  *pt;
	vector<double>  *mass;
	vector<double>  *weight;
	vector<double>  *pdgId;
	vector<double>  *pPhiCM;
	vector<double>  *nPhiCM;

	Double_t        arg_CaloQ1a;
	Double_t        argp_CaloQ1a;
	Double_t        argm_CaloQ1a;
	Double_t        abs_CaloQ1a;
	Double_t        absp_CaloQ1a;
	Double_t        absm_CaloQ1a;
	Double_t        arg_CaloQ1b;
	Double_t        argp_CaloQ1b;
	Double_t        argm_CaloQ1b;
	Double_t        abs_CaloQ1b;
	Double_t        absp_CaloQ1b;
	Double_t        absm_CaloQ1b;
	Double_t        arg_CaloQ1c;
	Double_t        argp_CaloQ1c;
	Double_t        argm_CaloQ1c;
	Double_t        abs_CaloQ1c;
	Double_t        absp_CaloQ1c;
	Double_t        absm_CaloQ1c;
	Double_t        arg_CaloQ1d;
	Double_t        argp_CaloQ1d;
	Double_t        argm_CaloQ1d;
	Double_t        abs_CaloQ1d;
	Double_t        absp_CaloQ1d;
	Double_t        absm_CaloQ1d;
	Double_t        arg_CaloQ1e;
	Double_t        argp_CaloQ1e;
	Double_t        argm_CaloQ1e;
	Double_t        abs_CaloQ1e;
	Double_t        absp_CaloQ1e;
	Double_t        absm_CaloQ1e;
	Double_t        arg_CaloQ1f;
	Double_t        argp_CaloQ1f;
	Double_t        argm_CaloQ1f;
	Double_t        abs_CaloQ1f;
	Double_t        absp_CaloQ1f;
	Double_t        absm_CaloQ1f;
	Double_t        arg_CaloQ1g;
	Double_t        argp_CaloQ1g;
	Double_t        argm_CaloQ1g;
	Double_t        abs_CaloQ1g;
	Double_t        absp_CaloQ1g;
	Double_t        absm_CaloQ1g;
	Double_t        arg_CaloQ2a;
	Double_t        argp_CaloQ2a;
	Double_t        argm_CaloQ2a;
	Double_t        abs_CaloQ2a;
	Double_t        absp_CaloQ2a;
	Double_t        absm_CaloQ2a;
	Double_t        arg_CaloQ2b;
	Double_t        argp_CaloQ2b;
	Double_t        argm_CaloQ2b;
	Double_t        abs_CaloQ2b;
	Double_t        absp_CaloQ2b;
	Double_t        absm_CaloQ2b;
	Double_t        arg_CaloQ2c;
	Double_t        argp_CaloQ2c;
	Double_t        argm_CaloQ2c;
	Double_t        abs_CaloQ2c;
	Double_t        absp_CaloQ2c;
	Double_t        absm_CaloQ2c;
	Double_t        arg_CaloQ2d;
	Double_t        argp_CaloQ2d;
	Double_t        argm_CaloQ2d;
	Double_t        abs_CaloQ2d;
	Double_t        absp_CaloQ2d;
	Double_t        absm_CaloQ2d;
	Double_t        arg_CaloQ2e;
	Double_t        argp_CaloQ2e;
	Double_t        argm_CaloQ2e;
	Double_t        abs_CaloQ2e;
	Double_t        absp_CaloQ2e;
	Double_t        absm_CaloQ2e;
	Double_t        arg_CaloQ2f;
	Double_t        argp_CaloQ2f;
	Double_t        argm_CaloQ2f;
	Double_t        abs_CaloQ2f;
	Double_t        absp_CaloQ2f;
	Double_t        absm_CaloQ2f;
	Double_t        arg_CaloQ2g;
	Double_t        argp_CaloQ2g;
	Double_t        argm_CaloQ2g;
	Double_t        abs_CaloQ2g;
	Double_t        absp_CaloQ2g;
	Double_t        absm_CaloQ2g;
	Double_t        _dcentralityBins;


	chV->SetBranchAddress("phi", &phi);
	chV->SetBranchAddress("eta", &eta);
	chV->SetBranchAddress("rapidity", &rapidity);
	chV->SetBranchAddress("pt", &pt);
	chV->SetBranchAddress("mass", &mass);
	chV->SetBranchAddress("weight", &weight);
	chV->SetBranchAddress("pdgId", &pdgId);
	chV->SetBranchAddress("pPhiCM", &pPhiCM);
	chV->SetBranchAddress("nPhiCM", &nPhiCM);

	chCaloV->SetBranchAddress("arg_CaloQ1a",&arg_CaloQ1a);
	chCaloV->SetBranchAddress("argp_CaloQ1a",&argp_CaloQ1a);
	chCaloV->SetBranchAddress("argm_CaloQ1a",&argm_CaloQ1a);
	chCaloV->SetBranchAddress("abs_CaloQ1a",&abs_CaloQ1a);
	chCaloV->SetBranchAddress("absp_CaloQ1a",&absp_CaloQ1a);
	chCaloV->SetBranchAddress("absm_CaloQ1a",&absm_CaloQ1a);
	chCaloV->SetBranchAddress("arg_CaloQ1b",&arg_CaloQ1b);
	chCaloV->SetBranchAddress("argp_CaloQ1b",&argp_CaloQ1b);
	chCaloV->SetBranchAddress("argm_CaloQ1b",&argm_CaloQ1b);
	chCaloV->SetBranchAddress("abs_CaloQ1b",&abs_CaloQ1b);
	chCaloV->SetBranchAddress("absp_CaloQ1b",&absp_CaloQ1b);
	chCaloV->SetBranchAddress("absm_CaloQ1b",&absm_CaloQ1b);
	chCaloV->SetBranchAddress("arg_CaloQ1c",&arg_CaloQ1c);
	chCaloV->SetBranchAddress("argp_CaloQ1c",&argp_CaloQ1c);
	chCaloV->SetBranchAddress("argm_CaloQ1c",&argm_CaloQ1c);
	chCaloV->SetBranchAddress("abs_CaloQ1c",&abs_CaloQ1c);
	chCaloV->SetBranchAddress("absp_CaloQ1c",&absp_CaloQ1c);
	chCaloV->SetBranchAddress("absm_CaloQ1c",&absm_CaloQ1c);
	chCaloV->SetBranchAddress("arg_CaloQ1d",&arg_CaloQ1d);
	chCaloV->SetBranchAddress("argp_CaloQ1d",&argp_CaloQ1d);
	chCaloV->SetBranchAddress("argm_CaloQ1d",&argm_CaloQ1d);
	chCaloV->SetBranchAddress("abs_CaloQ1d",&abs_CaloQ1d);
	chCaloV->SetBranchAddress("absp_CaloQ1d",&absp_CaloQ1d);
	chCaloV->SetBranchAddress("absm_CaloQ1d",&absm_CaloQ1d);
	chCaloV->SetBranchAddress("arg_CaloQ1e",&arg_CaloQ1e);
	chCaloV->SetBranchAddress("argp_CaloQ1e",&argp_CaloQ1e);
	chCaloV->SetBranchAddress("argm_CaloQ1e",&argm_CaloQ1e);
	chCaloV->SetBranchAddress("abs_CaloQ1e",&abs_CaloQ1e);
	chCaloV->SetBranchAddress("absp_CaloQ1e",&absp_CaloQ1e);
	chCaloV->SetBranchAddress("absm_CaloQ1e",&absm_CaloQ1e);
	chCaloV->SetBranchAddress("arg_CaloQ1f",&arg_CaloQ1f);
	chCaloV->SetBranchAddress("argp_CaloQ1f",&argp_CaloQ1f);
	chCaloV->SetBranchAddress("argm_CaloQ1f",&argm_CaloQ1f);
	chCaloV->SetBranchAddress("abs_CaloQ1f",&abs_CaloQ1f);
	chCaloV->SetBranchAddress("absp_CaloQ1f",&absp_CaloQ1f);
	chCaloV->SetBranchAddress("absm_CaloQ1f",&absm_CaloQ1f);
	chCaloV->SetBranchAddress("arg_CaloQ1g",&arg_CaloQ1g);
	chCaloV->SetBranchAddress("argp_CaloQ1g",&argp_CaloQ1g);
	chCaloV->SetBranchAddress("argm_CaloQ1g",&argm_CaloQ1g);
	chCaloV->SetBranchAddress("abs_CaloQ1g",&abs_CaloQ1g);
	chCaloV->SetBranchAddress("absp_CaloQ1g",&absp_CaloQ1g);
	chCaloV->SetBranchAddress("absm_CaloQ1g",&absm_CaloQ1g);
	chCaloV->SetBranchAddress("arg_CaloQ2a",&arg_CaloQ2a);
	chCaloV->SetBranchAddress("argp_CaloQ2a",&argp_CaloQ2a);
	chCaloV->SetBranchAddress("argm_CaloQ2a",&argm_CaloQ2a);
	chCaloV->SetBranchAddress("abs_CaloQ2a",&abs_CaloQ2a);
	chCaloV->SetBranchAddress("absp_CaloQ2a",&absp_CaloQ2a);
	chCaloV->SetBranchAddress("absm_CaloQ2a",&absm_CaloQ2a);
	chCaloV->SetBranchAddress("arg_CaloQ2b",&arg_CaloQ2b);
	chCaloV->SetBranchAddress("argp_CaloQ2b",&argp_CaloQ2b);
	chCaloV->SetBranchAddress("argm_CaloQ2b",&argm_CaloQ2b);
	chCaloV->SetBranchAddress("abs_CaloQ2b",&abs_CaloQ2b);
	chCaloV->SetBranchAddress("absp_CaloQ2b",&absp_CaloQ2b);
	chCaloV->SetBranchAddress("absm_CaloQ2b",&absm_CaloQ2b);
	chCaloV->SetBranchAddress("arg_CaloQ2c",&arg_CaloQ2c);
	chCaloV->SetBranchAddress("argp_CaloQ2c",&argp_CaloQ2c);
	chCaloV->SetBranchAddress("argm_CaloQ2c",&argm_CaloQ2c);
	chCaloV->SetBranchAddress("abs_CaloQ2c",&abs_CaloQ2c);
	chCaloV->SetBranchAddress("absp_CaloQ2c",&absp_CaloQ2c);
	chCaloV->SetBranchAddress("absm_CaloQ2c",&absm_CaloQ2c);
	chCaloV->SetBranchAddress("arg_CaloQ2d",&arg_CaloQ2d);
	chCaloV->SetBranchAddress("argp_CaloQ2d",&argp_CaloQ2d);
	chCaloV->SetBranchAddress("argm_CaloQ2d",&argm_CaloQ2d);
	chCaloV->SetBranchAddress("abs_CaloQ2d",&abs_CaloQ2d);
	chCaloV->SetBranchAddress("absp_CaloQ2d",&absp_CaloQ2d);
	chCaloV->SetBranchAddress("absm_CaloQ2d",&absm_CaloQ2d);
	chCaloV->SetBranchAddress("arg_CaloQ2e",&arg_CaloQ2e);
	chCaloV->SetBranchAddress("argp_CaloQ2e",&argp_CaloQ2e);
	chCaloV->SetBranchAddress("argm_CaloQ2e",&argm_CaloQ2e);
	chCaloV->SetBranchAddress("abs_CaloQ2e",&abs_CaloQ2e);
	chCaloV->SetBranchAddress("absp_CaloQ2e",&absp_CaloQ2e);
	chCaloV->SetBranchAddress("absm_CaloQ2e",&absm_CaloQ2e);
	chCaloV->SetBranchAddress("arg_CaloQ2f",&arg_CaloQ2f);
	chCaloV->SetBranchAddress("argp_CaloQ2f",&argp_CaloQ2f);
	chCaloV->SetBranchAddress("argm_CaloQ2f",&argm_CaloQ2f);
	chCaloV->SetBranchAddress("abs_CaloQ2f",&abs_CaloQ2f);
	chCaloV->SetBranchAddress("absp_CaloQ2f",&absp_CaloQ2f);
	chCaloV->SetBranchAddress("absm_CaloQ2f",&absm_CaloQ2f);
	chCaloV->SetBranchAddress("arg_CaloQ2g",&arg_CaloQ2g);
	chCaloV->SetBranchAddress("argp_CaloQ2g",&argp_CaloQ2g);
	chCaloV->SetBranchAddress("argm_CaloQ2g",&argm_CaloQ2g);
	chCaloV->SetBranchAddress("abs_CaloQ2g",&abs_CaloQ2g);
	chCaloV->SetBranchAddress("absp_CaloQ2g",&absp_CaloQ2g);
	chCaloV->SetBranchAddress("absm_CaloQ2g",&absm_CaloQ2g);
	chCaloV->SetBranchAddress("_dcentralityBins",&_dcentralityBins);


	TH1D * hQ1PhiS[7][200];
	TH1D * hQ1PhiP[7][200];
	TH1D * hQ1PhiN[7][200];

	TH1D * hQ2PhiS[7][200];
	TH1D * hQ2PhiP[7][200];
	TH1D * hQ2PhiN[7][200];

	TH1D * hQ1Res[7][200];
	TH1D * hQ2Res[7][200];

	TProfile * hQ1ResSP[7];
	TProfile * hQ2ResSP[7];

//	double Q1Rho[7][200];
//	double Q1RhoP[7][200];
//	double Q1RhoN[7][200];

	for ( int c = 0; c < 200; c++ ) {
		for ( int i = 0; i < 7; i++ ) {
			hQ1PhiS[i][c] = new TH1D(Form("hQ1PhiS_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());
			hQ1PhiP[i][c] = new TH1D(Form("hQ1PhiP_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());
			hQ1PhiN[i][c] = new TH1D(Form("hQ1PhiN_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());

			hQ2PhiS[i][c] = new TH1D(Form("hQ2PhiS_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());
			hQ2PhiP[i][c] = new TH1D(Form("hQ2PhiP_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());
			hQ2PhiN[i][c] = new TH1D(Form("hQ2PhiN_%i_%i", i, c), "", 64, -TMath::Pi(), TMath::Pi());

			hQ1Res[i][c]  = new TH1D(Form("hQ1Res_%i_%i", i, c), "", 100, -1., 1.);
			hQ2Res[i][c]  = new TH1D(Form("hQ2Res_%i_%i", i, c), "", 100, -1., 1.);
		}
	}
	for ( int i = 0; i < 7; i++ ) {
		hQ1ResSP[i] = new TProfile(Form("hQ1ResSP_%i", i), "", 200, 0, 200 );
		hQ2ResSP[i] = new TProfile(Form("hQ2ResSP_%i", i), "", 200, 0, 200 );
	}

	unsigned int ievt = 0;
        if ( s2 != s3 ) ievt = s2;
	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;

		gNoff = int(_dcentralityBins);
		hQ1PhiS[0][gNoff]->Fill(arg_CaloQ1a);
		hQ1PhiS[1][gNoff]->Fill(arg_CaloQ1b);
		hQ1PhiS[2][gNoff]->Fill(arg_CaloQ1c);
		hQ1PhiS[3][gNoff]->Fill(arg_CaloQ1d);
		hQ1PhiS[4][gNoff]->Fill(arg_CaloQ1e);
		hQ1PhiS[5][gNoff]->Fill(arg_CaloQ1f);
		hQ1PhiS[6][gNoff]->Fill(arg_CaloQ1g);

		hQ1PhiP[0][gNoff]->Fill(argp_CaloQ1a);
		hQ1PhiP[1][gNoff]->Fill(argp_CaloQ1b);
		hQ1PhiP[2][gNoff]->Fill(argp_CaloQ1c);
		hQ1PhiP[3][gNoff]->Fill(argp_CaloQ1d);
		hQ1PhiP[4][gNoff]->Fill(argp_CaloQ1e);
		hQ1PhiP[5][gNoff]->Fill(argp_CaloQ1f);
		hQ1PhiP[6][gNoff]->Fill(argp_CaloQ1g);

		hQ1PhiN[0][gNoff]->Fill(argm_CaloQ1a);
		hQ1PhiN[1][gNoff]->Fill(argm_CaloQ1b);
		hQ1PhiN[2][gNoff]->Fill(argm_CaloQ1c);
		hQ1PhiN[3][gNoff]->Fill(argm_CaloQ1d);
		hQ1PhiN[4][gNoff]->Fill(argm_CaloQ1e);
		hQ1PhiN[5][gNoff]->Fill(argm_CaloQ1f);
		hQ1PhiN[6][gNoff]->Fill(argm_CaloQ1g);

		hQ2PhiS[0][gNoff]->Fill(arg_CaloQ2a);
		hQ2PhiS[1][gNoff]->Fill(arg_CaloQ2b);
		hQ2PhiS[2][gNoff]->Fill(arg_CaloQ2c);
		hQ2PhiS[3][gNoff]->Fill(arg_CaloQ2d);
		hQ2PhiS[4][gNoff]->Fill(arg_CaloQ2e);
		hQ2PhiS[5][gNoff]->Fill(arg_CaloQ2f);
		hQ2PhiS[6][gNoff]->Fill(arg_CaloQ2g);

		hQ2PhiP[0][gNoff]->Fill(argp_CaloQ2a);
		hQ2PhiP[1][gNoff]->Fill(argp_CaloQ2b);
		hQ2PhiP[2][gNoff]->Fill(argp_CaloQ2c);
		hQ2PhiP[3][gNoff]->Fill(argp_CaloQ2d);
		hQ2PhiP[4][gNoff]->Fill(argp_CaloQ2e);
		hQ2PhiP[5][gNoff]->Fill(argp_CaloQ2f);
		hQ2PhiP[6][gNoff]->Fill(argp_CaloQ2g);

		hQ2PhiN[0][gNoff]->Fill(argm_CaloQ2a);
		hQ2PhiN[1][gNoff]->Fill(argm_CaloQ2b);
		hQ2PhiN[2][gNoff]->Fill(argm_CaloQ2c);
		hQ2PhiN[3][gNoff]->Fill(argm_CaloQ2d);
		hQ2PhiN[4][gNoff]->Fill(argm_CaloQ2e);
		hQ2PhiN[5][gNoff]->Fill(argm_CaloQ2f);
		hQ2PhiN[6][gNoff]->Fill(argm_CaloQ2g);

		hQ1Res[0][gNoff]->Fill( TMath::Cos(argp_CaloQ1a - argm_CaloQ1a) );
		hQ1Res[1][gNoff]->Fill( TMath::Cos(argp_CaloQ1b - argm_CaloQ1b) );
		hQ1Res[2][gNoff]->Fill( TMath::Cos(argp_CaloQ1c - argm_CaloQ1c) );
		hQ1Res[3][gNoff]->Fill( TMath::Cos(argp_CaloQ1d - argm_CaloQ1d) );
		hQ1Res[4][gNoff]->Fill( TMath::Cos(argp_CaloQ1e - argm_CaloQ1e) );
		hQ1Res[5][gNoff]->Fill( TMath::Cos(argp_CaloQ1f - argm_CaloQ1f) );
		hQ1Res[6][gNoff]->Fill( TMath::Cos(argp_CaloQ1g - argm_CaloQ1g) );

		hQ2Res[0][gNoff]->Fill( TMath::Cos( (argp_CaloQ2a - argm_CaloQ2a) ) );
		hQ2Res[1][gNoff]->Fill( TMath::Cos( (argp_CaloQ2b - argm_CaloQ2b) ) );
		hQ2Res[2][gNoff]->Fill( TMath::Cos( (argp_CaloQ2c - argm_CaloQ2c) ) );
		hQ2Res[3][gNoff]->Fill( TMath::Cos( (argp_CaloQ2d - argm_CaloQ2d) ) );
		hQ2Res[4][gNoff]->Fill( TMath::Cos( (argp_CaloQ2e - argm_CaloQ2e) ) );
		hQ2Res[5][gNoff]->Fill( TMath::Cos( (argp_CaloQ2f - argm_CaloQ2f) ) );
		hQ2Res[6][gNoff]->Fill( TMath::Cos( (argp_CaloQ2g - argm_CaloQ2g) ) );

		hQ1ResSP[0]->Fill( gNoff, absp_CaloQ1a * absm_CaloQ1a * TMath::Cos(argp_CaloQ1a - argm_CaloQ1a) );
		hQ1ResSP[1]->Fill( gNoff, absp_CaloQ1b * absm_CaloQ1b * TMath::Cos(argp_CaloQ1b - argm_CaloQ1b) );
		hQ1ResSP[2]->Fill( gNoff, absp_CaloQ1c * absm_CaloQ1c * TMath::Cos(argp_CaloQ1c - argm_CaloQ1c) );
		hQ1ResSP[3]->Fill( gNoff, absp_CaloQ1d * absm_CaloQ1d * TMath::Cos(argp_CaloQ1d - argm_CaloQ1d) );
		hQ1ResSP[4]->Fill( gNoff, absp_CaloQ1e * absm_CaloQ1e * TMath::Cos(argp_CaloQ1e - argm_CaloQ1e) );
		hQ1ResSP[5]->Fill( gNoff, absp_CaloQ1f * absm_CaloQ1f * TMath::Cos(argp_CaloQ1f - argm_CaloQ1f) );
		hQ1ResSP[6]->Fill( gNoff, absp_CaloQ1g * absm_CaloQ1g * TMath::Cos(argp_CaloQ1g - argm_CaloQ1g) );

		hQ2ResSP[0]->Fill( gNoff, absp_CaloQ2a * absm_CaloQ2a * TMath::Cos(argp_CaloQ2a - argm_CaloQ2a) );
		hQ2ResSP[1]->Fill( gNoff, absp_CaloQ2b * absm_CaloQ2b * TMath::Cos(argp_CaloQ2b - argm_CaloQ2b) );
		hQ2ResSP[2]->Fill( gNoff, absp_CaloQ2c * absm_CaloQ2c * TMath::Cos(argp_CaloQ2c - argm_CaloQ2c) );
		hQ2ResSP[3]->Fill( gNoff, absp_CaloQ2d * absm_CaloQ2d * TMath::Cos(argp_CaloQ2d - argm_CaloQ2d) );
		hQ2ResSP[4]->Fill( gNoff, absp_CaloQ2e * absm_CaloQ2e * TMath::Cos(argp_CaloQ2e - argm_CaloQ2e) );
		hQ2ResSP[5]->Fill( gNoff, absp_CaloQ2f * absm_CaloQ2f * TMath::Cos(argp_CaloQ2f - argm_CaloQ2f) );
		hQ2ResSP[6]->Fill( gNoff, absp_CaloQ2g * absm_CaloQ2g * TMath::Cos(argp_CaloQ2g - argm_CaloQ2g) );

		hNoff->Fill(gNoff);
	}


	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int c = 0; c < 200; c++ ) {
		for ( int i = 0; i < 7; i++ ) {
			hQ1PhiS[i][c]->Write();
			hQ1PhiP[i][c]->Write();
			hQ1PhiN[i][c]->Write();

			hQ2PhiS[i][c]->Write();
			hQ2PhiP[i][c]->Write();
			hQ2PhiN[i][c]->Write();

			hQ1Res[i][c]->Write();
			hQ2Res[i][c]->Write();
		}
	}
	for ( int i = 0; i < 7; i++ ) {
		hQ1ResSP[i]->Write();
		hQ2ResSP[i]->Write();
	}
	hNoff->Write();
}
