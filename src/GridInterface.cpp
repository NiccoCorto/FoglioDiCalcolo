#include "../include/GridInterface.h"

GridInterface::GridInterface(wxPanel *panel) {
    InitializeGrid(panel);
}

void GridInterface::InitializeGrid(wxPanel *panel) {
    // Create a wxGridSizer with 5 rows and 4 columns
    wxGridSizer *gridSizer = new wxGridSizer(5, 4, 10, 10);

    // Create cells and link them to wxTextCtrl
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cells[i][j] = std::make_shared<Cell>(); //shared by function and gridInterface
            cellInputs[i][j] = new wxTextCtrl(panel, wxID_ANY);
            gridSizer->Add(cellInputs[i][j], 1, wxEXPAND | wxALL);  // Add each control to the grid sizer
            cellInputs[i][j]->Bind(wxEVT_TEXT, &GridInterface::OnCellValueChanged, this);  // Bind event
        }
    }

    // Create function objects for all cells
    std::vector<std::shared_ptr<Cell>> allCells;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            allCells.push_back(cells[i][j]);
        }
    }

    // Initialize function objects with all cells
    sumFunction = std::make_unique<Function>(Function::SUM, allCells);
    meanFunction = std::make_unique<Function>(Function::MEAN, allCells);
    minFunction = std::make_unique<Function>(Function::MIN, allCells);
    maxFunction = std::make_unique<Function>(Function::MAX, allCells);

    // Create readonly text controls to display the results
    sumText = new wxTextCtrl(panel, wxID_ANY, std::to_string(sumFunction->getValue()), wxDefaultPosition, wxDefaultSize,
                             wxTE_READONLY);
    meanText = new wxTextCtrl(panel, wxID_ANY, std::to_string(meanFunction->getValue()), wxDefaultPosition,
                              wxDefaultSize, wxTE_READONLY);
    minText = new wxTextCtrl(panel, wxID_ANY, std::to_string(minFunction->getValue()), wxDefaultPosition, wxDefaultSize,
                             wxTE_READONLY);
    maxText = new wxTextCtrl(panel, wxID_ANY, std::to_string(maxFunction->getValue()), wxDefaultPosition, wxDefaultSize,
                             wxTE_READONLY);

    // Ensure these are added AFTER all cell inputs
    gridSizer->Add(sumText, 1, wxEXPAND | wxALL);
    gridSizer->Add(meanText, 1, wxEXPAND | wxALL);
    gridSizer->Add(minText, 1, wxEXPAND | wxALL);
    gridSizer->Add(maxText, 1, wxEXPAND | wxALL);

    // Set the sizer for the panel
    panel->SetSizer(gridSizer);
}

void GridInterface::OnCellValueChanged(wxCommandEvent &event) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            wxString valueStr = cellInputs[i][j]->GetValue();
            long value;

            // Check if the valueStr can be converted to a long integer
            if (valueStr.ToLong(&value)) {
                // Successfully converted to long, set cell value
                if (cells[i][j]) {
                    cells[i][j]->setValue(static_cast<int>(value));
                }
            } else {
                // Conversion failed, set default value
                if (cells[i][j]) {
                    cells[i][j]->setValue(0);
                }
            }
        }
    }

    // Update function results after handling all cells
    UpdateFunctionResults();
}

void GridInterface::UpdateFunctionResults() {
    sumText->SetValue(std::to_string(sumFunction->getValue()));
    meanText->SetValue(std::to_string(meanFunction->getValue()));
    minText->SetValue(std::to_string(minFunction->getValue()));
    maxText->SetValue(std::to_string(maxFunction->getValue()));
}