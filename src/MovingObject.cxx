#include "MovingObject.h"

namespace hw6 {
    ClassImp(MovingObject);

    // default initializes all components to zero
    MovingObject::MovingObject() : fVx(0.0), fVy(0.0), fVz(0.0) {}

    // Other constructor initialize components from arguments
    MovingObject::(Double_t vx, Double_t vy, Double_t vz)
    : fVx(vx), fVy(vy), fVz(vz) {}


    // getters
    MovingObject::Vx() {
        return fVx;
    }
    
    MovingObject::Vy() {
        return fVy;
    }

    MovingObject::Vz() {
        return fVz;
    }

    // setter

   void MovingObject::setVelocity(Double_t vx, Double_t vy, Double_t vz) {
    fVx = vx;
    fVy = vy;
    fVz = vz;
   }


   
} // namespace hw6