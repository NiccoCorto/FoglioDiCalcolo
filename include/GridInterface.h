
#ifndef PROJECTS_GRIDINTERFACE_H
#define PROJECTS_GRIDINTERFACE_H
#ifndef GRIDINTERFACE_H
#define GRIDINTERFACE_H

#include <wx/wx.h>
#include <vector>
#include "Cell.h"
#include "Function.h"
#include <memory>
#include <deque>

class GridInterface {
public:
    GridInterface(wxPanel *panel);

    void OnCellValueChanged(wxCommandEvent &event);
    void OnAddCell(wxCommandEvent &event);
    void OnRemoveCell(wxCommandEvent &event);

private:
    wxTextCtrl *sumText;
    wxTextCtrl *meanText;
    wxTextCtrl *minText;
    wxTextCtrl *maxText;

    std::deque<std::shared_ptr<Cell>> cells;
    std::deque<wxTextCtrl *> cellInputs;

    std::unique_ptr<Function> sumFunction;
    std::unique_ptr<Function> meanFunction;
    std::unique_ptr<Function> minFunction;
    std::unique_ptr<Function> maxFunction;

    wxGridSizer *gridSizer;
    wxPanel *panel;

    void InitializeGrid(wxPanel *panel);

    void UpdateFunctionResults();
};

#endif // GRIDINTERFACE_H
#endif //PROJECTS_GRIDINTERFACE_H
