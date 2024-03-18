#include "Logical.h"

bool NOT::result(bool x) const {
    return !x;
}

bool AND::result(bool x, bool y) const {
    return x && y;
}

bool OR::result(bool x, bool y) const {
    return x || y;
}

namespace Logical {
    bool eval(const OneArg& op, bool x) {
        return op.result(x);
    }

    bool eval(const TwoArg& op, bool x, bool y) {
        return op.result(x, y);
    }
}
