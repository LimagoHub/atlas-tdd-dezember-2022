#include "TranslatorClientTest.h"
#include "stdexcept"
TEST_F(TranslatorClientTest, diy_mock)
{
	// Recordmode
	EXPECT_CALL(*translatorMock, translate("Hallo")).Times(1).WillRepeatedly(Throw(std::out_of_range{"upps"}));

	// Replaymode
	
	object_under_test.go();


}