#include <gtest/gtest.h>

#include "model/MathCalculator.h"

#define ACCURACY 1e-07

TEST(calculation_src_test, test_1) {
  my::MathCalculator m;
  double result = -314.57610957027;
  double answer = m.Calculate("-sqrt(5647*(9-(-78)))+46^3/250-log(1000)");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_2) {
  my::MathCalculator m;
  double result = 10000011.2028204;
  double answer = m.Calculate("10000000+98/100000-cos(90)*(sqrt(625))");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_3) {
  my::MathCalculator m;
  double answer = m.Calculate("log(-178)+634/2/0.5");
  EXPECT_TRUE(std::isnan(answer));
}

TEST(calculation_src_test, test_4) {
  my::MathCalculator m;
  double result = 2538.250420002308894;
  double answer = m.Calculate("log(178)+634/2/0.5^3");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_5) {
  my::MathCalculator m;
  double result = -1.582661488475988;
  double answer = m.Calculate("atan(0)^3-155.87633/98.49");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_6) {
  my::MathCalculator m;
  double result = 4247.389013;
  double answer = m.Calculate("3958-sqrt(567^3-567)*ln(1)+289.389013");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_7) {
  my::MathCalculator m;
  double result = 10000007.962414428;
  double answer = m.Calculate("100010001/3794*0.00034+9999999");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_8) {
  my::MathCalculator m;
  double answer = m.Calculate("1.0/0.0+cos(180)-1.0/0.0");
  EXPECT_TRUE(std::isnan(answer));
}

TEST(calculation_src_test, test_9) {
  my::MathCalculator m;
  double answer = m.Calculate("cos(180)-1.0/0.0");
  EXPECT_TRUE(std::isinf(answer));
}

TEST(calculation_src_test, test_10) {
  my::MathCalculator m;
  double result = -12.046197928264263;
  double answer = m.Calculate("150-cos(180)*150/5+(-180)");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_11) {
  my::MathCalculator m;
  double answer = m.Calculate("acos(100)");
  EXPECT_TRUE(std::isnan(answer));
}

TEST(calculation_src_test, test_12) {
  my::MathCalculator m;
  double result = -0.55193482688;
  double answer = m.Calculate("cos(76-60)*(35mod7)-542/982");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_13) {
  my::MathCalculator m;
  double result = 3.85919608528;
  double answer = m.Calculate("log(1000*ln(200*ln(1000)))");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_14) {
  my::MathCalculator m;
  double result = -12.046197928264263;
  double answer = m.Calculate("150-cos(x)*150/5+(-x)", 180);
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_15) {
  my::MathCalculator m;
  double result = 439615.5;
  double answer = m.Calculate("879231*(1/2)+atan(0)/(sqrt(982-237*0.34))");
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_16) {
  my::MathCalculator m;
  double result = 5000.56237908;
  double answer = m.Calculate("cos(x)-x*(-5)", 1E3);
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_17) {
  my::MathCalculator m;
  double result = 1055077.2;
  double answer = m.Calculate("879231*(x)+atan(0)/(sqrt(982-x*0.34))", 1.2);
  EXPECT_NEAR(result, answer, ACCURACY);
}

TEST(calculation_src_test, test_18) {
  my::MathCalculator m;
  double answer = m.Calculate("ln(100000)-78361+asin(2)-(645mod82)^7");
  EXPECT_TRUE(std::isnan(answer));
}

TEST(calculation_src_test, test_19) {
  my::MathCalculator m;
  double answer = m.Calculate("879231*(x)+atan(0)/(sqrt(982-x*0.34))");
  EXPECT_NEAR(0.0, answer, ACCURACY);
}

TEST(calculation_src_test, test_20) {
  my::MathCalculator m;
  double answer = m.Calculate("8-cos(x^9)*7", 8);
  EXPECT_NEAR(3.4785444, answer, ACCURACY);
}

TEST(calculation_src_test, test_21) {
  my::MathCalculator m;
  double answer = m.Calculate("187/5+9*(ln(10)^3.5)");
  EXPECT_NEAR(204.1237307, answer, ACCURACY);
}

TEST(calculation_src_test, test_22) {
  my::MathCalculator m;
  double answer = m.Calculate("46/3+5^2*(89+4)-sin(2)");
  EXPECT_NEAR(2339.424035906, answer, ACCURACY);
}

TEST(calculation_src_test, test_23) {
  my::MathCalculator m;
  double answer = m.Calculate("46/3+5^2*(89+4)*sin(2)");
  EXPECT_NEAR(2129.4498507030432, answer, ACCURACY);
}

TEST(calculation_src_test, test_24) {
  my::MathCalculator m;
  double answer = m.Calculate("987.65^(1/2)+7*tan(3/0.5)");
  EXPECT_NEAR(29.3898559, answer, ACCURACY);
}

TEST(calculation_src_test, test_25) {
  my::MathCalculator m;
  double answer = m.Calculate("2+tan(45)/(7-90*(-4))");
  EXPECT_NEAR(2.0044135, answer, ACCURACY);
}

TEST(calculation_src_test, test_26) {
  my::MathCalculator m;
  double answer = m.Calculate("cos(23.4+tan(23*(0-23)))");
  EXPECT_NEAR(-0.3047384, answer, ACCURACY);
}

TEST(calculation_src_test, test_27) {
  my::MathCalculator m;
  double answer = m.Calculate("96mod2-98*(1/2)");
  EXPECT_NEAR(-49, answer, ACCURACY);
}

TEST(calculation_src_test, test_28) {
  my::MathCalculator m;
  double answer = m.Calculate("96mod(x)-98*x", -1e+2);
  EXPECT_NEAR(9896, answer, ACCURACY);
}

TEST(calculation_src_test, test_29) {
  my::MathCalculator m;
  double answer = m.Calculate("87.9/456+atan(1)-94");
  EXPECT_NEAR(-93.0218387, answer, ACCURACY);
}

TEST(calculation_src_test, test_30) {
  my::MathCalculator m;
  double answer = m.Calculate("sqrt(x)-cos(90+x)/log(10)", 64);
  EXPECT_NEAR(8.99808109, answer, ACCURACY);
}

TEST(calculation_src_test, test_31) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("sqrt(x)-cos((90+x)/log(10)", 64);
               , std::invalid_argument);
}

TEST(calculation_src_test, test_32) {
  my::MathCalculator m;
  double answer = m.Calculate("2^3^2");
  EXPECT_NEAR(512, answer, ACCURACY);
}

TEST(calculation_src_test, test_33) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("+2+2");, std::invalid_argument);
}

TEST(calculation_src_test, test_34) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("2+");, std::invalid_argument);
}

TEST(calculation_src_test, test_35) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("(");, std::invalid_argument);
}

TEST(calculation_src_test, test_36) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate(".");, std::invalid_argument);
}

TEST(calculation_src_test, test_37) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("si");, std::invalid_argument);
}

TEST(calculation_src_test, test_38) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("x90");, std::invalid_argument);
}

TEST(calculation_src_test, test_39) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("-10(");, std::invalid_argument);
}

TEST(calculation_src_test, test_40) {
  my::MathCalculator m;
  EXPECT_THROW(m.Calculate("2++2");, std::invalid_argument);
}

// int main(int argc, char* argv[]) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }