#include "MovingObject.h"
#include <cmath>


    ClassImp(MovingObject);

    // default initializes all components to zero
    MovingObject::MovingObject() : fVx(0.0), fVy(0.0), fVz(0.0) {

    }

    // Other constructor initialize components from arguments
    MovingObject::MovingObject(Double_t vx, Double_t vy, Double_t vz)
    : fVx(vx), fVy(vy), fVz(vz) {

    }
    
    MovingObject::~MovingObject() {

    }

    // getters
    Double_t MovingObject::Vx() const {
        return fVx;
    }
    
    Double_t MovingObject::Vy() const {
        return fVy;
    }

    Double_t MovingObject::Vz() const {
        return fVz;
    }

    // setter

   void MovingObject::SetVelocity(Double_t vx, Double_t vy, Double_t vz) {
    fVx = vx;
    fVy = vy;
    fVz = vz;
   }

   Double_t MovingObject::Speed() const {
    return std::sqrt(fVx*fVx + fVy*fVy + fVz*fVz);
   }

   Double_t MovingObject::HorizontalSpeed() const {
    return std::sqrt(fVx*fVx + fVy*fVy);
   }
