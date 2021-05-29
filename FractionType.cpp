#ifndef FRACTIONTYPE_CPP
#define FRACTIONTYPE_CPP

#include "FractionType.h"

FractionType::FractionType(int num, int den)
{
    numerator = num;
    denominator = den;
}

FractionType::FractionType()
{
    numerator = denominator = 0;
}

FractionType::~FractionType()
{
    numerator = denominator = 0;
}

void FractionType::setNumerator(int num)
{
    numerator = num;
}

void FractionType::setDenominator(int den)
{
    denominator = den;
}

int FractionType::getNumerator()
{
    return numerator;
}

int FractionType::getDenominator()
{
    return denominator;
}

bool FractionType::isZero()
{
    if(numerator == 0 && denominator != 0)
        return true;

    return false;
}

bool FractionType::isInfinite()
{
    if(denominator == 0 && numerator != 0)
        return true;

    return false;
}

bool FractionType::isWhole()
{
    if(numerator % denominator == 0)
        return true;

    return false;
}

bool FractionType::isIndeterminate()
{
    if( (numerator == denominator) && numerator == 0)
        return true;

    return false;
}

bool FractionType::isProper()
{
    if (numerator < denominator)
        return true;

    return false;
}

int FractionType::convertImproperToMixed()
{
    int whole = numerator/denominator;

    return whole;
}
#endif // FRACTIONTYPE_CPP
