#include <nova/math.h>

#include <doctest/doctest.h>

TEST_CASE("[nova]: consts")
{
	CHECK(doctest::Approx(nova::PI) == 3.14159265358979323846);
	CHECK(doctest::Approx(nova::PI_DIV_2) == (3.14159265358979323846 / 2.0));
	CHECK(doctest::Approx(nova::TAU) == (3.14159265358979323846 * 2.0));

	CHECK(doctest::Approx(nova::TO_DEGREE * nova::PI) == 180.0);
	CHECK(doctest::Approx(nova::TO_RADIAN * 360.0) == nova::TAU);
}

TEST_CASE("[nova]: math")
{
	SUBCASE("sqrt")
	{
		for (double i = 0.0; i < 100.0; i += 0.1)
		{
			CHECK(doctest::Approx(nova::sqrt(i*i)) == i);
			CHECK(doctest::Approx(nova::sqrt(float(i*i))) == float(i));
		}
	}

	SUBCASE("sin")
	{
		for (double theta = -2.0 * nova::TAU; theta < 2 * nova::TAU; theta += 0.1)
		{
			INFO("theta: ", theta);
			CHECK(doctest::Approx(nova::sin(theta)) == ::sin(theta));
			CHECK(doctest::Approx(nova::sin(float(theta))) == ::sinf(float(theta)));
		}
	}

	SUBCASE("cos")
	{
		for (double theta = -2.0 * nova::TAU; theta < 2 * nova::TAU; theta += 0.1)
		{
			INFO("theta: ", theta);
			CHECK(doctest::Approx(nova::cos(theta)) == ::cos(theta));
			CHECK(doctest::Approx(nova::cos(float(theta))) == ::cosf(float(theta)));
		}
	}

	SUBCASE("tan")
	{
		for (double theta = -2.0 * nova::TAU; theta < 2 * nova::TAU; theta += 0.1)
		{
			INFO("theta: ", theta);
			CHECK(doctest::Approx(nova::tan(theta)) == ::tan(theta));
			CHECK(doctest::Approx(nova::tan(float(theta))) == ::tanf(float(theta)));
		}
	}
}
