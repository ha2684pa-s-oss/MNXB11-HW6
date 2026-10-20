#include "MovingObject.h"

#include <TFile.h>
#include <TTree.h>
#include <TClass.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <iostream>
#include <TH2D.h>

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

    // Create a histogram for speed distribution
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

    // horizontal speed distribution
    
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

    // Velocity components
    // Velocity components: vy versus vx
    TCanvas *c3 = new TCanvas(
        "c3", "Velocity Components", 800, 600
    );

    TH2D *h_velocity = new TH2D(
        "h_velocity",
        "Velocity Components;v_{x} (m/s);v_{y} (m/s)",
        100, -1.5, 1.5,
        100, -1.5, 1.5
    );

    for (Int_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        if (moving_object) {
            h_velocity->Fill(
                moving_object->Vx(),
                moving_object->Vy()
            );
        }
    }

    c3->cd();
    c3->SetRightMargin(0.15);
    h_velocity->Draw("HIST");

    c3->Modified();
    c3->Update();
    c3->SaveAs("velocity_components.png");


    TCanvas *c4 = new TCanvas("c4", "Horizontal Speed vs Vz", 700, 500);

    // Check the branch and leaf names with tree->Print()
    tree->Print();

    // Draw vz on the x-axis and horizontal speed on the y-axis
    // Select only measurements with total speed > 0.50 m/s
    tree->Draw(
        "object.HorizontalSpeed():object.Vz()",
        "object.Speed()>0.50",
        "SCAT"
    );

    c4->SetTitle("Horizontal Speed vs vz");
    c4->Modified();
    c4->Update();



    c1->SaveAs("speed_histogram.png");
    c2->SaveAs("horizontal_speed_histogram.png");
    c3->SaveAs("velocity_components.png");
    c4->SaveAs("horizontal_speed_vs_vz.png");

    // clean up
    c1->Close();
    c2->Close();
    c3->Close();
    c4->Close();
    file->Close();
    delete file;
}