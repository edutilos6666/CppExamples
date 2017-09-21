//
// Created by edutilos on 21.09.17.
//
//sudo apt install qtdeclarative5-dev


#ifndef CPPEXAMPLES_QTEXAMPLES_H
#define CPPEXAMPLES_QTEXAMPLES_H

#include <iostream>
#include <sstream>
#include <string>


#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QGridLayout>


using namespace std;

class QGridLayoutExample;
class QtExamples {
public:
  void runQGridLayoutExample(int argc, char** argv);
};


class QGridLayoutExample: QDialog  {
private:
    string title;
    int left , top, width , height;
    //components
    QGridLayout *mainLayout;
    //title
    QLabel *lblTitle, *lblEmpty;
    //id
    QLabel *lblId ;
    QLineEdit *editId;
    //name
    QLabel *lblName;
    QLineEdit *editName;
    //age
    QLabel *lblAge;
    QLineEdit *editAge;
    //wage
    QLabel *lblWage;
    QLineEdit *editWage;
    //active
    QLabel *lblActive;
    QLineEdit *editActive;
    //buttons
    QPushButton *btnOk;
    QPushButton *btnClear;


public:
    QGridLayoutExample(string title, int left ,int top, int width , int height);
    void initGUI();
    void addComponents();
    void registerEvents();
};



#endif //CPPEXAMPLES_QTEXAMPLES_H
