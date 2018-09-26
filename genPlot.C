#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "../../style.h"

void genPlot(int s1 =0)
{
	int NCent = NCent8TeV4;
	const double * CentX = CentPPbX4;
	double Xrange = 399.;
	if ( s1==0 or s1==1 or s1==2 or s1==3 or s1==7 or s1==8 or s1==9 ) {
		NCent = NCentAA5TeV4;
		CentX = CentPbPbX4;
		Xrange= 100.;
	}
	TFile *f = new TFile(Form("%s/outputC_10_10.root", ftxt[s1]));
	SetStyle();

	double d1LmLm[20]	= {};
	double d1LmLmBar[20]	= {};
	double d1LmBarLmBar[20]	= {};
	double e1LmLm[20]	= {};
	double e1LmLmBar[20]	= {};
	double e1LmBarLmBar[20]	= {};


	double d2LmLm[20]	= {};
	double d2LmLmBar[20]	= {};
	double d2LmBarLmBar[20]	= {};
	double e2LmLm[20]	= {};
	double e2LmLmBar[20]	= {};
	double e2LmBarLmBar[20]	= {};

	double dm1LmLm[20]		= {};
	double dm1LmLmBar[20]		= {};
	double dm1LmBarLmBar[20]	= {};
	double em1LmLm[20]		= {};
	double em1LmLmBar[20]		= {};
	double em1LmBarLmBar[20]	= {};

	double dm2LmLm[20]		= {};
	double dm2LmLmBar[20]		= {};
	double dm2LmBarLmBar[20]	= {};
	double em2LmLm[20]		= {};
	double em2LmLmBar[20]		= {};
	double em2LmBarLmBar[20]	= {};

	TH1D * h1RLmLm		= (TH1D*) f->Get("h1RLmLm");
	TH1D * h1RLmLmBar	= (TH1D*) f->Get("h1RLmLmBar");
	TH1D * h1RLmBarLmBar	= (TH1D*) f->Get("h1RLmBarLmBar");
	TH1D * h2RLmLm		= (TH1D*) f->Get("h2RLmLm");
	TH1D * h2RLmLmBar	= (TH1D*) f->Get("h2RLmLmBar");
	TH1D * h2RLmBarLmBar	= (TH1D*) f->Get("h2RLmBarLmBar");

	TH1D * hm1RLmLm		= (TH1D*) f->Get("hm1RLmLm");
	TH1D * hm1RLmLmBar	= (TH1D*) f->Get("hm1RLmLmBar");
	TH1D * hm1RLmBarLmBar	= (TH1D*) f->Get("hm1RLmBarLmBar");
	TH1D * hm2RLmLm		= (TH1D*) f->Get("hm2RLmLm");
	TH1D * hm2RLmLmBar	= (TH1D*) f->Get("hm2RLmLmBar");
	TH1D * hm2RLmBarLmBar	= (TH1D*) f->Get("hm2RLmBarLmBar");

	for ( int c = 0; c < 20; c++ ) {
		d1LmLm[c]		= h1RLmLm	->GetBinContent(c+1);
		d1LmLmBar[c]		= h1RLmLmBar	->GetBinContent(c+1);
		d1LmBarLmBar[c]		= h1RLmBarLmBar	->GetBinContent(c+1);
		d2LmLm[c]		= h2RLmLm	->GetBinContent(c+1);
		d2LmLmBar[c]		= h2RLmLmBar	->GetBinContent(c+1);
		d2LmBarLmBar[c]		= h2RLmBarLmBar	->GetBinContent(c+1);
		dm1LmLm[c]		= hm1RLmLm	->GetBinContent(c+1);
		dm1LmLmBar[c]		= hm1RLmLmBar	->GetBinContent(c+1);
		dm1LmBarLmBar[c]	= hm1RLmBarLmBar->GetBinContent(c+1);
		dm2LmLm[c]		= hm2RLmLm	->GetBinContent(c+1);
		dm2LmLmBar[c]		= hm2RLmLmBar	->GetBinContent(c+1);
		dm2LmBarLmBar[c]	= hm2RLmBarLmBar->GetBinContent(c+1);

		e1LmLm[c]		= h1RLmLm	->GetBinError(c+1);
		e1LmLmBar[c]		= h1RLmLmBar	->GetBinError(c+1);
		e1LmBarLmBar[c]		= h1RLmBarLmBar	->GetBinError(c+1);
		e2LmLm[c]		= h2RLmLm	->GetBinError(c+1);
		e2LmLmBar[c]		= h2RLmLmBar	->GetBinError(c+1);
		e2LmBarLmBar[c]		= h2RLmBarLmBar	->GetBinError(c+1);
		em1LmLm[c]		= hm1RLmLm	->GetBinError(c+1);
		em1LmLmBar[c]		= hm1RLmLmBar	->GetBinError(c+1);
		em1LmBarLmBar[c]	= hm1RLmBarLmBar->GetBinError(c+1);
		em2LmLm[c]		= hm2RLmLm	->GetBinError(c+1);
		em2LmLmBar[c]		= hm2RLmLmBar	->GetBinError(c+1);
		em2LmBarLmBar[c]	= hm2RLmBarLmBar->GetBinError(c+1);
	}

	TGraphErrors * gr1LmLm		= new TGraphErrors(NCent, CentX,	d1LmLm,		0,	e1LmLm);
	TGraphErrors * gr1LmLmBar	= new TGraphErrors(NCent, CentX,	d1LmLmBar,	0,	e1LmLmBar);
	TGraphErrors * gr1LmBarLmBar	= new TGraphErrors(NCent, CentX,	d1LmBarLmBar,	0,	e1LmBarLmBar);

	TGraphErrors * gr2LmLm		= new TGraphErrors(NCent, CentX,	d2LmLm,		0,	e2LmLm);
	TGraphErrors * gr2LmLmBar	= new TGraphErrors(NCent, CentX,	d2LmLmBar,	0,	e2LmLmBar);
	TGraphErrors * gr2LmBarLmBar	= new TGraphErrors(NCent, CentX,	d2LmBarLmBar,	0,	e2LmBarLmBar);

	TGraphErrors * gr1MLmLm		= new TGraphErrors(NCent, CentX,	dm1LmLm,	0,	em1LmLm);
	TGraphErrors * gr1MLmLmBar	= new TGraphErrors(NCent, CentX,	dm1LmLmBar,	0,	em1LmLmBar);
	TGraphErrors * gr1MLmBarLmBar	= new TGraphErrors(NCent, CentX,	dm1LmBarLmBar,	0,	em1LmBarLmBar);

	TGraphErrors * gr2MLmLm		= new TGraphErrors(NCent, CentX,	dm2LmLm,	0,	em2LmLm);
	TGraphErrors * gr2MLmLmBar	= new TGraphErrors(NCent, CentX,	dm2LmLmBar,	0,	em2LmLmBar);
	TGraphErrors * gr2MLmBarLmBar	= new TGraphErrors(NCent, CentX,	dm2LmBarLmBar,	0,	em2LmBarLmBar);

	gr1LmLm		->SetMarkerStyle( kFullCircle );
	gr1LmLmBar	->SetMarkerStyle( kFullCross );
	gr1LmBarLmBar	->SetMarkerStyle( kFullSquare );
	gr1MLmLm	->SetMarkerStyle( kOpenCircle );
	gr1MLmLmBar	->SetMarkerStyle( kOpenCross );
	gr1MLmBarLmBar	->SetMarkerStyle( kOpenSquare );

	gr1LmLm		->SetMarkerColor( kBlue );
	gr1LmLmBar	->SetMarkerColor( kRed );
	gr1LmBarLmBar	->SetMarkerColor( kBlack );
	gr1MLmLm	->SetMarkerColor( kBlue );
	gr1MLmLmBar	->SetMarkerColor( kRed );
	gr1MLmBarLmBar	->SetMarkerColor( kBlack );

	gr1LmLm		->SetLineColor( kBlue );
	gr1LmLmBar	->SetLineColor( kRed );
	gr1LmBarLmBar	->SetLineColor( kBlack );
	gr1MLmLm	->SetLineColor( kBlue );
	gr1MLmLmBar	->SetLineColor( kRed );
	gr1MLmBarLmBar	->SetLineColor( kBlack );

	gr2LmLm		->SetMarkerStyle( kFullCircle );
	gr2LmLmBar	->SetMarkerStyle( kFullCross );
	gr2LmBarLmBar	->SetMarkerStyle( kFullSquare );
	gr2MLmLm	->SetMarkerStyle( kOpenCircle );
	gr2MLmLmBar	->SetMarkerStyle( kOpenCross );
	gr2MLmBarLmBar	->SetMarkerStyle( kOpenSquare );

	gr2LmLm		->SetMarkerColor( kBlue );
	gr2LmLmBar	->SetMarkerColor( kRed );
	gr2LmBarLmBar	->SetMarkerColor( kBlack );
	gr2MLmLm	->SetMarkerColor( kBlue );
	gr2MLmLmBar	->SetMarkerColor( kRed );
	gr2MLmBarLmBar	->SetMarkerColor( kBlack );

	gr2LmLm		->SetLineColor( kBlue );
	gr2LmLmBar	->SetLineColor( kRed );
	gr2LmBarLmBar	->SetLineColor( kBlack );
	gr2MLmLm	->SetLineColor( kBlue );
	gr2MLmLmBar	->SetLineColor( kRed );
	gr2MLmBarLmBar	->SetLineColor( kBlack );

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);
	TH2D * hframe_cent = new TH2D("hframe_cent", "", 1, 0, Xrange, 1, -0.005, 0.02);
	InitHist(hframe_cent, "N_{trk}^{offline}", "sin^{2}");
	hframe_cent->Draw();
	gr1LmLm		->Draw("Psame");
	gr1LmLmBar	->Draw("Psame");
	gr1LmBarLmBar	->Draw("Psame");
	gr1MLmLm	->Draw("Psame");
	gr1MLmLmBar	->Draw("Psame");
	gr1MLmBarLmBar	->Draw("Psame");

	cT->SaveAs(Form("%s/cgr1.pdf", ftxt[s1]));


	TFile * fwrite = new TFile(Form("%s/outGraph.root", ftxt[s1]), "recreate");
	gr1LmLm		->Write("gr1LmLm");
	gr1LmLmBar	->Write("gr1LmLmBar");
	gr1LmBarLmBar	->Write("gr1LmBarLmBar");
	gr1MLmLm	->Write("gr1MLmLm");
	gr1MLmLmBar	->Write("gr1MLmLmBar");
	gr1MLmBarLmBar	->Write("gr1MLmBarLmBar");

	gr2LmLm		->Write("gr2LmLm");
	gr2LmLmBar	->Write("gr2LmLmBar");
	gr2LmBarLmBar	->Write("gr2LmBarLmBar");
	gr2MLmLm	->Write("gr2MLmLm");
	gr2MLmLmBar	->Write("gr2MLmLmBar");
	gr2MLmBarLmBar	->Write("gr2MLmBarLmBar");
}
