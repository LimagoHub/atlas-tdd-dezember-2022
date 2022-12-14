#include "TranslatorClientTest.h"
#include "stdexcept"
TEST_F(TranslatorClientTest, diy_mock)
{
    // Hier (Unique pointer muss im Test erzeugt werden!!!)
    std::unique_ptr<TranslatorMock> translatorMock = std::make_unique<TranslatorMock>();
	// Recordmode
	EXPECT_CALL(*translatorMock, translate("Hallo")).Times(1).WillRepeatedly(Return("")); // this must be called before passing
    // objects into the code to be tested.

    // und hier
    TranslatorClient object_under_test(std::move(translatorMock));
	// Replaymode
	
	object_under_test.go();


}