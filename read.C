#include "MovingObject.h"

#include <TFile.h>
#include <TTree.h>
#include <TClass.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <iostream>

void read();

void read() {
    // Open file in READ mode
    TFile *file = TFile::Open("/home/hannap/mnxb11/MNXB11-HW6/tree_file.root", "READ");
    TCanvas *c1 = new TCanvas("c1", "Speed Distribution", 700, 500);

    // prep
    TTree *tree = nullptr;

    // get tree
    file->GetObject("tree", tree);

    // create object 
    MovingObject *moving_object = nullptr;
    
    tree->SetBranchAddress("object", &moving_object);

    // Create a histogram for speed
    TH1D *speed = new TH1D(
        "Measurements",
        "Speed distribution;Speed (m/s);Number of measurements",
        100, 0, 3
    );

    // get number of entires
    Int_t nEntries = tree->GetEntries();
    // read entries and fill the histogram
    for (Int_t i = 0; i<nEntries; ++i) {
        tree->GetEntry(i);
        if (moving_object) {
            speed->Fill(moving_object->Speed());
        }
    }
    speed->SetStats(1);
    speed->SetLineColor(kMagenta+2);
    speed->SetFillColor(kMagenta-9);
    c1->cd();
    speed->Draw("HIST");
    c1->Modified();
    c1->Update();
    c1->SaveAs("speed_histogram.png");
    
    TCanvas *c2 = new TCanvas("c2", "Horizontal Speed Distribution", 700, 500);
    TH1D *h_speed = new TH1D(
        "Measurements",
        "Horizontal Speed distribution;Speed (m/s);Number of measurements",
        100, 0, 3
    );


for (Int_t i = 0; i<nEntries; ++i) {
        tree->GetEntry(i);
        if (moving_object) {
            h_speed->Fill(moving_object->HorizontalSpeed());
        }
    }
    h_speed->SetStats(1);
    h_speed->SetLineColor(kBlue+2);
    h_speed->SetFillColor(kBlue-9);
    c2->cd();
    h_speed->Draw("HIST");
    c2->Modified();
    c2->Update();
    c2->SaveAs("horizontal_speed_histogram.png");
    // Clean up
    file->Close();
    delete file;
}