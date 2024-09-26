#include "../../src/builder/scanner.h"

TEST(ScannerTest, testScannerNextShouldSkipOthercharacters)
{
    Scanner scanner("@#$.  *\nCircle");

    ASSERT_EQ("Circle", scanner.next());
}

TEST(ScannerTest, testScannerNextDoubleShouldSkipOthercharacters)
{
    Scanner scanner("@#$.  *\n13.69");

    ASSERT_NEAR(13.69, scanner.nextDouble(), 0.001);
}

TEST(ScannerTest, testScannerNextShouldThrowException)
{
    Scanner scanner("Cirle");
    ASSERT_ANY_THROW(scanner.next());
}

TEST(ScannerTest, testScannerNextShouldThrowException2)
{
    Scanner scanner("CompoundSape");
    ASSERT_ANY_THROW(scanner.next());
}

TEST(ScannerTest, testScannerNextShouldThrowException3)
{
    Scanner scanner("Vetor");
    ASSERT_ANY_THROW(scanner.next());
}

TEST(ScannerTest, testScannerNextDoubleShouldThrowException)
{
    Scanner scanner(")");
    ASSERT_ANY_THROW(scanner.nextDouble());
}

TEST(ScannerTest, testScannerNextDoubleShouldThrowException2)
{
    Scanner scanner("(");
    ASSERT_ANY_THROW(scanner.nextDouble());
}

TEST(ScannerTest, testScannerShouldBeCorrect)
{
    Scanner scanner("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))");

    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.28, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.26, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.83, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.73, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}

TEST(ScannerTest, testScannerNextShouldThrowExceptionWhenIsDone)
{
    Scanner scanner("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))");

    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.28, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.26, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.83, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.73, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
    ASSERT_ANY_THROW(scanner.next());
}

TEST(ScannerTest, testScannerNextDoubleShouldThrowExceptionWhenIsDone)
{
    Scanner scanner("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))");

    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.28, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.26, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.83, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.73, scanner.nextDouble(), 0.001);
    ASSERT_ANY_THROW(scanner.nextDouble());
}

TEST(ScannerTest, testScannerShouldBeCorrect2)
{
    Scanner scanner("CompoundShape (Circle (Vector ((-4.28, 0.26), (-4.83, 0.73))), Triangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50))), CompoundShape (Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))))");

    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.28, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.26, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-4.83, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.73, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Triangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-2.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(1.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(1.50, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.47, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-2.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(1.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(-1.47, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(4.50, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Rectangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(0.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(3.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(3.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(4.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_NEAR(3.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(",", scanner.next());
    ASSERT_NEAR(0.00, scanner.nextDouble(), 0.001);
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}