#include "../include/GridInterface.h"

GridInterface::GridInterface(wxPanel *panel) {
    // Convert std::deque to std::vector for Function
    std::vector<std::shared_ptr<Cell>> cellsVector(cells.begin(), cells.end());

    sumFunction = std::make_unique<Function>(Function::SUM, cellsVector);
    meanFunction = std::make_unique<Function>(Function::MEAN, cellsVector);
    minFunction = std::make_unique<Function>(Function::MIN, cellsVector);
    maxFunction = std::make_unique<Function>(Function::MAX, cellsVector);

    InitializeGrid(panel);
    for (const auto &cell: cells) {
        sumFunction->addCell(cell);
        meanFunction->addCell(cell);
        minFunction->addCell(cell);
        maxFunction->addCell(cell);
    }
}

void GridInterface::InitializeGrid(wxPanel *panel) {
    this->panel = panel;
    gridSizer = new wxGridSizer(0, 4, 10, 10);

    // Add initial 4x4 grid of cells
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            auto cell = std::make_shared<Cell>();
            cells.push_back(cell);

            auto input = new wxTextCtrl(panel, wxID_ANY, "0");
            cellInputs.push_back(input);

            input->Bind(wxEVT_TEXT, &GridInterface::OnCellValueChanged, this);
            gridSizer->Add(input, 1, wxEXPAND | wxALL);
        }
    }

    // Initialize functions with the cells after they are created
    std::vector<std::shared_ptr<Cell>> cellsVector(cells.begin(), cells.end());
    sumFunction = std::make_unique<Function>(Function::SUM, cellsVector);
    meanFunction = std::make_unique<Function>(Function::MEAN, cellsVector);
    minFunction = std::make_unique<Function>(Function::MIN, cellsVector);
    maxFunction = std::make_unique<Function>(Function::MAX, cellsVector);

    sumText = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    meanText = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    minText = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    maxText = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    gridSizer->Add(sumText, 1, wxEXPAND | wxALL);
    gridSizer->Add(meanText, 1, wxEXPAND | wxALL);
    gridSizer->Add(minText, 1, wxEXPAND | wxALL);
    gridSizer->Add(maxText, 1, wxEXPAND | wxALL);

    // Add + and - buttons for adding/removing cells
    auto addButton = new wxButton(panel, wxID_ANY, "+");
    auto removeButton = new wxButton(panel, wxID_ANY, "-");
    addButton->Bind(wxEVT_BUTTON, &GridInterface::OnAddCell, this);
    removeButton->Bind(wxEVT_BUTTON, &GridInterface::OnRemoveCell, this);
    gridSizer->Add(addButton, 1, wxEXPAND | wxALL);
    gridSizer->Add(removeButton, 1, wxEXPAND | wxALL);

    panel->SetSizer(gridSizer);
    panel->Layout();
}

void GridInterface::OnAddCell(wxCommandEvent &event) {
    // Create a new Cell and TextCtrl
    auto cell = std::make_shared<Cell>();
    auto input = new wxTextCtrl(panel, wxID_ANY, "0");

    // Bind events and add to containers
    input->Bind(wxEVT_TEXT, &GridInterface::OnCellValueChanged, this);
    cells.push_back(cell);
    cellInputs.push_back(input);

    // Add to Function observers
    sumFunction->addCell(cell);
    meanFunction->addCell(cell);
    minFunction->addCell(cell);
    maxFunction->addCell(cell);

    // Add to layout and refresh
    gridSizer->Add(input, 1, wxEXPAND | wxALL);
    panel->Layout();
}

void GridInterface::OnRemoveCell(wxCommandEvent &event) {
    if (cells.empty()) {
        wxLogMessage("Nessuna cella da rimuovere.");
        return;
    }

    // Check if it's the last cell and handle appropriately
    auto cell = cells.back();
    auto input = cellInputs.back();

    sumFunction->removeCell(cell);
    meanFunction->removeCell(cell);
    minFunction->removeCell(cell);
    maxFunction->removeCell(cell);

    gridSizer->Detach(input);
    input->Destroy();

    cells.pop_back();
    cellInputs.pop_back();

    if (cells.empty()) {
        sumText->SetValue("0");
        meanText->SetValue("0");
        minText->SetValue("0");
        maxText->SetValue("0");
    } else {
        UpdateFunctionResults();
    }

    panel->Layout();
}

void GridInterface::OnCellValueChanged(wxCommandEvent &event) {
    // Identify the source of the event
    auto *input = dynamic_cast<wxTextCtrl *>(event.GetEventObject());
    if (!input) return; // Safety check

    // Find the corresponding cell
    for (size_t i = 0; i < cellInputs.size(); ++i) {
        if (cellInputs[i] == input) {
            wxString valueStr = input->GetValue();
            long value;

            // Check if the valueStr can be converted to a long integer
            if (valueStr.ToLong(&value)) {
                // Successfully converted
                input->SetBackgroundColour(*wxWHITE);
                cells[i]->setValue(static_cast<int>(value));
            } else {
                // Conversion failed
                input->SetBackgroundColour(*wxRED);
                cells[i]->setValue(0);
            }

            // Update function results after handling this cell
            UpdateFunctionResults();
            return;
        }
    }
}

void GridInterface::UpdateFunctionResults() {
    // update in function results in grid
    sumText->SetValue(std::to_string(sumFunction->getValue()));
    meanText->SetValue(std::to_string(meanFunction->getValue()));
    minText->SetValue(std::to_string(minFunction->getValue()));
    maxText->SetValue(std::to_string(maxFunction->getValue()));
}