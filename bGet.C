#include "label.h"
#include "noff.h"

#include <TFile.h>
#include <TH1.h>
using namespace std;
void bGet(int s1 = 0, int s2 = 10, int s3 = 10)
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	int NCent = NCent8TeV4;
	const int * pCent = CentNoffCutPA8TeV4;
	if ( s1==0 or s1==1 or s1==2 or s1==3 or s1==7 or s1==8 or s1==9 ) {
		NCent = NCentAA5TeV4;
		pCent = CentCutAA5TeV;
	}

	TFile * f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));

	TH1D * hPLmLm 		= (TH1D*) f->Get("hPLmLm");
	TH1D * hPLmLmBar	= (TH1D*) f->Get("hPLmLmBar");
	TH1D * hPLmBarLmBar	= (TH1D*) f->Get("hPLmBarLmBar");
	TH1D * hMPLmLm 		= (TH1D*) f->Get("hMPLmLm");
	TH1D * hMPLmLmBar	= (TH1D*) f->Get("hMPLmLmBar");
	TH1D * hMPLmBarLmBar	= (TH1D*) f->Get("hMPLmBarLmBar");

	TH1D * h1LmLm 		= (TH1D*) f->Get("h1LmLm");
	TH1D * h1LmLmBar	= (TH1D*) f->Get("h1LmLmBar");
	TH1D * h1LmBarLmBar	= (TH1D*) f->Get("h1LmBarLmBar");
	TH1D * hm1LmLm 		= (TH1D*) f->Get("hm1LmLm");
	TH1D * hm1LmLmBar	= (TH1D*) f->Get("hm1LmLmBar");
	TH1D * hm1LmBarLmBar	= (TH1D*) f->Get("hm1LmBarLmBar");

	TH1D * h2LmLm 		= (TH1D*) f->Get("h2LmLm");
	TH1D * h2LmLmBar	= (TH1D*) f->Get("h2LmLmBar");
	TH1D * h2LmBarLmBar	= (TH1D*) f->Get("h2LmBarLmBar");
	TH1D * hm2LmLm 		= (TH1D*) f->Get("hm2LmLm");
	TH1D * hm2LmLmBar	= (TH1D*) f->Get("hm2LmLmBar");
	TH1D * hm2LmBarLmBar	= (TH1D*) f->Get("hm2LmBarLmBar");

	TH1D * hNoff = (TH1D*) f->Get("hNoff");
	TH1D * hNV0  = (TH1D*) f->Get("hNV0");

	double dPLmLm[600] = {};
	double dPLmLmBar[600] = {};
	double dPLmBarLmBar[600] = {};
	double dMPLmLm[600] = {};
	double dMPLmLmBar[600] = {};
	double dMPLmBarLmBar[600] = {};

	double d1LmLm[600] = {};
	double d1LmLmBar[600] = {};
	double d1LmBarLmBar[600] = {};
	double e1LmLm[600] = {};
	double e1LmLmBar[600] = {};
	double e1LmBarLmBar[600] = {};

	double dm1LmLm[600] = {};
	double dm1LmLmBar[600] = {};
	double dm1LmBarLmBar[600] = {};
	double em1LmLm[600] = {};
	double em1LmLmBar[600] = {};
	double em1LmBarLmBar[600] = {};

	double d2LmLm[600] = {};
	double d2LmLmBar[600] = {};
	double d2LmBarLmBar[600] = {};
	double e2LmLm[600] = {};
	double e2LmLmBar[600] = {};
	double e2LmBarLmBar[600] = {};

	double dm2LmLm[600] = {};
	double dm2LmLmBar[600] = {};
	double dm2LmBarLmBar[600] = {};
	double em2LmLm[600] = {};
	double em2LmLmBar[600] = {};
	double em2LmBarLmBar[600] = {};

	double dPRLmLm[20] = {};
	double dPRLmLmBar[20] = {};
	double dPRLmBarLmBar[20] = {};

	double dMPRLmLm[20] = {};
	double dMPRLmLmBar[20] = {};
	double dMPRLmBarLmBar[20] = {};

	double d1RLmLm[20] = {};
	double d1RLmLmBar[20] = {};
	double d1RLmBarLmBar[20] = {};
	double e1RLmLm[20] = {};
	double e1RLmLmBar[20] = {};
	double e1RLmBarLmBar[20] = {};

	double dm1RLmLm[20] = {};
	double dm1RLmLmBar[20] = {};
	double dm1RLmBarLmBar[20] = {};
	double em1RLmLm[20] = {};
	double em1RLmLmBar[20] = {};
	double em1RLmBarLmBar[20] = {};

	double d2RLmLm[20] = {};
	double d2RLmLmBar[20] = {};
	double d2RLmBarLmBar[20] = {};
	double e2RLmLm[20] = {};
	double e2RLmLmBar[20] = {};
	double e2RLmBarLmBar[20] = {};

	double dm2RLmLm[20] = {};
	double dm2RLmLmBar[20] = {};
	double dm2RLmBarLmBar[20] = {};
	double em2RLmLm[20] = {};
	double em2RLmLmBar[20] = {};
	double em2RLmBarLmBar[20] = {};

	double dNoff[600] = {};
	double dRNoff[20] = {};

	for ( int c = 0; c < 600; c++ ) {
		dPLmLm[c]		= hPLmLm	->GetBinContent(c+1);
		dPLmLmBar[c]		= hPLmLmBar	->GetBinContent(c+1);
		dPLmBarLmBar[c]		= hPLmBarLmBar	->GetBinContent(c+1);
		dMPLmLm[c]		= hMPLmLm	->GetBinContent(c+1);
		dMPLmLmBar[c]		= hMPLmLmBar	->GetBinContent(c+1);
		dMPLmBarLmBar[c]	= hMPLmBarLmBar	->GetBinContent(c+1);

		d1LmLm[c]		= h1LmLm	->GetBinContent(c+1);
		d1LmLmBar[c]		= h1LmLmBar	->GetBinContent(c+1);
		d1LmBarLmBar[c]		= h1LmBarLmBar	->GetBinContent(c+1);
		e1LmLm[c]		= h1LmLm	->GetBinError(c+1);
		e1LmLmBar[c]		= h1LmLmBar	->GetBinError(c+1);
		e1LmBarLmBar[c]		= h1LmBarLmBar	->GetBinError(c+1);

		dm1LmLm[c]		= hm1LmLm	->GetBinContent(c+1);
		dm1LmLmBar[c]		= hm1LmLmBar	->GetBinContent(c+1);
		dm1LmBarLmBar[c]	= hm1LmBarLmBar	->GetBinContent(c+1);
		em1LmLm[c]		= hm1LmLm	->GetBinError(c+1);
		em1LmLmBar[c]		= hm1LmLmBar	->GetBinError(c+1);
		em1LmBarLmBar[c]	= hm1LmBarLmBar	->GetBinError(c+1);

		d2LmLm[c]		= h2LmLm	->GetBinContent(c+1);
		d2LmLmBar[c]		= h2LmLmBar	->GetBinContent(c+1);
		d2LmBarLmBar[c]		= h2LmBarLmBar	->GetBinContent(c+1);
		e2LmLm[c]		= h2LmLm	->GetBinError(c+1);
		e2LmLmBar[c]		= h2LmLmBar	->GetBinError(c+1);
		e2LmBarLmBar[c]		= h2LmBarLmBar	->GetBinError(c+1);

		dm2LmLm[c]		= hm2LmLm	->GetBinContent(c+1);
		dm2LmLmBar[c]		= hm2LmLmBar	->GetBinContent(c+1);
		dm2LmBarLmBar[c]	= hm2LmBarLmBar	->GetBinContent(c+1);
		em2LmLm[c]		= hm2LmLm	->GetBinError(c+1);
		em2LmLmBar[c]		= hm2LmLmBar	->GetBinError(c+1);
		em2LmBarLmBar[c]	= hm2LmBarLmBar	->GetBinError(c+1);

		dNoff[c]		= hNoff->GetBinContent(c+1);
	}

	// Rebin

	for ( int c = 0; c < NCent; c++ ) {
		double	sPLL = 0;
		double	sPLLbar = 0;
		double	sPLbarLbar = 0;
		double	sMPLL = 0;
		double	sMPLLbar = 0;
		double	sMPLbarLbar = 0;

		double	s1LL = 0;
		double	s1LLbar = 0;
		double	s1LbarLbar = 0;
		double	s2LL = 0;
		double	s2LLbar = 0;
		double	s2LbarLbar = 0;

		double	sm1LL = 0;
		double	sm1LLbar = 0;
		double	sm1LbarLbar = 0;
		double	sm2LL = 0;
		double	sm2LLbar = 0;
		double	sm2LbarLbar = 0;

		double	e1LL = 0;
		double	e1LLbar = 0;
		double	e1LbarLbar = 0;
		double	e2LL = 0;
		double	e2LLbar = 0;
		double	e2LbarLbar = 0;

		double	em1LL = 0;
		double	em1LLbar = 0;
		double	em1LbarLbar = 0;
		double	em2LL = 0;
		double	em2LLbar = 0;
		double	em2LbarLbar = 0;

		double	sNoff = 0;

		for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
			if ( m > 600 ) continue;
			sPLL		+= dPLmLm[m];
			sPLLbar		+= dPLmLmBar[m];
			sPLbarLbar	+= dPLmBarLmBar[m];

			sMPLL		+= dMPLmLm[m];
			sMPLLbar	+= dMPLmLmBar[m];
			sMPLbarLbar	+= dMPLmBarLmBar[m];

			s1LL		+= d1LmLm[m];
			s1LLbar		+= d1LmLmBar[m];
			s1LbarLbar	+= d1LmBarLmBar[m];
			s2LL		+= d2LmLm[m];
			s2LLbar		+= d2LmLmBar[m];
			s2LbarLbar	+= d2LmBarLmBar[m];

			sm1LL		+= dm1LmLm[m];
			sm1LLbar	+= dm1LmLmBar[m];
			sm1LbarLbar	+= dm1LmBarLmBar[m];
			sm2LL		+= dm2LmLm[m];
			sm2LLbar	+= dm2LmLmBar[m];
			sm2LbarLbar	+= dm2LmBarLmBar[m];

			e1LL		+= e1LmLm[m]		* e1LmLm[m];
			e1LLbar		+= e1LmLmBar[m]		* e1LmLmBar[m];
			e1LbarLbar	+= e1LmBarLmBar[m]	* e1LmBarLmBar[m];
			e2LL		+= e2LmLm[m]		* e2LmLm[m];
			e2LLbar		+= e2LmLmBar[m]		* e2LmLmBar[m];
			e2LbarLbar	+= e2LmBarLmBar[m]	* e2LmBarLmBar[m];

			em1LL		+= em1LmLm[m]		* em1LmLm[m];
			em1LLbar	+= em1LmLmBar[m]	* em1LmLmBar[m];
			em1LbarLbar	+= em1LmBarLmBar[m]	* em1LmBarLmBar[m];
			em2LL		+= em2LmLm[m]		* em2LmLm[m];
			em2LLbar	+= em2LmLmBar[m]	* em2LmLmBar[m];
			em2LbarLbar	+= em2LmBarLmBar[m]	* em2LmBarLmBar[m];

			sNoff		+= dNoff[m];
		}
		if ( sPLL )		s1LL		/= sPLL;
		if ( sPLLbar )		s1LLbar		/= sPLLbar;
		if ( sPLbarLbar )	s1LbarLbar	/= sPLbarLbar;
		if ( sPLL )		s2LL		/= sPLL;
		if ( sPLLbar )		s2LLbar		/= sPLLbar;
		if ( sPLbarLbar )	s2LbarLbar	/= sPLbarLbar;

		if ( sMPLL )		sm1LL		/= sMPLL;
		if ( sMPLLbar )		sm1LLbar	/= sMPLLbar;
		if ( sMPLbarLbar )	sm1LbarLbar	/= sMPLbarLbar;
		if ( sMPLL )		sm2LL		/= sMPLL;
		if ( sMPLLbar )		sm2LLbar	/= sMPLLbar;
		if ( sMPLbarLbar )	sm2LbarLbar	/= sMPLbarLbar;

		if ( sPLL )		e1LL		= sqrt(e1LL)		/sPLL;
		if ( sPLLbar )		e1LLbar		= sqrt(e1LLbar)		/sPLLbar;
		if ( sPLbarLbar )	e1LbarLbar	= sqrt(e1LbarLbar)	/sPLbarLbar;
		if ( sPLL )		e2LL		= sqrt(e2LL)		/sPLL;
		if ( sPLLbar )		e2LLbar		= sqrt(e2LLbar)		/sPLLbar;
		if ( sPLbarLbar )	e2LbarLbar	= sqrt(e2LbarLbar)	/sPLbarLbar;

		if ( sMPLL )		em1LL		= sqrt(em1LL)		/sMPLL;
		if ( sMPLLbar )		em1LLbar	= sqrt(em1LLbar)	/sMPLLbar;
		if ( sMPLbarLbar )	em1LbarLbar	= sqrt(em1LbarLbar)	/sMPLbarLbar;
		if ( sMPLL )		em2LL		= sqrt(em2LL)		/sMPLL;
		if ( sMPLLbar )		em2LLbar	= sqrt(em2LLbar)	/sMPLLbar;
		if ( sMPLbarLbar )	em2LbarLbar	= sqrt(em2LbarLbar)	/sMPLbarLbar;

		if ( sPLL )		dPRLmLm[c]	= sPLL;
		if ( sPLLbar )		dPRLmLmBar[c]	= sPLLbar;
		if ( sPLbarLbar )	dPRLmBarLmBar[c]= sPLbarLbar;

		if ( sMPLL )		dMPRLmLm[c]		= sMPLL;
		if ( sMPLLbar )		dMPRLmLmBar[c]		= sMPLLbar;
		if ( sMPLbarLbar )	dMPRLmBarLmBar[c]	= sMPLbarLbar;

		d1RLmLm[c]		= s1LL;
		d1RLmLmBar[c]		= s1LLbar;
		d1RLmBarLmBar[c]	= s1LbarLbar;
		d2RLmLm[c]		= s2LL;
		d2RLmLmBar[c]		= s2LLbar;
		d2RLmBarLmBar[c]	= s2LbarLbar;

		dm1RLmLm[c]		= sm1LL;
		dm1RLmLmBar[c]		= sm1LLbar;
		dm1RLmBarLmBar[c]	= sm1LbarLbar;
		dm2RLmLm[c]		= sm2LL;
		dm2RLmLmBar[c]		= sm2LLbar;
		dm2RLmBarLmBar[c]	= sm2LbarLbar;

		e1RLmLm[c]		= e1LL;
		e1RLmLmBar[c]		= e1LLbar;
		e1RLmBarLmBar[c]	= e1LbarLbar;
		e2RLmLm[c]		= e2LL;
		e2RLmLmBar[c]		= e2LLbar;
		e2RLmBarLmBar[c]	= e2LbarLbar;

		em1RLmLm[c]		= em1LL;
		em1RLmLmBar[c]		= em1LLbar;
		em1RLmBarLmBar[c]	= em1LbarLbar;
		em2RLmLm[c]		= em2LL;
		em2RLmLmBar[c]		= em2LLbar;
		em2RLmBarLmBar[c]	= em2LbarLbar;

		dRNoff[c]	= sNoff;
	}

	TH1D * hPRLmLm		= new TH1D("hPRLmLm",       "hPRLmLm", 20, 0, 20);
	TH1D * hPRLmLmBar	= new TH1D("hPRLmLmBar",    "hPRLmLmBar", 20, 0, 20);
	TH1D * hPRLmBarLmBar	= new TH1D("hPRLmBarLmBar", "hPRLmBarLmBar", 20, 0, 20);

	TH1D * hMPRLmLm		= new TH1D("hMPRLmLm",       "hMPRLmLm", 20, 0, 20);
	TH1D * hMPRLmLmBar	= new TH1D("hMPRLmLmBar",    "hMPRLmLmBar", 20, 0, 20);
	TH1D * hMPRLmBarLmBar	= new TH1D("hMPRLmBarLmBar", "hMPRLmBarLmBar", 20, 0, 20);

	TH1D * h1RLmLm		= new TH1D("h1RLmLm",       "h1RLmLm", 20, 0, 20);
	TH1D * h1RLmLmBar	= new TH1D("h1RLmLmBar",    "h1RLmLmBar", 20, 0, 20);
	TH1D * h1RLmBarLmBar	= new TH1D("h1RLmBarLmBar", "h1RLmBarLmBar", 20, 0, 20);

	TH1D * hm1RLmLm		= new TH1D("hm1RLmLm",       "hm1RLmLm", 20, 0, 20);
	TH1D * hm1RLmLmBar	= new TH1D("hm1RLmLmBar",    "hm1RLmLmBar", 20, 0, 20);
	TH1D * hm1RLmBarLmBar	= new TH1D("hm1RLmBarLmBar", "hm1RLmBarLmBar", 20, 0, 20);

	TH1D * h2RLmLm		= new TH1D("h2RLmLm",       "h2RLmLm", 20, 0, 20);
	TH1D * h2RLmLmBar	= new TH1D("h2RLmLmBar",    "h2RLmLmBar", 20, 0, 20);
	TH1D * h2RLmBarLmBar	= new TH1D("h2RLmBarLmBar", "h2RLmBarLmBar", 20, 0, 20);

	TH1D * hm2RLmLm		= new TH1D("hm2RLmLm",       "hm2RLmLm", 20, 0, 20);
	TH1D * hm2RLmLmBar	= new TH1D("hm2RLmLmBar",    "hm2RLmLmBar", 20, 0, 20);
	TH1D * hm2RLmBarLmBar	= new TH1D("hm2RLmBarLmBar", "hm2RLmBarLmBar", 20, 0, 20);

	TH1D * hRNoff		= new TH1D("hRNoff", "hRNoff", 20, 0, 20);

	for ( int c = 0; c < NCent; c++ ) {
		hPRLmLm		->SetBinContent( c+1, dPRLmLm[c] );
		hPRLmLmBar	->SetBinContent( c+1, dPRLmLmBar[c] );
		hPRLmBarLmBar	->SetBinContent( c+1, dPRLmBarLmBar[c] );

		hMPRLmLm	->SetBinContent( c+1, dMPRLmLm[c] );
		hMPRLmLmBar	->SetBinContent( c+1, dMPRLmLmBar[c] );
		hMPRLmBarLmBar	->SetBinContent( c+1, dMPRLmBarLmBar[c] );

		h1RLmLm		->SetBinContent( c+1, d1RLmLm[c] );
		h1RLmLmBar	->SetBinContent( c+1, d1RLmLmBar[c] );
		h1RLmBarLmBar	->SetBinContent( c+1, d1RLmBarLmBar[c] );
		h2RLmLm		->SetBinContent( c+1, d2RLmLm[c] );
		h2RLmLmBar	->SetBinContent( c+1, d2RLmLmBar[c] );
		h2RLmBarLmBar	->SetBinContent( c+1, d2RLmBarLmBar[c] );

		hm1RLmLm	->SetBinContent( c+1, dm1RLmLm[c] );
		hm1RLmLmBar	->SetBinContent( c+1, dm1RLmLmBar[c] );
		hm1RLmBarLmBar	->SetBinContent( c+1, dm1RLmBarLmBar[c] );
		hm2RLmLm	->SetBinContent( c+1, dm2RLmLm[c] );
		hm2RLmLmBar	->SetBinContent( c+1, dm2RLmLmBar[c] );
		hm2RLmBarLmBar	->SetBinContent( c+1, dm2RLmBarLmBar[c] );

		h1RLmLm		->SetBinError( c+1, e1RLmLm[c] );
		h1RLmLmBar	->SetBinError( c+1, e1RLmLmBar[c] );
		h1RLmBarLmBar	->SetBinError( c+1, e1RLmBarLmBar[c] );
		h2RLmLm		->SetBinError( c+1, e2RLmLm[c] );
		h2RLmLmBar	->SetBinError( c+1, e2RLmLmBar[c] );
		h2RLmBarLmBar	->SetBinError( c+1, e2RLmBarLmBar[c] );

		hm1RLmLm	->SetBinError( c+1, em1RLmLm[c] );
		hm1RLmLmBar	->SetBinError( c+1, em1RLmLmBar[c] );
		hm1RLmBarLmBar	->SetBinError( c+1, em1RLmBarLmBar[c] );
		hm2RLmLm	->SetBinError( c+1, em2RLmLm[c] );
		hm2RLmLmBar	->SetBinError( c+1, em2RLmLmBar[c] );
		hm2RLmBarLmBar	->SetBinError( c+1, em2RLmBarLmBar[c] );

		hRNoff		->SetBinContent( c+1, dRNoff[c] );
	}

	TFile * fwrite = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], s2, s3), "recreate");

	hPRLmLm		->Write();
	hPRLmLmBar	->Write();
	hPRLmBarLmBar	->Write();

	hMPRLmLm	->Write();
	hMPRLmLmBar	->Write();
	hMPRLmBarLmBar	->Write();

	h1RLmLm		->Write();
	h1RLmLmBar	->Write();
	h1RLmBarLmBar	->Write();

	hm1RLmLm	->Write();
	hm1RLmLmBar	->Write();
	hm1RLmBarLmBar	->Write();

	h2RLmLm		->Write();
	h2RLmLmBar	->Write();
	h2RLmBarLmBar	->Write();

	hm2RLmLm	->Write();
	hm2RLmLmBar	->Write();
	hm2RLmBarLmBar	->Write();

	hNoff		->Write();
	hNV0		->Write();
	hRNoff		->Write();
}
