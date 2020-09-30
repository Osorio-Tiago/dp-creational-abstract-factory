//
// Created by Maikol Guzman on 9/29/20.
//
#include <iostream>
#include <utility>

/**
 * Button Base Class
 */
class Button {
private:
    int id{};
    std::string name;
public:
    virtual std::string clickButton() = 0;
};

/**
 * MacOSButton drive class of Button
 */
class MacOSButton : public Button {
    std::string clickButton() override {
        return "Click Mac OS Button";
    }
};

/**
 * WindowsButton drive class of Button
 */
class WindowsButton : public Button {
    std::string clickButton() override {
        return "Click Windows Button";
    }
};

/**
 * Label Base Class
 */
class Label {
private:
    int id{};
    std::string text;
public:
    virtual std::string showLabel() = 0;
};

/**
 * MacOSLabel drive class of Label
 */
class MacOSLabel : public Label {
    std::string showLabel() override {
        return "Show Mac OS Label";
    }
};

/**
 * WindowsLabel drive class of Label
 */
class WindowsLabel : public Label {
    std::string showLabel() override {
        return "Show Windows Label";
    }
};

/**
 * Factory Abstract Class
 */
class GUIFactory {
public:
    virtual Button* makeButton() = 0;
    virtual Label* makeLabel() = 0;
};

/**
 * MacOSFactory
 */
class MacOSFactory : public GUIFactory {
public:
    Button* makeButton() override {
        return new MacOSButton;
    }

    Label* makeLabel() override {
        return new MacOSLabel;
    }
};

/**
 * WindowsFactory
 */
class WindowsFactory : public GUIFactory {
public:
    Button* makeButton() override {
        return new WindowsButton;
    }

    Label* makeLabel() override {
        return new WindowsLabel;
    }
};

/**
 * Main Class
 * @return
 */
int main() {
    std::cout << "Hello, Universidad Nacional!" << std::endl;

    GUIFactory* macOsFactory = new MacOSFactory;
    GUIFactory* windowsFactory = new WindowsFactory;

    Button* buttons[2];

    buttons[0] = macOsFactory->makeButton();
    buttons[1] = windowsFactory->makeButton();

    Label* labels[2];

    labels[0] = macOsFactory->makeLabel();
    labels[1] = windowsFactory->makeLabel();

    std::cout << "Buttons ---->" << std::endl;
    for (auto & button : buttons) {
        std::cout << button->clickButton() << std::endl;
    }

    std::cout << "Labels ---->" << std::endl;
    for (auto & label : labels) {
        std::cout << label->showLabel() << std::endl;
    }

    return 0;
}

