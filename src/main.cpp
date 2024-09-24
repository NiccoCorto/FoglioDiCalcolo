#include <wx/wx.h>
#include "../include/GridInterface.h"
#include <memory>

class SpreadsheetApp : public wxApp {
public:
    virtual bool OnInit();
};

class SpreadsheetFrame : public wxFrame {
public:
    SpreadsheetFrame(const wxString &title);

private:
    std::unique_ptr<GridInterface> gridInterface;
};

wxIMPLEMENT_APP(SpreadsheetApp);

bool SpreadsheetApp::OnInit() {
    auto *frame = new SpreadsheetFrame("Spreadsheet");
    frame->Show(true);
    return true;
}

SpreadsheetFrame::SpreadsheetFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 400)) {
    auto panel = new wxPanel(this, wxID_ANY);  // Create the panel
    gridInterface = std::make_unique<GridInterface>(panel);  // Initialize the gridInterface with the panel
}