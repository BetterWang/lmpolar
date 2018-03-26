
char const * fname[] = {
	"test/",		// 0 test
	"../CumuV0/HIMinimumBias5/crab_HIMB5_LmPolar_ppRecoGMO_v3/180325_212311/0000/",		// 1 HIMB5 Lm Sig
	"../CumuV0/HIMinimumBias6/crab_HIMB6_LmPolar_ppRecoGMO_v3/180325_212327/0000/",		// 2 HIMB6 Lm Sig
	"../CumuV0/HIMinimumBias7/crab_HIMB7_LmPolar_ppRecoGMO_v3/180325_212346/0000/",		// 3 HIMB7 Lm Sig
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
TChain * chCaloV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/LmTree/trV", fname[s1]));
        chCaloV->Add(Form("%s/*.root/CaloTree/trV", fname[s1]));
	chV->AddFriend(chCaloV);
}
