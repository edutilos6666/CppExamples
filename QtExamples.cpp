//
// Created by edutilos on 21.09.17.
//

#include "QtExamples.h"


void QtExamples::runQGridLayoutExample(int argc, char **argv) {
    QApplication app(argc, argv);
    QGridLayoutExample *window = new QGridLayoutExample("QtGridLayoutExample", 10, 10, -1, -1);
//    window->show();  //show() is not accessible within this context
    app.exec();
}




QGridLayoutExample::QGridLayoutExample(string title, int left ,int top, int width , int height) {
    this->title = title;
    this->left = left;
    this->top = top;
    this->width = width ;
    this->height = height;
    this->initGUI();
    this->show();
}

void QGridLayoutExample::initGUI() {
    this->setWindowTitle(QString::fromStdString(this->title));
    this->setGeometry(this->left, this->top, this->width , this->height);
    this->setWindowModality(Qt::WindowModal);
    this->addComponents();
    this->registerEvents();
}

void QGridLayoutExample::addComponents() {
    //mainLayout
    mainLayout = new QGridLayout();
    this->setLayout(mainLayout);
    //title
    lblTitle = new QLabel(QString::fromStdString(this->title));
    lblEmpty = new QLabel();
    mainLayout->addWidget(lblEmpty, 0, 0);
    mainLayout->addWidget(lblTitle, 0, 1);
    //id
    lblId = new QLabel("Id: ");
    editId = new QLineEdit();
    mainLayout->addWidget(lblId, 1 ,0);
    mainLayout->addWidget(editId, 1, 1);
    //name
    lblName = new QLabel("Name: ");
    editName = new QLineEdit();
    mainLayout->addWidget(lblName, 2, 0);
    mainLayout->addWidget(editName, 2, 1);
    //age
    lblAge = new QLabel("Age: ");
    editAge = new QLineEdit();
    mainLayout->addWidget(lblAge, 3, 0);
    mainLayout->addWidget(editAge, 3, 1);
    //wage
    lblWage = new QLabel("Wage: ");
    editWage = new QLineEdit();
    mainLayout->addWidget(lblWage, 4, 0);
    mainLayout->addWidget(editWage, 4, 1);
    //active
    lblActive = new QLabel("Active: ");
    editActive = new QLineEdit();
    mainLayout->addWidget(lblActive, 5, 0);
    mainLayout->addWidget(editActive, 5, 1);
    //buttons
    btnOk = new QPushButton("Ok");
    btnClear = new QPushButton("Clear");
    mainLayout->addWidget(btnOk, 6, 0);
    mainLayout->addWidget(btnClear, 6 , 1);
}

void QGridLayoutExample::registerEvents() {
    QObject::connect(btnOk, &QPushButton::clicked, [&]() {
        try {
            long id = editId->text().toLong();
            string name = editName->text().toStdString();
            int age = editAge->text().toInt();
            double wage = editWage->text().toDouble();
            string temp = editActive->text().toStdString();
            bool active = temp == "true";

            stringstream ss ;
            ss << "<<Infos>>" << endl;
            ss << "id = "<< id << endl;
            ss << "name = " << name << endl;
            ss << "age = " << age << endl;
            ss << "wage = " << wage << endl;
            ss  << "active = " <<  boolalpha <<  active << endl;
            QMessageBox::information(this, "<<Infos>>", QString::fromStdString(ss.str()));
        } catch(exception &ex) {
            QMessageBox::critical(this, "<<Error>>", QString::fromStdString(ex.what()));
        }
    });


    QObject::connect(btnClear, &QPushButton::clicked, [&](){
        editId->setText("");
        editName->setText("");
        editAge->setText("");
        editWage->setText("");
        editActive->setText("");
    });


}