#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Window settings
    setWindowTitle("GPUswitcher");
    setWindowIcon(QIcon(":/icon.png"));
    setFixedSize(300, 300);
    // Create Pixmap from images
    QPixmap hybridImage(":/Hybrid.png");
    QPixmap integratedImage(":/Integrated.png");

    // Create central Widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create main Layout for images and buttons
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    imageStack = new QStackedWidget;
    // Create labels for store images
    QLabel *image1 = new QLabel();
    QLabel *image2 = new QLabel();
    // Create grid Laout for combo box and button
    QGridLayout *joinedLayout = new QGridLayout();

    // Set Pixmap for label and set up alignment
    image1->setPixmap(hybridImage.scaled(250, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image1->setAlignment(Qt::AlignCenter);
    image2->setPixmap(integratedImage.scaled(250, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image2->setAlignment(Qt::AlignCenter);
    // Add our images to widget stack
    imageStack->addWidget(image1);
    imageStack->addWidget(image2);

    // Init combo box and set up
    mainCombo = new QComboBox();
    mainCombo->addItems({"Hybrid mode", "Integrated only"});
    mainCombo->setCurrentIndex(0);

    // Create button and set up text and size
    QPushButton *ApplyButton = new QPushButton();
    ApplyButton->setText("Apply");
    ApplyButton->setFixedSize(50, 30);

    // Add combo box and button to grid layout, after add stack to main Layout with grid layout
    joinedLayout->addWidget(mainCombo, 0, 0);
    joinedLayout->addWidget(ApplyButton, 0, 1);
    mainLayout->addWidget(imageStack);
    mainLayout->addLayout(joinedLayout);

    //Connect Button and changing index in combo box
    connect(ApplyButton,&QPushButton::clicked, this, &MainWindow::onApplyButtonClicked);
    connect(mainCombo, &QComboBox::currentIndexChanged, this, [=](int index){ imageStack->setCurrentIndex(index); });

}

MainWindow::~MainWindow() {}

void MainWindow::onApplyButtonClicked() {

    // Variable to store index
    int index = mainCombo->currentIndex();

    // Check index and change modes with display Message Boxes
    if (index == 0) {
        std::system("supergfxctl --mode Hybrid");
        QMessageBox::information(this, "Info", "Graphics mode changed to Hybrid. Required user action is: Logout required to complete mode change");
    }
    else {
        std::system("supergfxctl --mode Integrated");
        QMessageBox::information(this, "Info", "Graphics mode changed to Integrated. Required user action is: Logout required to complete mode change");
    }
}
