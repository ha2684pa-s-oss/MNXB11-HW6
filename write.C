#include "MovingObject.h"

#include <TFile.h>
#include <TTree.h>
#include <vector>
#include <TRandom3.h>
#include <iostream>
#include <TF1.h>


void write();


void write() {

    // initialize object
    MovingObject *moving_object = new MovingObject();
    
    Double_t vx, vy, vz;
    // random numbers generator with preset seed
    gRandom->SetSeed(42);
    
    // create root file
    TFile *file = new TFile("tree_file.root", "RECREATE");

    // create TTree
    TTree *tree = new TTree("velocities", "tree");

    // adding branches
    tree->Branch("object", &moving_object);

    // loop to create data

    const Int_t nEvents = 100;

    for (Int_t i{0}; i<nEvents; i++) {
        vx = gRandom->Gaus(0.0, 0.30);
        vy = gRandom->Gaus(0.0, 0.30);
        vz = gRandom->Gaus(0.0, 0.30);
        moving_object->SetVelocity(vx, vy, vz);
        tree->Fill();

    }

    // write to file and close
    file->Write();
    file->Close();

    // clean up
    delete moving_object;
    delete file;
}