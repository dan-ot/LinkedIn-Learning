#include "OtherFeatures.h"

constexpr double fracOf::dbl() const
{
    return static_cast<double>(n) / static_cast<double>(d);
}

constexpr auto fracOf::operator==(const fracOf& rhs) const
{
    return dbl() == rhs.dbl();
}

constexpr auto fracOf::operator<=>(const fracOf& rhs) const
{
    return dbl() <=> rhs.dbl();
}
