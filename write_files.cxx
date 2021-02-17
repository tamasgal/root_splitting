#include <iostream>
#include "TClass.h"
#include "TFile.h"
#include "TObject.h"
#include "TStreamerInfo.h"
#include "TTree.h"

#include "TWhatever.h"

void write_file(const char *filename, int split_level, bool memberwise) {
    bool _memberwise;

    _memberwise = TVirtualStreamerInfo::SetStreamMemberWise(memberwise);
    std::cout << "Split level = " << split_level << ", ";
    std::cout << "memberwise streaming = " << TVirtualStreamerInfo::GetStreamMemberWise();
    std::cout << std::endl;

    static TWhatever *whatever;

    TFile hfile(filename,"RECREATE");

    TTree *tree = new TTree("T","A tree holding TWhatevers");
    tree->Branch("whatever", &whatever, 32000, split_level);

    short sign;

    for ( Int_t i=0; i<5001; i++) {
        if(i % 2 == 0) {
            sign = -1;
        } else {
            sign = 1;
        }
        whatever->SetA(i * 10.1);
        whatever->SetB(sign * i);

        tree->Fill();
    }

    tree->Print();

    hfile.Write();
    hfile.Close();

    TVirtualStreamerInfo::SetStreamMemberWise(_memberwise);  // reset
    std::cout << std::endl;
}


int main(int argc, char **argv)
{

    TClass::GetClass("TWhatever")->SetCanSplit(true);

    write_file("nosplit.objectwise.root", 0, false);
    write_file("nosplit.memberwise.root", 0, true);

    write_file("split_1.objectwise.root", 1, false);
    write_file("split_1.memberwise.root", 1, true);

    return 0;
}

