#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
	{
		FString strChar("char");
		FString strWChar(L"wchar");
		FString strTChar(TEXT("wchar"));

		strChar = "char";
		strWChar = "wchar";
		strTChar = TEXT("wchar");
	}

	// Printf
	{
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}
		
		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));
			
			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	FString strApple(TEXT("Apple"));
	FString strBanana(TEXT("Banana"));
	
	// Operators
	{
		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	FName nameChar(TEXT("name"));
	FName nameChar2(TEXT("NAME"));
	FName newName(TEXT("NewName"));

	// Operator
	{
		// ==
		TestEqual(TEXT("Operator =="), nameChar == nameChar2, true);
		TestEqual(TEXT("Operator !="), nameChar != newName, true);
	}

	// Index
	{
		TestEqual(TEXT("ComparisonIndex"), nameChar.GetComparisonNameEntry() == nameChar2.GetComparisonNameEntry(), true);
		TestEqual(TEXT("DisplayIndex"), nameChar.GetDisplayNameEntry() != nameChar2.GetDisplayNameEntry(), true);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTextTest, "Beluga.Text", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTextTest::RunTest(const FString& Parameters)
{
	FText helloEUR = FText::FromString("Hello!");
	FText helloKOR = FText::FromString("안녕하세요");
	FText nameEUR = FText::FromString("Name");

	// CultureName
	{
		TestEqual(TEXT("Diff Lang, Same Meaning"), FInternationalization::Get().GetPrioritizedCultureNames(helloEUR.ToString())
			== FInternationalization::Get().GetPrioritizedCultureNames(helloKOR.ToString()), true);
		TestEqual(TEXT("Same Lang, Diff Meaning"), FInternationalization::Get().GetPrioritizedCultureNames(helloEUR.ToString())
			== FInternationalization::Get().GetPrioritizedCultureNames(nameEUR.ToString()), true);

	}



	return true;
}
