#pragma once

#include "nova/defines.h"

extern "C" {
	// forward declaration (cmath)
#if NOVA_MSVC
	double sqrt(double);
	double sin(double);
	double cos(double);
	double tan(double);
	double asin(double);
	double atan2(double, double);
#elif NOVA_GCC
	// TODO[Waleed]: investigate about throw()
	double sqrt(double) throw();
	double sin(double) throw();
	double cos(double) throw();
	double tan(double) throw();
	double asin(double) throw();
	double atan2(double, double) throw();
#else
	#error "Unhandled operating system"
#endif
}

namespace nova
{
	static constexpr double PI        = 3.14159265358979323846;
	static constexpr double PI_DIV_2  = PI * 0.5;
	static constexpr double TAU       = 2.0 * PI;
	static constexpr double TO_DEGREE = 360.0 / TAU;
	static constexpr double TO_RADIAN = TAU / 360.0;

    inline static float
    sqrt(float f)
    {
        return (float)::sqrt(f);
    }

    inline static double
    sqrt(double f)
    {
        return ::sqrt(f);
    }

    inline static float
    sin(float f)
    {
        return (float)::sin(f);
    }

    inline static double
    sin(double f)
    {
        return ::sin(f);
    }

    inline static float
    cos(float f)
    {
        return (float)::cos(f);
    }

    inline static double
    cos(double f)
    {
        return ::cos(f);
    }

    inline static float
    tan(float f)
    {
        return (float)::tan(f);
    }

    inline static double
    tan(double f)
    {
        return ::tan(f);
    }

    inline static float
    asin(float f)
    {
        return (float)::asin(f);
    }

    inline static double
    asin(double f)
    {
        return ::asin(f);
    }

    inline static float
    atan2(float y, float x)
    {
        return (float)::atan2(y, x);
    }

    inline static double
    atan2(double y, double x)
    {
        return ::atan2(y, x);
    }

    inline static float
    abs(float f)
    {
        return f < 0 ? f * -1 : f;
    }

	// TODO: add unittests
    inline static double
    abs(double f)
    {
        return f < 0 ? f * -1 : f;
    }
}
