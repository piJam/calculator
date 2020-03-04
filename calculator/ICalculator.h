#ifndef _ICALCULATOR_H_
#define _ICALCULATOR_H_

#include <QString>
class ICalulator
{
public:
    virtual bool expression(const QString& exp) = 0;
    virtual QString result() = 0;
};

#endif // ICALCULATOR_H
