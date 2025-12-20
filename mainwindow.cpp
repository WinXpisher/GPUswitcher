#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GPUswitcher");
    setWindowIcon(QIcon(":/icon.png"));
    setFixedSize(300, 300);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QGridLayout *joinedLayout = new QGridLayout();

    mainCombo = new QComboBox();
    mainCombo->addItems({"Hybrid mode", "Integrated only"});

    QPushButton *ApplyButton = new QPushButton();
    ApplyButton->setText("Apply");
    ApplyButton->setFixedSize(50, 30);

    joinedLayout->addWidget(mainCombo, 0, 0);
    joinedLayout->addWidget(ApplyButton, 0, 1);
    mainLayout->addLayout(joinedLayout);

    connect(ApplyButton,&QPushButton::clicked, this, &MainWindow::onApplyButtonClicked);

}

MainWindow::~MainWindow() {}

void MainWindow::onApplyButtonClicked() {

    int index = mainCombo->currentIndex();

    if (index == 0) {
        std::system("supergfxctl --mode Hybrid");
        QMessageBox::information(this, "Info", "Graphics mode changed to Hybrid. Required user action is: Logout required to complete mode change");
    }
    else {
        std::system("supergfxctl --mode Integrated");
        QMessageBox::information(this, "Info", "Graphics mode changed to Integrated. Required user action is: Logout required to complete mode change");
    }
}
