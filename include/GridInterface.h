
#ifndef PROJECTS_GRIDINTERFACE_H
#define PROJECTS_GRIDINTERFACE_H
#ifndef GRIDINTERFACE_H
#define GRIDINTERFACE_H

#include <wx/wx.h>
#include <vector>
#include "Cell.h"
#include "Function.h"
#include <memory>

class GridInterface {
public:
    GridInterface(wxPanel *panel);

    void OnCellValueChanged(wxCommandEvent &event);

private:
    wxTextCtrl *cellInputs[4][4];
    wxTextCtrl *sumText;
    wxTextCtrl *meanText;
    wxTextCtrl *minText;
    wxTextCtrl *maxText;

    std::shared_ptr<Cell> cells[4][4];
    std::unique_ptr<Function> sumFunction;
    std::unique_ptr<Function> meanFunction;
    std::unique_ptr<Function> minFunction;
    std::unique_ptr<Function> maxFunction;

    void InitializeGrid(wxPanel *panel);

    void UpdateFunctionResults();
};

#endif // GRIDINTERFACE_H
#endif //PROJECTS_GRIDINTERFACE_H
