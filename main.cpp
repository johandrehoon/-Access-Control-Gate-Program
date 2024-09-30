#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include "Gate.h"

class AccessControlWidget : public QWidget {
private:
    Gate gate;
    QLineEdit *passwordInput;

public:
    AccessControlWidget(QWidget *parent = nullptr)
        : QWidget(parent), gate("Gate 1", 1234) // Initialize Gate object with a description and password
    {
        // Set up the layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QGridLayout *keypadLayout = new QGridLayout();

        // Create widgets
        QLabel *descriptionLabel = new QLabel(gate.getDescription(), this);
        passwordInput = new QLineEdit(this);
        passwordInput->setReadOnly(true); // Make input field read-only

        // Create keypad buttons
        QPushButton *buttons[12]; // 10 digits + # + clear + enter buttons

        for (int i = 0; i < 10; ++i) {
            buttons[i] = new QPushButton(QString::number(i), this);
            int row = (i / 3);
            int col = i % 3;
            keypadLayout->addWidget(buttons[i], row, col);
            connect(buttons[i], &QPushButton::clicked, this, [this, i]() {
                passwordInput->insert(QString::number(i));
            });
        }

        // Add hash, clear, and enter buttons
        buttons[10] = new QPushButton("#", this);
        buttons[11] = new QPushButton("Clear", this);
        QPushButton *enterButton = new QPushButton("Enter", this);

        keypadLayout->addWidget(buttons[10], 3, 0);
        keypadLayout->addWidget(buttons[11], 3, 1);
        keypadLayout->addWidget(enterButton, 3, 2);

        // Connect buttons to their slots
        connect(buttons[10], &QPushButton::clicked, this, [this]() {
            passwordInput->insert(QString('#')); // Convert char to QString
        });
        connect(buttons[11], &QPushButton::clicked, this, [this]() {
            passwordInput->clear(); // Clear the input field
        });
        connect(enterButton, &QPushButton::clicked, this, &AccessControlWidget::checkPassword);

        // Add widgets to main layout
        mainLayout->addWidget(descriptionLabel);
        mainLayout->addWidget(passwordInput);
        mainLayout->addLayout(keypadLayout);
    }

private slots:
    void checkPassword() {
        QString input = passwordInput->text();
        if (input.endsWith('#')) {
            input.chop(1); // Remove the '#'
            bool ok;
            int password = input.toInt(&ok);
            if (ok) {
                if (gate.checkPassword(password)) {
                    QMessageBox::information(this, "Access Control", "Access Granted");
                } else {
                    QMessageBox::warning(this, "Access Control", "Access Denied");
                }
            } else {
                QMessageBox::warning(this, "Access Control", "Invalid Password Format");
            }
        } else {
            QMessageBox::warning(this, "Access Control", "Password must end with #");
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AccessControlWidget widget;
    widget.setWindowTitle("Access Control Gate");
    widget.show();

    return app.exec();
}
