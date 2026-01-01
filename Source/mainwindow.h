#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    // Function to process button signal
    void onApplyButtonClicked();
private:
    QComboBox *mainCombo;
    QStackedWidget *imageStack;
};
#endif // MAINWINDOW_H
