
char const * fname[] = {
	"test/",		// 0 test
	"../CumuV0/HIMinimumBias5/crab_HIMB5_LmPolar_ppRecoGMO_v6/180806_155134/0000/",		// 1 HIMB5 Lm Sig
	"",		// 2 HIMB6 Lm Sig
	"",		// 3 HIMB7 Lm Sig
};


char const * ftxt[] = {
	"txt/test/",			// 0 test
	"txt/HIMB5_Lm/",		// 1
	"txt/HIMB6_Lm/",		// 2
	"txt/HIMB7_Lm/",		// 3
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/lmpolar/trV", fname[s1]));
}
