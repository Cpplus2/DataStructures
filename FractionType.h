#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H

class FractionType
{
    private:
        int numerator, denominator;

    public:
        FractionType();
        FractionType(int, int);
        ~FractionType();
        void setNumerator(int);
        void setDenominator(int);
        int getNumerator();
        int getDenominator();
        bool isZero();
        bool isInfinite();
        bool isProper();
        bool isIndeterminate();
        bool isWhole();
        int convertImproperToMixed();

};
#endif // FRACTIONTYPE_H
