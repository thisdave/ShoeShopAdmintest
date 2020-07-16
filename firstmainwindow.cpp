#include "firstmainwindow.h"
#include "firstmainwindow2_kesz.cpp"

 FirstMainWindow::FirstMainWindow (QWidget *parent):
                           QMainWindow(parent)
{
   /*table2_cipoarak->horizontalHeader () -> setResizeMode (QHeaderView :: Stretch);
    table2_cipoarak->verticalHeader () -> setResizeMode (QHeaderView :: Stretch);*/
   
   this->resize(1024, 768);
   this->setWindowTitle("FirstMainWindow");
  
//Menuk megadasa: Start:
   fileMenu=this->menuBar()->addMenu(tr("&fajl"));
   tablaMenu=this->menuBar()->addMenu(tr("&tablat_megjelenit")) ;
   rendezesMenu=this->menuBar()->addMenu(tr("&rendezes"));
//Menuk megadasa: vege:

//A mar elkeszitett actionok megadasa
 menuk_Actionjeinek_elkeszitese();

//Tablak elkeszitese es feltoltese
tablakat_keszit_feltolt();
//Tablak elkeszitese es feltoltese VEGE:
};
 

// RENDEZES: RAKTARKESZLET  KEZD:
/*void FirstMainWindow::raktarkeszletTabla_rendezes_cipoId_szerint(){
   table1_main->sortByColumn(0,Qt::AscendingOrder);
};*/

// RENDEZES: RAKTARKESZLET  VEGE:




