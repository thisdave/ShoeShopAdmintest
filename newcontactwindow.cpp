#include "newcontactwindow.h"

NewContactWindow::NewContactWindow  (QWidget *parent) :
QDialog(parent)
     {

      this->setWindowTitle("Kontakt hozzaadasa"); 
  
      group                                 =     new QGroupBox();

       labelVasAdatok                     =     new QLabel("Adatok:");

      labelVasId                         =     new QLabel("Vasarlo azonosito:");
      labelVasNev                      =     new QLabel("Nev:");
      labelVasEmail                   =     new QLabel("email:");
      labelVasCipoMeret           =     new QLabel("cipomeret:");  
      labelVasDbSzam                      =     new QLabel("db_szam:");
      labelVasCipoModellNev       =      new QLabel("cipo_markamodell:");
     
      txtVasId                        =      new QLineEdit("");
      txtVasNev                    =      new QLineEdit("");
      txtVasEmail                 =      new QLineEdit("");
      txtVasCipoMeret        =       new QLineEdit("");
      txtVasCipoModellNev     =        new QLineEdit("");
      txtVasDbSzam                  =        new QLineEdit("");
      txtVasCipoMarka             =        new QLineEdit("");

       btnOk                          =         new QPushButton("ok");
       btnCancel                  =          new QPushButton("cancel");

      //1. Csinálok egy gridlayoutot
      //2.  hozzaadom a 4 vezerlot
      //3. Beállítom hogy a group QGroupBox objektum kezelője
      // a grid_layo legyen      

      grid_layo = new QGridLayout();


      grid_layo->addWidget(labelVasNev, 0 ,0);
      grid_layo->addWidget(txtVasNev, 0 ,1); 
      grid_layo->addWidget(labelVasId,1 ,0);
      grid_layo->addWidget(txtVasId ,1,1);
      grid_layo->addWidget(labelVasEmail, 2,0);
      grid_layo->addWidget(txtVasEmail, 2 ,1);
      grid_layo->addWidget(labelVasCipoMeret,3,0);
      grid_layo->addWidget(txtVasCipoMeret, 3 ,1);
      grid_layo->addWidget(labelVasCipoModellNev,4,0);
      grid_layo->addWidget(txtVasCipoModellNev,4,1);
      grid_layo->addWidget(labelVasDbSzam,5,0);
      grid_layo->addWidget(txtVasDbSzam,5,1);


      group->setLayout(grid_layo);

   

      btns_layo        =           new QHBoxLayout();
      btns_layo       ->          addStretch();
      btns_layo       ->           addWidget(btnOk);
      btns_layo       ->           addWidget(btnCancel);

      main_layo        =          new QVBoxLayout();
      this            ->      setLayout(main_layo);
      main_layo       ->      addWidget(group);
      main_layo       ->      addStretch();
      main_layo       ->      addLayout(btns_layo);

      


      
     connect( btnOk,SIGNAL(clicked()),this, SLOT( accept()    ));
     connect( btnCancel,SIGNAL(clicked()),this, SLOT(reject() ));
      
      
    };
QString NewContactWindow::getVasNev()               {  return txtVasNev->text(); }
QString NewContactWindow::getVasId()                {  return txtVasId->text();        }
QString NewContactWindow::getVasEmail()           {  return txtVasEmail->text();    }
QString NewContactWindow::getVasCipoMeret()     {  return txtVasCipoMeret->text();  }
QString NewContactWindow::getVasModellNev()     {  return txtVasCipoMarka->text();      }
QString NewContactWindow::getVasDbSzam()        {  return txtVasDbSzam->text();      }
