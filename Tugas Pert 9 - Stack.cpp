#include <iostream>
#include <string>
#include <stack>

using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText;

public:
    TextEditor() : currentText("") {}

    void ketik(const string& text) {
        undoStack.push(currentText);
        currentText += text;
        redoStack = stack<string>(); // reset redo stack
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(currentText);
            currentText = undoStack.top();
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(currentText);
            currentText = redoStack.top();
            redoStack.pop();
        }
    }

    bool isUndoEmpty() {
        return undoStack.empty();
    }

    bool isRedoEmpty() {
        return redoStack.empty();
    }

    void printText() {
        cout << "Current text: " << currentText << endl;
    }
};

int main() {
    TextEditor editor;

    while (true) {
        cout << "Enter operation (ketik, undo, redo, IsEmptyUndo, IsEmptyRedo): ";
        string operation;
        cin >> operation;

        if (operation == "ketik") {
            cout << "Enter text to type: ";
            string text;
            cin >> text;
            editor.ketik(text);
            editor.printText();
        } else if (operation == "undo") {
            editor.undo();
            editor.printText();
        } else if (operation == "redo") {
            editor.redo();
            editor.printText();
        } else if (operation == "IsEmptyUndo") {
            cout << "Undo stack is empty: " << (editor.isUndoEmpty()? "true" : "false") << endl;
        } else if (operation == "IsEmptyRedo") {
            cout << "Redo stack is empty: " << (editor.isRedoEmpty()? "true" : "false") << endl;
        } else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}