// BEOLVASAS CIPOARAKAT 01_cipoarak.txt bol
int FirstMainWindow::cipoarakTablaBetoltesFajlbol()
{ 
   qDebug()<<"setRowCount(1) parancs elott vagyok program)" << "\n";

   table2_cipoarak->setRowCount(	0);
  qDebug()<<"setRowCount(1) parancsig nem szallt el a program)" << "\n";
   table2_cipoarak-> setColumnCount(3);

   int vanhiba=0;
   std::ifstream file2_cipoarak;

    //Ez az objektum jelenti a fajlt 

     file2_cipoarak.open("Data//01_cipoarak.txt", std::ios_base::in) ;
    if( file2_cipoarak.fail( ))
                        {vanhiba=1; return -1;
                          qDebug() <<"FirstMainWindow::cipoarakTablaBetoltesFajlbol a 01_cipoarak.txt fajl megnyitasa sikertelen\n";
                          }
     else {qDebug() <<"FirstMainWindow::cipoarakTablaBetoltesFajlbol\n"  << "A 01_cipoarak.txt fajl megnyitasa sikeres\n";}
 
 
   //eddig eljut program futasa
    std::string line1("abc_string proba\n");
    char  *string_c_chars  = new char[1000];
     strcpy(string_c_chars,line1.c_str());
  
     //qDebug() << "kiirando_szoveg:"<<  string_c_chars <<"\n";

    line1="";

   if(vanhiba ==1) {return -1;}
    

      //beolvasok 3 sort a fajlbol:

            if(!std::getline(file2_cipoarak, line1) )   
                   {  qDebug()<< "fuggveny: cipoArakat fajlbol betolt: 01_cipoarak.txt teljes sor olvasasi hiba" <<"\n";  
                                 vanhiba=1;   return -2 ;  }

          strcpy(string_c_chars,line1.c_str()); 

         if(file2_cipoarak.eof())  { qDebug()<< "A fajl olvasasnal a 01_cipoarak.txt fajlnak a vegere  ertunk" <<"\n"; 
                                                       vanhiba=0; return 2;}                      
           qDebug()<<"1. sora a kommenteknek: " <<string_c_chars <<"\n" ;

        
   
          if(! std::getline(file2_cipoarak, line1)) 
                                                     {  qDebug()<< "cipoArakat fajlbol betolt: teljes sor olvasasi hiba" <<"\n";  
                                                        vanhiba=1;   return -2 ;  }
         strcpy(string_c_chars, line1.c_str());   

          if(file2_cipoarak.eof())  
                                                  { qDebug()<< "A fajl olvasasnal a 01_cipoarak.txt fajlnak a vegere ertunk" <<"\n"; 
                                                       vanhiba=0; return -3 ;}                      
           qDebug()<<"2. sora a kommenteknek : " <<string_c_chars <<"\n" ;

      
;
      
           if( !std::getline(file2_cipoarak, line1))  
                         {  qDebug()<< "fuggveny: cipoArakat fajlbol betolt: 01_cipoarak.txt teljes sor olvasasi hiba" <<"\n";  
                             vanhiba=1;   return -2 ;  }
          strcpy(string_c_chars,line1.c_str());  
  
          if(file2_cipoarak.eof())  { qDebug()<< "A fajl olvasasnal a 01_cipoarak.txt fajlnak a vegere ertunk" <<"\n"; 
                                                       vanhiba=0;  return -3;  }                      
           qDebug()<<"3. sora a kommenteknek: " <<string_c_chars <<"\n" ;


           if(  !std::getline(file2_cipoarak, line1))  {  qDebug()<< "fuggveny: cipoArakat fajlbol betolt: 01_cipoarak.txt teljes sor olvasasi hiba" <<"\n";  
                                                        vanhiba=1;   return -2 ;  }
strcpy(string_c_chars,line1.c_str());   
          if(file2_cipoarak.eof())  { qDebug()<< "A fajl olvasasnal a 01_cipoarak.txt fajlnak a vegere ertunk"  <<"\n"; 
                                                       vanhiba=0; return -3 ;}                      
           qDebug()<<"4. sora a kommenteknek : " <<string_c_chars <<"\n" ;


/*itt kezdodik a tenyleges adatbeolvasas programresz*/

          std::string cipomodellId_tmp="";
          std::string cipomodellNev_tmp="";
          std::string cipomodellAr_tmp= "";
    
         const std::string delimiter=" "; 
        
        QString cipomodellId2="";
        QString cipomodellNev2="";
        QString cipomodellAr2="";


      //itt meg nem tudom hany elemet irok hozza a table hoz,
      

  //Ez itt a beolvaso ciklusom:
   //Ez itt a beolvaso ciklusom eleje:
      int sorokszama=0;
       int adattagok_egysorban_max=4;
         int adattagok_szama_aktualis_sorban=0;

  while (1)
            {  
          qDebug()<<"A program elkezdi vegrehajtani a while ciklust\n";
          qDebug()  << "Program belepett a while ciklusba\n" <<"\n" ;
         adattagok_szama_aktualis_sorban=0;
     
          std::getline(file2_cipoarak, line1);
          if(file2_cipoarak.eof()) { qDebug()  << "A fajl vegere ertunk" <<"\n"; break;  ;}
          qDebug()  << "while ciklusban atleptem az endof_file ellenorzes-en" <<"\n" ;
          strcpy(string_c_chars,line1.c_str());           

          if(file2_cipoarak.fail())  {  vanhiba=1;  qDebug()<< "hiba tortent a fajl egy soranak olvasasakor:\n" <<sorokszama<<"\n"; 
                                                        return -3 ;  }
          if(file2_cipoarak.eof())  { 
                                                   qDebug() << "az adott file leiroban a fajl vegere ertunk" << sorokszama<<"\n";
                                                    break ;} 

        qDebug() << "A fajl n dik valos adatsora sikeresen beolvasva" << string_c_chars<<"\n"; 
           
        //atmeneti stringek a beolvasashoz
   
         //sztringekbe olvasás a sorbol
          qDebug() << "beolvasott sor szetbontasa most kezdodik ennyiedik sor:" << sorokszama << "\n";
 
         //adatsorbol kivagom az elso adatot
          cipomodellId_tmp=line1.substr(0,line1.find(delimiter));
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
         //Atmasolom a pufferbe a stringet, es kiiratom;
          strcpy(string_c_chars, cipomodellId_tmp.c_str());  
          qDebug() << "Cipoarak.txt n d ik sor   1. adat a sorban:  Cipomodell ID:" <<  string_c_chars << "\n" ;

            //adatsorbol kivagom a masodik adatot
          cipomodellNev_tmp=line1.substr(0,(line1.find(delimiter)));
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
          strcpy(string_c_chars, cipomodellNev_tmp.c_str()); 
          qDebug() <<"Cipoarak.txt n d ik sor      2. adat a sorban: Cipomodell Nev:" <<  string_c_chars <<"\n";  

         //adatsorbol kimásolom a harmadik adatot:
          cipomodellAr_tmp=line1.substr(0,(line1.find(delimiter)));
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
         //Atmasolom a pufferbe a stringet, hogy ne a stackre mutasson a line c_str(),;  
          strcpy(string_c_chars,           cipomodellAr_tmp.c_str()) ; 
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
          qDebug() <<"Cipoarak.txt n d ik sor      3. adat a sorban: Cipomodell_ar"<<  string_c_chars << "\n" ;
 

         qDebug() << " QStringek  feltoltese meg nem pointerrel kezdodik:\n" ;
          //atmasolom a Qstringekbe az ertekeket:
          cipomodellId2 = QString::fromStdString(cipomodellId_tmp);
          qDebug() << "QStringek ertekadasának eredménye:  cipomodellId2: " << cipomodellId2 << "\n";
          cipomodellNev2   =  QString::fromStdString(cipomodellNev_tmp);
          qDebug() << "QStringek ertekadasának eredménye:  cipomodellNev2: " << cipomodellNev2 << "\n";

          cipomodellAr2    =  QString::fromStdString(cipomodellAr_tmp);
          qDebug() << " QStringek ertekadasának eredménye:     CipomodellAr" << cipomodellAr2 << "\n";
        
          qDebug() << " A cipo QStringek ertekadasa nem fagyasztotta ki a programot\n" ;
         //nem kell c tipusu stringbe konvertalni
         
       
           sorokszama=0;
            adatok_szama_aktualis_sorban=0;
          //ez mondja meg hany

           int rownum = table2_cipoarak->rowCount() ; // current sor szama   
           table2_cipoarak->insertRow(rownum);     

 //table_cipoarak feltoltese KEZD:
          switch ( adattagok_oszlopszama_aktualis_sorban){
                case 0:   
                           {QTableWidgetItem * newCipomodellId2Item=new QTableWidgetItem(cipomodellId2);
			      table2_cipoarak->setItem(table2_cipoarak->rowCount()-1,0,newCipomodellId2Item);  
			     
                            qDebug() << "megtorent a QWidget n. soranak elso oszlopanak feltoltese" << "\n";   
			      adatok_szama_aktualis_sorban=1;}
                             break;
                case 1: 
                        {QTableWidgetItem * newCipomodellNev2Item=new QTableWidgetItem(cipomodellNev2); 
			    table2_cipoarak->setItem(table2_cipoarak->rowCount()-1,1,newCipomodellNev2Item);

                           qDebug() << "megtorent a QWidget n. soranak masodik oszlopanak feltoltese" << "\n";  
      
		          adatok_szama_aktualis_sorban=2;}
                          break;
              case 2:
			  { QTableWidgetItem * newCipomodellAr2Item=new QTableWidgetItem(cipomodellAr2);
			   table2_cipoarak->setItem(table2_cipoarak->rowCount()-1,2,newCipomodellAr2Item);
			   qDebug() << "megtorent a QWidget n. soranak harmadik oszlopanak feltoltese" << "\n";
			   adatok_szama_aktualis_sorban=3;}
                         break;
           default: {}
                        break;
              }
          //table_cipoarak feltoltese VEGE:


         qDebug()<<" \n Beolvasott sorok szama: :"<<"\n"<< sorokszama <<"\n";

         if( adattagok_szama_aktualis_sorban==3)
                                {sorokszama++;
                                  adatok_szama_aktualis_sorban=0;}


        }
// Beolvaso_Ciklus_vege:
  
 if (vanhiba <= 0)        {file2_cipoarak.close() ; return -1;} 
//Ha eredmenyes volt a kiiras, lezarom a fajlt es adjon ki egyet

 if (vanhiba >0)              {    file2_cipoarak.close(); return 1;}


  return 1;}

