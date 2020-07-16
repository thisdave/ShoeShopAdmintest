#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>



class SearchDlg : public QDialog
{
    Q_OBJECT

   public:
     explicit SearchDlg(QWidget *parent=0);

   signals:
     void searchInvoked(QString expression);

   public slots:
    void search();

   protected:
   QHBoxLayout    *layout;
   QLineEdit      *txtExpression;
   QPushButton    *btnSearch;
};

#endif 
