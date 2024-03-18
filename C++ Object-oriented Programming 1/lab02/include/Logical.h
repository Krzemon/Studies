#ifndef LOGICAL_H
#define LOGICAL_H

class OneArg {
public:
    virtual bool result(bool x) const = 0;
};

class TwoArg {
public:
    virtual bool result(bool x, bool y) const = 0;
};

class NOT : public OneArg {
public:
    bool result(bool x) const override;
};

class AND : public TwoArg {
public:
    bool result(bool x, bool y) const override;
};

class OR : public TwoArg {
public:
    bool result(bool x, bool y) const override;
};

namespace Logical {
    bool eval(const OneArg& op, bool x);
    bool eval(const TwoArg& op, bool x, bool y);
}

#endif // LOGICAL_H