int FirstMainWindow::cipoarakTablaKiirasFajlba(){
   qDebug()  << " CipoarakTable-t kiirom cipoarak.txt fajlba\n" <<"\n";
   std::fstream file_cipoarak_kim;//Ez az objektum jelenti a fajlt

   file_cipoarak_kim.open("Data//01_cipoarak.txt");  //alapbol out
       

   int currentRowsNumber=table2_cipoarak->rowCount();
   int i;
   for(i=0;i<currentRowsNumber;i++){
      file_cipoarak_kim << (table2_cipoarak->itemAt(i,0)->text()).toStdString();
       if(!file_cipoarak_kim.is_open()) return -1;

        file_cipoarak_kim << " ";
        file_cipoarak_kim << (table2_cipoarak->itemAt(i,1)->text()).toStdString();
       if(!file_cipoarak_kim.is_open()) return -1;
        file_cipoarak_kim << " ";
        file_cipoarak_kim << (table2_cipoarak->itemAt(i,2)->text().toStdString());
       if(! file_cipoarak_kim.is_open()) return -1;
       file_cipoarak_kim << "\n";
       if(! file_cipoarak_kim.is_open()){ break ;}
       currentRowsNumber++;
   }

  //irasi puffer kiuritese:
   file_cipoarak_kim.flush() ;
  //fajl lezarasa:
   file_cipoarak_kim.close();
   return 0;
};



//raktarkeszlet beolvasasa fajlbol KEZDET:
/*int FirstMainWindow::raktarkeszletTablaBetolteseFajlbol(){
return 0;
};*/
//raktarkeszlet beolvasasa fajlbol VEGE:

/*//raktarkeszlet tabla kiirasa KEZDET:
int FirstMainWindow::raktarkeszletTablaKiirasaFajlba(){
return 0;
};
//raktarkeszlet tabla kiirasa VEGE*/





//felkesz függvények kezd:


//felkesz fuggvenyek vege:

/*int  FirstMainWindow::mainTablaBetoltesFajlbol(){
return 1;
};*/


/*int FirstMainWindow::mainTablaKiirasFajlba(){
  return 1;
};*/











void FirstMainWindow::updateStatusText(){
    QList<QTableWidgetItem*> selectedItems = table1_main -> selectedItems();

    if(selectedItems.length()  > 0) 
     {
        this->statusBar()->showMessage(        "Name: " %
         table1_main->item(selectedItems.first()->row(), 0)->text()      );
     
     }
};

void FirstMainWindow::closeEvent(QCloseEvent* event)
{
     msg.setWindowTitle("Kilepes");
     msg.setText("Tenyleg Kilepes?");
     msg.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

    if(msg.exec()==QMessageBox::Yes)
              {event->accept();}
    else event->ignore();
    return;
};

