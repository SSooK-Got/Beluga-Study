#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	FVector vec = FVector(1, 2, 3);
	FVector vec2 = FVector(1,1,1);
	
	// Dot Product
	{
		//Expected vec.Dot(vec2)
		// 1*1 + 1*2 + 1*3 = 6
		TestEqual(TEXT("Dot Product"), FVector::DotProduct(vec, vec2), 6.0);
	}

	// Cross Product
	{
		// (1*1 , 1*2 + 1*3) = (1, 2, 3) = vec
		TestEqual(TEXT("Cross Product"), FVector::CrossProduct(vec, vec2), vec);
	}
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaRotatorTest, "Beluga.Rotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaRotatorTest::RunTest(const FString& Parameters)
{
	FRotator rot;
	FRotator rot2 = FRotator(720, -360, 360);

	// Zero Rotate
	{
		TestEqual(TEXT("Zero Rotate"), rot.Equals(FRotator::ZeroRotator), true);
	}

	// Final Orientation
	{
		TestEqual(TEXT("Final Orientation"), rot.Equals( rot2), true);
	}




	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaQuatTest, "Beluga.Quat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaQuatTest::RunTest(const FString& Parameters)
{
	FQuat quat = FQuat(45,45,45, 0);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters)
{

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters)
{
	
	return true;
}
