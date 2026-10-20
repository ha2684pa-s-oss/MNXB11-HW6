#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H


namespace hw6 {
    class MovingObject : public TObject {
        public:
            MovingObject();
            MovingObject(Double_t vx, Double_t vy, Double_t vz);
            ~MovingObject() override;

            // getter functions
            Double_t Vx() const;
            Double_t Vy() const;
            Double_t Vz() const;

            Double_t Speed() const;
            Double_t HorizontalSpeed() const;

            void setVelocity(Double_t vx, Double_t vy, Double_t vz);

        private:
            Double_t fVx;
            Double_t fVy;
            Double_t fVz;

            ClassDef(MovingObject, 1);

    };



} // namespace hw6




#endif /* MOVINGOBJECT_H */
