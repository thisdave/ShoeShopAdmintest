#ifndef NEWCONTACTWINDOW_H
#define NEWCONTACTWINDOW_H


#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton> 
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDialog>
class NewContactWindow : public QDialog  
{
   Q_OBJECT
   private:

     QLabel * labelVasAdatok;

     QGroupBox *group;
     QLabel * labelVasId;
     QLabel * labelVasNev;
     QLabel * labelVasEmail;
     QLabel * labelVasCipoMeret;
     QLabel * labelVasCipoMarka;
     QLabel * labelVasDbSzam;
     QLabel * labelVasCipoModellNev;


//Epito elemek
     QLineEdit *txtVasId;
     QLineEdit *txtVasNev;
     QLineEdit *txtVasEmail;
     QLineEdit *txtVasCipoMeret;
     QLineEdit *txtVasDbSzam;
     QLineEdit *txtVasCipoModellNev;
     QLineEdit *txtVasCipoMarka;
     QPushButton *btnOk;
     QPushButton *btnCancel;

//Elrendezok
     QGridLayout *grid_layo; //racs layout
     QVBoxLayout *main_layo; //ablak layout
     QHBoxLayout *btns_layo; //gombok layoutja


//Adat tagok, amik a tenyleges informaciot tartalmazzak:
     QString *VasID;
     QString *VasNev;
     QString *VasEmailcim;
     QString *VasCipoMeret;
     QString *VasModellNev;
     QString *VasDbSzam;

   public:

     NewContactWindow(QWidget * parent=0);
  
  QString getVasId();
  QString getVasNev();
  QString getVasModellNev();
  QString getVasEmail();
  QString getVasCipoMeret();
  QString getVasDbSzam();
  signals:
  public slots:

  
};

#endif
