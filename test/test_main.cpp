#include <wx/wx.h>
#include <gtest/gtest.h>

wxIMPLEMENT_APP_NO_MAIN(wxApp); // Necessary for tests

//runs all tests
int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}