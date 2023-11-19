#include "mainwindow.h"

#include <QApplication>

#include "main1.c"
#include "util.c"
#include "input.c"
#include "output.c"
#include "mrna.c"
#include "ribosome.c"
#include "operation.c"
#include "decimaltype.c"
#include "binarytype.c"
#include "QFile"
#include "QDir"
#include "QString"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*For printing Output we assume these file pointers to create the files and write on them. These pointers repreent the file mRNA, mutation, and protein chain respectively */
FILE *fpmrna;
FILE *fpmuta;
FILE *fpp;

/* File pointer for soting the input as a output file */
FILE *fpn;

/* File pointer of the output file */
FILE *fpnop;

/* File pointers to store perfromance parameters Energy and Time */
FILE *fpdbio;
FILE *fpddig;

/* File pointers to store perfromance parameters Energy and Time */
FILE *fpengy;
FILE *fptime;


/*For taking the Inputs we assume these file pointers to open the existing files*/

FILE *fip1; 		/*File pointer for first input number*/
FILE *fip2; 		/*File pointer for first input number*/

FILE *fom;		/*File pointer for mode of operation*/

FILE *fon;		/*File pointer for name of operation*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.output_inactive_state = true;
    w.on_actionWelcome_triggered();
    w.show();
    a.exec();

    // Output Files Path
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";
    //Input Files Path
    QString inPath = QDir::homePath()+"/Ribosomal_Simulator/Input";

   QString operation =  inPath+"/operation.txt";
   QString mode =  inPath+"/mode.txt";
   QString number1 =  inPath+"/number1.txt";
   QString number2 =  inPath+"/number2.txt";

   std::string str = operation.toStdString();
   const char* on = str.c_str();

   std::string str1 = mode.toStdString();
   const char* om = str1.c_str();

   std::string str2 = number1.toStdString();
   const char* ip1 = str2.c_str();

   std::string str3 = number2.toStdString();
   const char* ip2 = str3.c_str();

   QString mrna =  outPath+"/mrna.txt";
   QString mutation =  outPath+"/mutation.txt";
   QString protein =  outPath+"/protein.txt";
   QString digitalIP =  outPath+"/digitalIP.txt";
   QString digitalOP =  outPath+"/digitalOP.txt";
   QString biodetails =  outPath+"/biodetails.txt";
   QString digdetails =  outPath+"/digdetails.txt";
   QString energy =  outPath+"/energy.txt";
   QString time =  outPath+"/time.txt";

   std::string str4 = mrna.toStdString();
   const char* pmrna = str4.c_str();

   std::string str5 = mutation.toStdString();
   const char* pmuta = str5.c_str();

   std::string str6 = protein.toStdString();
   const char* pp = str6.c_str();

   std::string str7 = digitalIP.toStdString();
   const char* pn = str7.c_str();

   std::string str8 = digitalOP.toStdString();
   const char* pnop = str8.c_str();

   std::string str9 = biodetails.toStdString();
   const char* pdbio = str9.c_str();

   std::string str10 = digdetails.toStdString();
   const char* pddig = str10.c_str();

   std::string str11 = energy.toStdString();
   const char* pengy = str11.c_str();

   std::string str12 = time.toStdString();
   const char* ptime = str12.c_str();

    if(w.output_inactive_state == false){
    fip1 = fopen(ip1, "r");
    fip2 = fopen(ip2, "r");
    fom = fopen(om, "r");
    fon = fopen(on,"r");

    fpmrna = fopen(pmrna,"w");
    fpmuta = fopen(pmuta,"w");
    fpp = fopen(pp,"w");

    fpn = fopen(pn,"w");
    fpnop = fopen(pnop,"w");

    fpdbio = fopen(pdbio,"w");
    fpddig = fopen(pddig,"w");

    fpengy = fopen(pengy,"w");
    fptime = fopen(ptime,"w");

       main1();

       fclose(fpn);
       fclose(fpnop);

       fclose(fpmrna);
       fclose(fpmuta);
       fclose(fpp);

       fclose(fpengy);
       fclose(fptime);

       fclose(fpdbio);
       fclose(fpddig);

       fclose(fip1);
       fclose(fip2);
       fclose(fom);
       fclose(fon);


    MainWindow x;
    x.output_inactive_state = false;
    x.on_actionOutput_triggered();
    x.show();
    x.outputProgress();
    return a.exec();}
}
