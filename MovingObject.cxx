#include "MovingObject.h"
#include <cmath>

namespace hw6 {
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
    Double_t MovingObject::Vx() {
        return fVx;
    }
    
    Double_t MovingObject::Vy() {
        return fVy;
    }

    Double_t MovingObject::Vz() {
        return fVz;
    }

    // setter

   void MovingObject::setVelocity(Double_t vx, Double_t vy, Double_t vz) {
    fVx = vx;
    fVy = vy;
    fVz = vz;
   }

   Double_t MovingObject::Speed() const {
    return 0;
   }

   Double_t MovingObject::HorizontalSpeed() const {
    return 0;
   }


} // namespace hw6