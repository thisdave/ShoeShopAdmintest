#ifndef FIRSTMAINWINDOW_H
#define FIRSTMAINWINDOW_H

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QStatusBar>
#include  <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QString>
#include <string>
#include <QStringBuilder>
#include <QStringList>
#include <QTableWidget>
#include <QtDebug>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <QMessageBox>
#include <QAction>
#include "newcontactwindow.h"
#include "searchdlg.h"

class FirstMainWindow : public QMainWindow{
 Q_OBJECT
//private adattagok
   //rövid műveletek, gyorsbillentyűs
    QAction *exitAction;
    QAction *newContactAction;
    QAction * nyers_adatsorokBeolvasasFajlbol_Action;
   
    QAction *adatok_make_main_tableBfrom_MainTable_Action;

    QAction * cipoarakTablaBetoltesFajlbol_Action;//fv nev pipa
    QAction * cipoarakTablaKiirasFajlba_Action;// fv nev pipa
    QAction * mainTablaBetoltesFajlbol_Action;
    QAction * mainTablaKiirasaFajlba_Action;
    QAction * raktarkeszletTablaKiirasFajlba_Action;
    QAction * raktarkeszletTablaBetoltesFajlbol_Action;

    QAction * osszes_tabla_elrejtese_Action;
    QAction * showSearchAction;
    QAction * cipomDiagAction;

    QAction * mainTablaMutat_Action;
    QAction * cipoarakTablaMutat_Action;
    QAction * raktarkeszletTablaMutat_Action;
 


    QAction *  mainTabla_rendezes_vasNev_sz_Action;
    QAction *  mainTabla_rendezes_vasEmailcim_sz_Action;
    QAction *  mainTabla_rendezes_cipoMeret_sz_Action;
    QAction *  mainTabla_rendezes_cipoModell_sz_Action ;



    QMenu * fileMenu;
    QMenu * rendezesMenu;
    QMenu * tablaMenu;
    QMessageBox msg;

    QTableWidget * table1_main;
    QTableWidget * table2_cipoarak;
    QTableWidget * table3_raktarkeszlet;
 public:
 explicit FirstMainWindow (QWidget * parent = nullptr);
 
 signals: 
 public slots:






    //Rendezo_fv.ek. keszek

    //void mainTabla_rendezes_vasNev_sz();
    //void mainTabla_rendezes_vasEmailcim_sz();
   // void mainTabla_rendezes_cipoModellId_sz();
   // void mainTabla_rendezes_cipoMeret_sz();


    //Rendezes Table Cipoarak KEZD:

    void cipoarakTabla_rendezes_cipoModellId_szerint();
    void cipoarakTabla_rendezes_cipoModellNev_szerint();
    void cipoarakTabla_rendezes_cipoAr_szerint();
    //Rendezes Cipoarak VEGE:

    //Rendezes Table raktarkeszlet KEZD:
     //void raktarkeszletTabla_rendezes_cipoId_szerint();
    //Rendezes Table raktarkeszlet VEGE:

   
    void osszes_tabla_elrejtese();
    //void tablat_valts_table1MainTabla();//Cipoarak tablat mutat a, tobbit elrejti
   void tablat_valts_table2CipoarakTabla();//Raktarkeszlet tablat mutatja, tobbit elrejti
   // void tablat_valts_table3RaktarkeszletTabla();//Main tablat mutatja, tobbit elrejti
  
   //Tablak elkeszitese es feltoltese
   void tablakat_keszit_feltolt();


    //A 'cipoarak.txt'-jet ugyanugy visszairom mindig
    int cipoarakTablaBetoltesFajlbol(); 
    //'01_Cipoarak.txt 'beolvassa fajlbol es betolti a table_CipoArak tablaba
    int cipoarakTablaKiirasFajlba() ;
    // a table1_CipoArak tabla tartalmat kiirja a '01_cipoarak.txt'tablaba

    // int mainTablaBetoltesFajlbol();
    // a main tabla tartalmat kiirja a '02_raktarkeszlet.txt' tablaba
  //  int mainTablaKiirasFajlba();
    //a mainTabla tartalmat kiirja a  01_data.txt  tablaba

    //raktarkeszlet betoltese/kiirasa
   // int raktarkeszletTablaBetolteseFajlbol();
   // int raktarkeszletTablaKiirasaFajlba();




    //void addNewContact();
    void updateStatusText();
    //void showSearch();

public:
    void closeEvent(QCloseEvent* event); 
    void menuk_Actionjeinek_elkeszitese();


     //ezt majd a konstruktorban letrehozom, adatbetolt tolti fel
    SearchDlg * searchDialog1;
    int cipom_elemszam;
    friend class NewContactWindow;
};
#endif
